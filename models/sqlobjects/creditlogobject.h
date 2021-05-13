#ifndef CREDITLOGOBJECT_H
#define CREDITLOGOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT CreditLogObject : public TSqlObject, public QSharedData
{
public:
    int id {0};
    int user_id {0};
    int credits {0};
    QString action;

    enum PropertyIndex {
        Id = 0,
        UserId,
        Credits,
        Action,
    };

    int primaryKeyIndex() const override { return Id; }
    int autoValueIndex() const override { return Id; }
    QString tableName() const override { return QStringLiteral("credit_log"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int id READ getid WRITE setid)
    T_DEFINE_PROPERTY(int, id)
    Q_PROPERTY(int user_id READ getuser_id WRITE setuser_id)
    T_DEFINE_PROPERTY(int, user_id)
    Q_PROPERTY(int credits READ getcredits WRITE setcredits)
    T_DEFINE_PROPERTY(int, credits)
    Q_PROPERTY(QString action READ getaction WRITE setaction)
    T_DEFINE_PROPERTY(QString, action)
};

#endif // CREDITLOGOBJECT_H
