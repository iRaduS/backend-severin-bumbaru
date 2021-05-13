#ifndef USER_H
#define USER_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractUser>
#include <TAbstractModel>

class TModelObject;
class UserObject;
class QJsonArray;


class T_MODEL_EXPORT User : public TAbstractUser, public TAbstractModel
{
public:
    User();
    User(const User &other);
    User(const UserObject &object);
    ~User();

    int id() const;
    QString username() const;
    void setUsername(const QString &username);
    QString password() const;
    void setPassword(const QString &password);
    QString email() const;
    void setEmail(const QString &email);
    QString name() const;
    void setName(const QString &name);
    int credits() const;
    void setCredits(int credits);
    int isElonMusk() const;
    void setIsElonMusk(int isElonMusk);
    int isTesla() const;
    void setIsTesla(int isTesla);
    int isHeart() const;
    void setIsHeart(int isHeart);
    int isFire() const;
    void setIsFire(int isFire);
    int fiftyFifty() const;
    void setFiftyFifty(int fiftyFifty);
    int hintGuesser() const;
    void setHintGuesser(int hintGuesser);
    QString identityKey() const { return username(); }
    User &operator=(const User &other);

    bool create() { return TAbstractModel::create(); }
    bool update() { return TAbstractModel::update(); }
    bool save()   { return TAbstractModel::save(); }
    bool remove() { return TAbstractModel::remove(); }

    static User getByIdentityKey(const QString &username);
    static User authenticate(const QString &username, const QString &password);
    static User create(const QString &username, const QString &password, const QString &email, const QString &name, int credits, int isElonMusk, int isTesla, int isHeart, int isFire, int fiftyFifty, int hintGuesser);
    static User create(const QVariantMap &values);
    static User get(int id);
    static int count();
    static QList<User> getAll();
    static QJsonArray getAllJson();

private:
    QSharedDataPointer<UserObject> d;

    TModelObject *modelData();
    const TModelObject *modelData() const;
    friend QDataStream &operator<<(QDataStream &ds, const User &model);
    friend QDataStream &operator>>(QDataStream &ds, User &model);
};

Q_DECLARE_METATYPE(User)
Q_DECLARE_METATYPE(QList<User>)

#endif // USER_H
