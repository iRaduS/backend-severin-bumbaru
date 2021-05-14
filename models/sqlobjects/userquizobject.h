#ifndef USERQUIZOBJECT_H
#define USERQUIZOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT UserQuizObject : public TSqlObject, public QSharedData
{
public:
    int id {0};
    int user_id {0};
    int quiz_id {0};

    enum PropertyIndex {
        Id = 0,
        UserId,
        QuizId,
    };

    int primaryKeyIndex() const override { return Id; }
    int autoValueIndex() const override { return Id; }
    QString tableName() const override { return QStringLiteral("user_quiz"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int id READ getid WRITE setid)
    T_DEFINE_PROPERTY(int, id)
    Q_PROPERTY(int user_id READ getuser_id WRITE setuser_id)
    T_DEFINE_PROPERTY(int, user_id)
    Q_PROPERTY(int quiz_id READ getquiz_id WRITE setquiz_id)
    T_DEFINE_PROPERTY(int, quiz_id)
};

#endif // USERQUIZOBJECT_H
