#ifndef GROUPUSEROBJECT_H
#define GROUPUSEROBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT GroupUserObject : public TSqlObject, public QSharedData
{
public:
    int id {0};
    int user_id {0};
    int group_id {0};
    int role {0};

    enum PropertyIndex {
        Id = 0,
        UserId,
        GroupId,
        Role,
    };

    int primaryKeyIndex() const override { return Id; }
    int autoValueIndex() const override { return Id; }
    QString tableName() const override { return QStringLiteral("group_user"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int id READ getid WRITE setid)
    T_DEFINE_PROPERTY(int, id)
    Q_PROPERTY(int user_id READ getuser_id WRITE setuser_id)
    T_DEFINE_PROPERTY(int, user_id)
    Q_PROPERTY(int group_id READ getgroup_id WRITE setgroup_id)
    T_DEFINE_PROPERTY(int, group_id)
    Q_PROPERTY(int role READ getrole WRITE setrole)
    T_DEFINE_PROPERTY(int, role)
};

#endif // GROUPUSEROBJECT_H
