#include <TreeFrogModel>
#include "creditlog.h"
#include "sqlobjects/creditlogobject.h"

CreditLog::CreditLog() :
    TAbstractModel(),
    d(new CreditLogObject())
{
    // set the initial parameters
}

CreditLog::CreditLog(const CreditLog &other) :
    TAbstractModel(),
    d(other.d)
{ }

CreditLog::CreditLog(const CreditLogObject &object) :
    TAbstractModel(),
    d(new CreditLogObject(object))
{ }

CreditLog::~CreditLog()
{
    // If the reference count becomes 0,
    // the shared data object 'CreditLogObject' is deleted.
}

int CreditLog::id() const
{
    return d->id;
}

int CreditLog::userId() const
{
    return d->user_id;
}

void CreditLog::setUserId(int userId)
{
    d->user_id = userId;
}

int CreditLog::credits() const
{
    return d->credits;
}

void CreditLog::setCredits(int credits)
{
    d->credits = credits;
}

QString CreditLog::action() const
{
    return d->action;
}

void CreditLog::setAction(const QString &action)
{
    d->action = action;
}

CreditLog &CreditLog::operator=(const CreditLog &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

CreditLog CreditLog::create(int userId, int credits, const QString &action)
{
    CreditLogObject obj;
    obj.user_id = userId;
    obj.credits = credits;
    obj.action = action;
    if (!obj.create()) {
        return CreditLog();
    }
    return CreditLog(obj);
}

CreditLog CreditLog::create(const QVariantMap &values)
{
    CreditLog model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

CreditLog CreditLog::get(int id)
{
    TSqlORMapper<CreditLogObject> mapper;
    return CreditLog(mapper.findByPrimaryKey(id));
}

int CreditLog::count()
{
    TSqlORMapper<CreditLogObject> mapper;
    return mapper.findCount();
}

QList<CreditLog> CreditLog::getAll()
{
    return tfGetModelListByCriteria<CreditLog, CreditLogObject>(TCriteria());
}

QJsonArray CreditLog::getAllJson()
{
    QJsonArray array;
    TSqlORMapper<CreditLogObject> mapper;

    if (mapper.find() > 0) {
        for (TSqlORMapperIterator<CreditLogObject> i(mapper); i.hasNext(); ) {
            array.append(QJsonValue(QJsonObject::fromVariantMap(CreditLog(i.next()).toVariantMap())));
        }
    }
    return array;
}

TModelObject *CreditLog::modelData()
{
    return d.data();
}

const TModelObject *CreditLog::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const CreditLog &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, CreditLog &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(CreditLog)
