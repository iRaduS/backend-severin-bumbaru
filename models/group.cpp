#include <TreeFrogModel>
#include "group.h"
#include "sqlobjects/groupobject.h"

Group::Group() :
    TAbstractModel(),
    d(new GroupObject())
{
    // set the initial parameters
}

Group::Group(const Group &other) :
    TAbstractModel(),
    d(other.d)
{ }

Group::Group(const GroupObject &object) :
    TAbstractModel(),
    d(new GroupObject(object))
{ }

Group::~Group()
{
    // If the reference count becomes 0,
    // the shared data object 'GroupObject' is deleted.
}

int Group::id() const
{
    return d->id;
}

QString Group::name() const
{
    return d->name;
}

void Group::setName(const QString &name)
{
    d->name = name;
}

QString Group::invite() const
{
    return d->invite;
}

void Group::setInvite(const QString &invite)
{
    d->invite = invite;
}

int Group::userId() const
{
    return d->user_id;
}

void Group::setUserId(int userId)
{
    d->user_id = userId;
}

Group &Group::operator=(const Group &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

Group Group::create(const QString &name, const QString &invite, int userId)
{
    GroupObject obj;
    obj.name = name;
    obj.invite = invite;
    obj.user_id = userId;
    if (!obj.create()) {
        return Group();
    }
    return Group(obj);
}

Group Group::create(const QVariantMap &values)
{
    Group model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

Group Group::get(int id)
{
    TSqlORMapper<GroupObject> mapper;
    return Group(mapper.findByPrimaryKey(id));
}

int Group::count()
{
    TSqlORMapper<GroupObject> mapper;
    return mapper.findCount();
}

QList<Group> Group::getAll()
{
    return tfGetModelListByCriteria<Group, GroupObject>(TCriteria());
}

QJsonArray Group::getAllJson()
{
    QJsonArray array;
    TSqlORMapper<GroupObject> mapper;

    if (mapper.find() > 0) {
        for (TSqlORMapperIterator<GroupObject> i(mapper); i.hasNext(); ) {
            array.append(QJsonValue(QJsonObject::fromVariantMap(Group(i.next()).toVariantMap())));
        }
    }
    return array;
}

TModelObject *Group::modelData()
{
    return d.data();
}

const TModelObject *Group::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const Group &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, Group &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(Group)
