#ifndef FOURQWIDGETITEM_H
#define FOURQWIDGETITEM_H

#include <QObject>
#include <QRect>
#include  <QDateTime>

class FourQWidgetItem : public QObject
{
    Q_OBJECT
public:
    explicit FourQWidgetItem(QObject* parent = nullptr);

    QString info() const;
    void setInfo(const QString& info);

    QRect itemRect() const;
    void setItemRect(const QRect& itemRect);

    int important() const;
    void setImportant(int important);

    int emergency() const;
    void setEmergency(int emergency);

    QDateTime createTime() const;
    void setCreateTime(const QDateTime& createTime);

signals:

private:
    QString m_info;
    QRect m_itemRect;
    int m_important;
    int m_emergency;
    QDateTime m_createTime;

};

#endif // FOURQWIDGETITEM_H
