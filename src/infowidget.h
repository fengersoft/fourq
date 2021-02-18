#ifndef INFOWIDGET_H
#define INFOWIDGET_H

#include <QWidget>
#include <QDateTime>

namespace Ui
{
class InfoWidget;
}

class InfoWidget : public QWidget
{
    Q_OBJECT

public:
    explicit InfoWidget(QWidget* parent = nullptr);
    ~InfoWidget();

    QString info() const;
    void setInfo(const QString& info);

    QDateTime createTime() const;
    void setCreateTime(const QDateTime& createTime);

private:
    Ui::InfoWidget* ui;
    QString m_info;
    QDateTime m_createTime;
};

#endif // INFOWIDGET_H
