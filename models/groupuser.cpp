#include <TreeFrogModel>
#include "groupuser.h"
#include "sqlobjects/groupuserobject.h"

GroupUser::GroupUser() :
    TAbstractModel(),
    d(new GroupUserObject())
{
    // set the initial parameters
}

GroupUser::GroupUser(const GroupUser &other) :
    TAbstractModel(),
    d(other.d)
{ }

GroupUser::GroupUser(const GroupUserObject &object) :
    TAbstractModel(),
    d(new GroupUserObject(object))
{ }

GroupUser::~GroupUser()
{
    // If the reference count becomes 0,
    // the shared data object 'GroupUserObject' is deleted.
}

int GroupUser::id() const
{
    return d->id;
}

int GroupUser::userId() const
{
    return d->user_id;
}

void GroupUser::setUserId(int userId)
{
    d->user_id = userId;
}

int GroupUser::groupId() const
{
    return d->group_id;
}

void GroupUser::setGroupId(int groupId)
{
    d->group_id = groupId;
}

int GroupUser::role() const
{
    return d->role;
}

void GroupUser::setRole(int role)
{
    d->role = role;
}

GroupUser &GroupUser::operator=(const GroupUser &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

GroupUser GroupUser::create(int userId, int groupId, int role)
{
    GroupUserObject obj;
    obj.user_id = userId;
    obj.group_id = groupId;
    obj.role = role;
    if (!obj.create()) {
        return GroupUser();
    }
    return GroupUser(obj);
}

GroupUser GroupUser::create(const QVariantMap &values)
{
    GroupUser model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

GroupUser GroupUser::get(int id)
{
    TSqlORMapper<GroupUserObject> mapper;
    return GroupUser(mapper.findByPrimaryKey(id));
}

int GroupUser::count()
{
    TSqlORMapper<GroupUserObject> mapper;
    return mapper.findCount();
}

QList<GroupUser> GroupUser::getAll()
{
    return tfGetModelListByCriteria<GroupUser, GroupUserObject>(TCriteria());
}

QJsonArray GroupUser::getAllJson()
{
    QJsonArray array;
    TSqlORMapper<GroupUserObject> mapper;

    if (mapper.find() > 0) {
        for (TSqlORMapperIterator<GroupUserObject> i(mapper); i.hasNext(); ) {
            array.append(QJsonValue(QJsonObject::fromVariantMap(GroupUser(i.next()).toVariantMap())));
        }
    }
    return array;
}

TModelObject *GroupUser::modelData()
{
    return d.data();
}

const TModelObject *GroupUser::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const GroupUser &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, GroupUser &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(GroupUser)
