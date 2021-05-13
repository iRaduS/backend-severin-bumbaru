#ifndef GROUP_H
#define GROUP_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class GroupObject;
class QJsonArray;


class T_MODEL_EXPORT Group : public TAbstractModel
{
public:
    Group();
    Group(const Group &other);
    Group(const GroupObject &object);
    ~Group();

    int id() const;
    QString name() const;
    void setName(const QString &name);
    QString invite() const;
    void setInvite(const QString &invite);
    int userId() const;
    void setUserId(int userId);
    Group &operator=(const Group &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static Group create(const QString &name, const QString &invite, int userId);
    static Group create(const QVariantMap &values);
    static Group get(int id);
    static int count();
    static QList<Group> getAll();
    static QJsonArray getAllJson();

private:
    QSharedDataPointer<GroupObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const Group &model);
    friend QDataStream &operator>>(QDataStream &ds, Group &model);
};

Q_DECLARE_METATYPE(Group)
Q_DECLARE_METATYPE(QList<Group>)

#endif // GROUP_H
