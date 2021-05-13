#ifndef QUIZ_H
#define QUIZ_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class QuizObject;
class QJsonArray;


class T_MODEL_EXPORT Quiz : public TAbstractModel
{
public:
    Quiz();
    Quiz(const Quiz &other);
    Quiz(const QuizObject &object);
    ~Quiz();

    int id() const;
    QString name() const;
    void setName(const QString &name);
    QString details() const;
    void setDetails(const QString &details);
    int groupId() const;
    void setGroupId(int groupId);
    Quiz &operator=(const Quiz &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static Quiz create(const QString &name, const QString &details, int groupId);
    static Quiz create(const QVariantMap &values);
    static Quiz get(int id);
    static int count();
    static QList<Quiz> getAll();
    static QJsonArray getAllJson();

private:
    QSharedDataPointer<QuizObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const Quiz &model);
    friend QDataStream &operator>>(QDataStream &ds, Quiz &model);
};

Q_DECLARE_METATYPE(Quiz)
Q_DECLARE_METATYPE(QList<Quiz>)

#endif // QUIZ_H
