#include <TreeFrogModel>
#include "quiz.h"
#include "sqlobjects/quizobject.h"

Quiz::Quiz() :
    TAbstractModel(),
    d(new QuizObject())
{
    // set the initial parameters
}

Quiz::Quiz(const Quiz &other) :
    TAbstractModel(),
    d(other.d)
{ }

Quiz::Quiz(const QuizObject &object) :
    TAbstractModel(),
    d(new QuizObject(object))
{ }

Quiz::~Quiz()
{
    // If the reference count becomes 0,
    // the shared data object 'QuizObject' is deleted.
}

int Quiz::id() const
{
    return d->id;
}

QString Quiz::name() const
{
    return d->name;
}

void Quiz::setName(const QString &name)
{
    d->name = name;
}

QString Quiz::details() const
{
    return d->details;
}

void Quiz::setDetails(const QString &details)
{
    d->details = details;
}

int Quiz::groupId() const
{
    return d->group_id;
}

void Quiz::setGroupId(int groupId)
{
    d->group_id = groupId;
}

Quiz &Quiz::operator=(const Quiz &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

Quiz Quiz::create(const QString &name, const QString &details, int groupId)
{
    QuizObject obj;
    obj.name = name;
    obj.details = details;
    obj.group_id = groupId;
    if (!obj.create()) {
        return Quiz();
    }
    return Quiz(obj);
}

Quiz Quiz::create(const QVariantMap &values)
{
    Quiz model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

Quiz Quiz::get(int id)
{
    TSqlORMapper<QuizObject> mapper;
    return Quiz(mapper.findByPrimaryKey(id));
}

int Quiz::count()
{
    TSqlORMapper<QuizObject> mapper;
    return mapper.findCount();
}

QList<Quiz> Quiz::getAll()
{
    return tfGetModelListByCriteria<Quiz, QuizObject>(TCriteria());
}

QJsonArray Quiz::getAllJson()
{
    QJsonArray array;
    TSqlORMapper<QuizObject> mapper;

    if (mapper.find() > 0) {
        for (TSqlORMapperIterator<QuizObject> i(mapper); i.hasNext(); ) {
            array.append(QJsonValue(QJsonObject::fromVariantMap(Quiz(i.next()).toVariantMap())));
        }
    }
    return array;
}

TModelObject *Quiz::modelData()
{
    return d.data();
}

const TModelObject *Quiz::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const Quiz &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, Quiz &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(Quiz)
