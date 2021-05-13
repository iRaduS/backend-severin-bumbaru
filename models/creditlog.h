#ifndef CREDITLOG_H
#define CREDITLOG_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class CreditLogObject;
class QJsonArray;


class T_MODEL_EXPORT CreditLog : public TAbstractModel
{
public:
    CreditLog();
    CreditLog(const CreditLog &other);
    CreditLog(const CreditLogObject &object);
    ~CreditLog();

    int id() const;
    int userId() const;
    void setUserId(int userId);
    int credits() const;
    void setCredits(int credits);
    QString action() const;
    void setAction(const QString &action);
    CreditLog &operator=(const CreditLog &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static CreditLog create(int userId, int credits, const QString &action);
    static CreditLog create(const QVariantMap &values);
    static CreditLog get(int id);
    static int count();
    static QList<CreditLog> getAll();
    static QJsonArray getAllJson();

private:
    QSharedDataPointer<CreditLogObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const CreditLog &model);
    friend QDataStream &operator>>(QDataStream &ds, CreditLog &model);
};

Q_DECLARE_METATYPE(CreditLog)
Q_DECLARE_METATYPE(QList<CreditLog>)

#endif // CREDITLOG_H
