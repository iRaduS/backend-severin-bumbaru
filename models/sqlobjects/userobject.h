#ifndef USEROBJECT_H
#define USEROBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT UserObject : public TSqlObject, public QSharedData
{
public:
    int id {0};
    QString username;
    QString password;
    QString email;
    QString name;
    int credits {0};
    int isElonMusk {0};
    int isTesla {0};
    int isHeart {0};
    int isFire {0};
    int fiftyFifty {0};
    int hintGuesser {0};

    enum PropertyIndex {
        Id = 0,
        Username,
        Password,
        Email,
        Name,
        Credits,
        IsElonMusk,
        IsTesla,
        IsHeart,
        IsFire,
        FiftyFifty,
        HintGuesser,
    };

    int primaryKeyIndex() const override { return Id; }
    int autoValueIndex() const override { return Id; }
    QString tableName() const override { return QStringLiteral("user"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int id READ getid WRITE setid)
    T_DEFINE_PROPERTY(int, id)
    Q_PROPERTY(QString username READ getusername WRITE setusername)
    T_DEFINE_PROPERTY(QString, username)
    Q_PROPERTY(QString password READ getpassword WRITE setpassword)
    T_DEFINE_PROPERTY(QString, password)
    Q_PROPERTY(QString email READ getemail WRITE setemail)
    T_DEFINE_PROPERTY(QString, email)
    Q_PROPERTY(QString name READ getname WRITE setname)
    T_DEFINE_PROPERTY(QString, name)
    Q_PROPERTY(int credits READ getcredits WRITE setcredits)
    T_DEFINE_PROPERTY(int, credits)
    Q_PROPERTY(int isElonMusk READ getisElonMusk WRITE setisElonMusk)
    T_DEFINE_PROPERTY(int, isElonMusk)
    Q_PROPERTY(int isTesla READ getisTesla WRITE setisTesla)
    T_DEFINE_PROPERTY(int, isTesla)
    Q_PROPERTY(int isHeart READ getisHeart WRITE setisHeart)
    T_DEFINE_PROPERTY(int, isHeart)
    Q_PROPERTY(int isFire READ getisFire WRITE setisFire)
    T_DEFINE_PROPERTY(int, isFire)
    Q_PROPERTY(int fiftyFifty READ getfiftyFifty WRITE setfiftyFifty)
    T_DEFINE_PROPERTY(int, fiftyFifty)
    Q_PROPERTY(int hintGuesser READ gethintGuesser WRITE sethintGuesser)
    T_DEFINE_PROPERTY(int, hintGuesser)
};

#endif // USEROBJECT_H
