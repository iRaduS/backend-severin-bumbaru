#include <TreeFrogModel>
#include "userquiz.h"
#include "sqlobjects/userquizobject.h"

UserQuiz::UserQuiz() :
    TAbstractModel(),
    d(new UserQuizObject())
{
    // set the initial parameters
}

UserQuiz::UserQuiz(const UserQuiz &other) :
    TAbstractModel(),
    d(other.d)
{ }

UserQuiz::UserQuiz(const UserQuizObject &object) :
    TAbstractModel(),
    d(new UserQuizObject(object))
{ }

UserQuiz::~UserQuiz()
{
    // If the reference count becomes 0,
    // the shared data object 'UserQuizObject' is deleted.
}

int UserQuiz::id() const
{
    return d->id;
}

int UserQuiz::userId() const
{
    return d->user_id;
}

void UserQuiz::setUserId(int userId)
{
    d->user_id = userId;
}

int UserQuiz::quizId() const
{
    return d->quiz_id;
}

void UserQuiz::setQuizId(int quizId)
{
    d->quiz_id = quizId;
}

UserQuiz &UserQuiz::operator=(const UserQuiz &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

UserQuiz UserQuiz::create(int userId, int quizId)
{
    UserQuizObject obj;
    obj.user_id = userId;
    obj.quiz_id = quizId;
    if (!obj.create()) {
        return UserQuiz();
    }
    return UserQuiz(obj);
}

UserQuiz UserQuiz::create(const QVariantMap &values)
{
    UserQuiz model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

UserQuiz UserQuiz::get(int id)
{
    TSqlORMapper<UserQuizObject> mapper;
    return UserQuiz(mapper.findByPrimaryKey(id));
}

int UserQuiz::count()
{
    TSqlORMapper<UserQuizObject> mapper;
    return mapper.findCount();
}

QList<UserQuiz> UserQuiz::getAll()
{
    return tfGetModelListByCriteria<UserQuiz, UserQuizObject>(TCriteria());
}

QJsonArray UserQuiz::getAllJson()
{
    QJsonArray array;
    TSqlORMapper<UserQuizObject> mapper;

    if (mapper.find() > 0) {
        for (TSqlORMapperIterator<UserQuizObject> i(mapper); i.hasNext(); ) {
            array.append(QJsonValue(QJsonObject::fromVariantMap(UserQuiz(i.next()).toVariantMap())));
        }
    }
    return array;
}

TModelObject *UserQuiz::modelData()
{
    return d.data();
}

const TModelObject *UserQuiz::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const UserQuiz &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, UserQuiz &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(UserQuiz)
