#ifndef GROUPUSER_H
#define GROUPUSER_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class GroupUserObject;
class QJsonArray;


class T_MODEL_EXPORT GroupUser : public TAbstractModel
{
public:
    GroupUser();
    GroupUser(const GroupUser &other);
    GroupUser(const GroupUserObject &object);
    ~GroupUser();

    int id() const;
    int userId() const;
    void setUserId(int userId);
    int groupId() const;
    void setGroupId(int groupId);
    int role() const;
    void setRole(int role);
    GroupUser &operator=(const GroupUser &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static GroupUser create(int userId, int groupId, int role);
    static GroupUser create(const QVariantMap &values);
    static GroupUser get(int id);
    static int count();
    static QList<GroupUser> getAll();
    static QJsonArray getAllJson();

private:
    QSharedDataPointer<GroupUserObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const GroupUser &model);
    friend QDataStream &operator>>(QDataStream &ds, GroupUser &model);
};

Q_DECLARE_METATYPE(GroupUser)
Q_DECLARE_METATYPE(QList<GroupUser>)

#endif // GROUPUSER_H
