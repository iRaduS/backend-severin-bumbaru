#include <TreeFrogModel>
#include "user.h"
#include "sqlobjects/userobject.h"

User::User() :
    TAbstractUser(),
    TAbstractModel(),
    d(new UserObject())
{
    // set the initial parameters
}

User::User(const User &other) :
    TAbstractUser(),
    TAbstractModel(),
    d(other.d)
{ }

User::User(const UserObject &object) :
    TAbstractUser(),
    TAbstractModel(),
    d(new UserObject(object))
{ }


User::~User()
{
    // If the reference count becomes 0,
    // the shared data object 'UserObject' is deleted.
}

int User::id() const
{
    return d->id;
}

QString User::username() const
{
    return d->username;
}

void User::setUsername(const QString &username)
{
    d->username = username;
}

QString User::password() const
{
    return d->password;
}

void User::setPassword(const QString &password)
{
    d->password = password;
}

QString User::email() const
{
    return d->email;
}

void User::setEmail(const QString &email)
{
    d->email = email;
}

QString User::name() const
{
    return d->name;
}

void User::setName(const QString &name)
{
    d->name = name;
}

int User::credits() const
{
    return d->credits;
}

void User::setCredits(int credits)
{
    d->credits = credits;
}

int User::isElonMusk() const
{
    return d->isElonMusk;
}

void User::setIsElonMusk(int isElonMusk)
{
    d->isElonMusk = isElonMusk;
}

int User::isTesla() const
{
    return d->isTesla;
}

void User::setIsTesla(int isTesla)
{
    d->isTesla = isTesla;
}

int User::isHeart() const
{
    return d->isHeart;
}

void User::setIsHeart(int isHeart)
{
    d->isHeart = isHeart;
}

int User::isFire() const
{
    return d->isFire;
}

void User::setIsFire(int isFire)
{
    d->isFire = isFire;
}

int User::fiftyFifty() const
{
    return d->fiftyFifty;
}

void User::setFiftyFifty(int fiftyFifty)
{
    d->fiftyFifty = fiftyFifty;
}

int User::hintGuesser() const
{
    return d->hintGuesser;
}

void User::setHintGuesser(int hintGuesser)
{
    d->hintGuesser = hintGuesser;
}

User &User::operator=(const User &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

User User::authenticate(const QString &username, const QString &password)
{
    if (username.isEmpty() || password.isEmpty())
        return User();

    TSqlORMapper<UserObject> mapper;
    UserObject obj = mapper.findFirst(TCriteria(UserObject::Username, username));
    if (obj.isNull() || obj.password != password) {
        obj.clear();
    }
    return User(obj);
}

User User::create(const QString &username, const QString &password, const QString &email, const QString &name, int credits, int isElonMusk, int isTesla, int isHeart, int isFire, int fiftyFifty, int hintGuesser)
{
    UserObject obj;
    obj.username = username;
    obj.password = password;
    obj.email = email;
    obj.name = name;
    obj.credits = credits;
    obj.isElonMusk = isElonMusk;
    obj.isTesla = isTesla;
    obj.isHeart = isHeart;
    obj.isFire = isFire;
    obj.fiftyFifty = fiftyFifty;
    obj.hintGuesser = hintGuesser;
    if (!obj.create()) {
        return User();
    }
    return User(obj);
}

User User::getByIdentityKey(const QString &username)
{
    TSqlORMapper<UserObject> mapper;
    TCriteria cri(UserObject::Username, username);
    return User(mapper.findFirst(cri));
}

User User::create(const QVariantMap &values)
{
    User model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

User User::get(int id)
{
    TSqlORMapper<UserObject> mapper;
    return User(mapper.findByPrimaryKey(id));
}

int User::count()
{
    TSqlORMapper<UserObject> mapper;
    return mapper.findCount();
}

QList<User> User::getAll()
{
    return tfGetModelListByCriteria<User, UserObject>();
}

QJsonArray User::getAllJson()
{
    QJsonArray array;
    TSqlORMapper<UserObject> mapper;

    if (mapper.find() > 0) {
        for (TSqlORMapperIterator<UserObject> i(mapper); i.hasNext(); ) {
            array.append(QJsonValue(QJsonObject::fromVariantMap(User(i.next()).toVariantMap())));
        }
    }
    return array;
}

TModelObject *User::modelData()
{
    return d.data();
}

const TModelObject *User::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const User &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, User &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(User)