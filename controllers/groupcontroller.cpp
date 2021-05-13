#include "groupcontroller.h"
#include "group.h"
#include "user.h"
#include "groupuser.h"
#include <tsqlquery.h>


void GroupController::index()
{
    TSqlQuery query;
    
    query.prepare("SELECT g.id, g.name, COUNT(gu.user_id), gu.role, gu.id FROM group_user gu LEFT JOIN groups g ON g.id = gu.group_id WHERE gu.user_id = :id GROUP BY g.id ORDER BY gu.role DESC");
    query.bind(":id", User::getByIdentityKey(this->identityKeyOfLoginUser()).id());
    query.exec();

    QVariantMap inserter;
    QList<QVariantMap> groupList;
    
    while (query.next()) {
        int id = query.value(0).toInt();
        QString name = query.value(1).toString();
        int count = query.value(2).toInt();
        int role = query.value(3).toInt();
        int guid = query.value(4).toInt();

        inserter["id"] = QVariant(id);
        inserter["name"] = QVariant(name);
        inserter["count"] = QVariant(count);
        inserter["role"] = QVariant(role);
        inserter["guid"] = QVariant(guid);

        groupList.push_back(inserter);
    }

    texport(groupList);
    render("index", "dashboard");
}

void GroupController::join() {
    int id = User::getByIdentityKey(this->identityKeyOfLoginUser()).id();
    QString invite = httpRequest().formItemValue("invite");
    
    TSqlQuery query;

    query.prepare("SELECT COUNT(g.id) FROM group_user gu LEFT JOIN groups g ON g.id = gu.group_id WHERE g.invite = :invite AND gu.user_id = :id LIMIT 1");
    query.bindValue(":invite", QVariant(invite));
    query.bind(":id", id);
    query.exec();

    int counter = 0;
    while (query.next()) {
        counter = query.value(0).toInt();
    }

    if (!counter) {
        query.prepare("SELECT id FROM groups WHERE invite = :invite LIMIT 1");
        query.bindValue(":invite", QVariant(invite));
        query.exec();

        int gId = 0;
        while (query.next()) {
            gId = query.value(0).toInt();
        }

        QVariantMap inserter;
        inserter["userId"] = QVariant(id);
        inserter["role"] = QVariant(1);
        inserter["groupId"] = QVariant(gId);

        GroupUser::create(inserter);
    }

    redirect(urla("index"));
}

void GroupController::show(const QString &id)
{
    auto group = Group::get(id.toInt());
    texport(group);
    render("show", "dashboard");
}

void GroupController::create()
{
    switch (httpRequest().method()) {
    case Tf::Get:
        render("create", "dashboard");
        break;

    case Tf::Post: {
        int id = User::getByIdentityKey(this->identityKeyOfLoginUser()).id();
        auto group = httpRequest().formItems("group");
        group["userId"] = QVariant(id);

        auto model = Group::create(group);
        if (!model.isNull()) {
            QVariantMap group_user;

            group_user["userId"] = QVariant(id);
            group_user["groupId"] = QVariant(model.id());
            group_user["role"] = QVariant(2);

            auto insert = GroupUser::create(group_user);

            QString notice = "Created successfully.";
            tflash(notice);
            redirect(urla("show", model.id()));
        } else {
            QString error = "Failed to create.";
            texport(error);
            texport(group);
            render("create", "dashboard");
        }
        break; }

    default:
        renderErrorResponse(Tf::NotFound);
        break;
    }
}

void GroupController::leave(const QString &id) {
    if (httpRequest().method() != Tf::Post) {
        renderErrorResponse(Tf::NotFound);
        return;
    }

    auto group = GroupUser::get(id.toInt());
    group.remove();
    redirect(urla("index"));
}

void GroupController::save(const QString &id)
{
    switch (httpRequest().method()) {
    case Tf::Get: {
        auto model = Group::get(id.toInt());
        
        TSqlQuery query;
        query.prepare("SELECT u.name, u.username, gu.role, gu.id FROM user u JOIN group_user gu ON u.id = gu.user_id WHERE gu.group_id = :id ORDER BY gu.role DESC");
        query.bind(":id", model.id());
        query.exec();

        QVariantMap inserter;
        QList<QVariantMap> memberList;

        while (query.next()) {
            QString name = query.value(0).toString();
            QString username = query.value(1).toString();
            int role = query.value(2).toInt();
            int uid = query.value(3).toInt();

            inserter["uid"] = QVariant(uid);
            inserter["name"] = QVariant(name);
            inserter["role"] = QVariant(role);
            inserter["username"] = QVariant(username);

            memberList.push_back(inserter);
        }

        if (!model.isNull()) {
            auto group = model.toVariantMap();
            texport(memberList);
            texport(group);
            render("save", "dashboard");
        }
        break; }

    case Tf::Post: {
        QString error;
        auto model = Group::get(id.toInt());
        
        if (model.isNull()) {
            error = "Original data not found. It may have been updated/removed by another transaction.";
            tflash(error);
            redirect(urla("save", id));
            break;
        }

        auto group = httpRequest().formItems("group");
        model.setProperties(group);

        if (model.save()) {
            QString notice = "Updated successfully.";
            tflash(notice);
            redirect(urla("show", model.id()));
        } else {
            error = "Failed to update.";
            texport(error);
            texport(group);
            render("save", "dashboard");
        }
        break; }

    default:
        renderErrorResponse(Tf::NotFound);
        break;
    }
}

void GroupController::kick(const QString &id, const QString &group_id) {
    if (httpRequest().method() != Tf::Post) {
        renderErrorResponse(Tf::NotFound);
        return;
    }

    auto group = GroupUser::get(id.toInt());
    group.remove();
    redirect(urla("save", group_id.toInt()));
}

void GroupController::remove(const QString &id)
{
    if (httpRequest().method() != Tf::Post) {
        renderErrorResponse(Tf::NotFound);
        return;
    }

    auto group = Group::get(id.toInt());
    group.remove();
    redirect(urla("index"));
}


// Don't remove below this line
T_DEFINE_CONTROLLER(GroupController)
