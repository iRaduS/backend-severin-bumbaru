#ifndef USERQUIZ_H
#define USERQUIZ_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class UserQuizObject;
class QJsonArray;


class T_MODEL_EXPORT UserQuiz : public TAbstractModel
{
public:
    UserQuiz();
    UserQuiz(const UserQuiz &other);
    UserQuiz(const UserQuizObject &object);
    ~UserQuiz();

    int id() const;
    int userId() const;
    void setUserId(int userId);
    int quizId() const;
    void setQuizId(int quizId);
    UserQuiz &operator=(const UserQuiz &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static UserQuiz create(int userId, int quizId);
    static UserQuiz create(const QVariantMap &values);
    static UserQuiz get(int id);
    static int count();
    static QList<UserQuiz> getAll();
    static QJsonArray getAllJson();

private:
    QSharedDataPointer<UserQuizObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const UserQuiz &model);
    friend QDataStream &operator>>(QDataStream &ds, UserQuiz &model);
};

Q_DECLARE_METATYPE(UserQuiz)
Q_DECLARE_METATYPE(QList<UserQuiz>)

#endif // USERQUIZ_H
