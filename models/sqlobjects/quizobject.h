#ifndef QUIZOBJECT_H
#define QUIZOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT QuizObject : public TSqlObject, public QSharedData
{
public:
    int id {0};
    QString name;
    QString details;
    int group_id {0};

    enum PropertyIndex {
        Id = 0,
        Name,
        Details,
        GroupId,
    };

    int primaryKeyIndex() const override { return Id; }
    int autoValueIndex() const override { return Id; }
    QString tableName() const override { return QStringLiteral("quiz"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int id READ getid WRITE setid)
    T_DEFINE_PROPERTY(int, id)
    Q_PROPERTY(QString name READ getname WRITE setname)
    T_DEFINE_PROPERTY(QString, name)
    Q_PROPERTY(QString details READ getdetails WRITE setdetails)
    T_DEFINE_PROPERTY(QString, details)
    Q_PROPERTY(int group_id READ getgroup_id WRITE setgroup_id)
    T_DEFINE_PROPERTY(int, group_id)
};

#endif // QUIZOBJECT_H
