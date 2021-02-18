#include "fourqwidgetitem.h"

FourQWidgetItem::FourQWidgetItem(QObject* parent) : QObject(parent)
{

}

QString FourQWidgetItem::info() const
{
    return m_info;
}

void FourQWidgetItem::setInfo(const QString& info)
{
    m_info = info;
}

QRect FourQWidgetItem::itemRect() const
{
    return m_itemRect;
}

void FourQWidgetItem::setItemRect(const QRect& itemRect)
{
    m_itemRect = itemRect;
}

int FourQWidgetItem::important() const
{
    return m_important;
}

void FourQWidgetItem::setImportant(int important)
{
    m_important = important;
}

int FourQWidgetItem::emergency() const
{
    return m_emergency;
}

void FourQWidgetItem::setEmergency(int emergency)
{
    m_emergency = emergency;
}

QDateTime FourQWidgetItem::createTime() const
{
    return m_createTime;
}

void FourQWidgetItem::setCreateTime(const QDateTime &createTime)
{
    m_createTime = createTime;
}
