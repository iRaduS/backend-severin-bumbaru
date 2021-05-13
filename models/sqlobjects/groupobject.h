#ifndef GROUPOBJECT_H
#define GROUPOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT GroupObject : public TSqlObject, public QSharedData
{
public:
    int id {0};
    QString name;
    QString invite;
    int user_id {0};

    enum PropertyIndex {
        Id = 0,
        Name,
        Invite,
        UserId,
    };

    int primaryKeyIndex() const override { return Id; }
    int autoValueIndex() const override { return Id; }
    QString tableName() const override { return QStringLiteral("groups"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int id READ getid WRITE setid)
    T_DEFINE_PROPERTY(int, id)
    Q_PROPERTY(QString name READ getname WRITE setname)
    T_DEFINE_PROPERTY(QString, name)
    Q_PROPERTY(QString invite READ getinvite WRITE setinvite)
    T_DEFINE_PROPERTY(QString, invite)
    Q_PROPERTY(int user_id READ getuser_id WRITE setuser_id)
    T_DEFINE_PROPERTY(int, user_id)
};

#endif // GROUPOBJECT_H
