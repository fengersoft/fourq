#ifndef USERICONWIDGET_H
#define USERICONWIDGET_H

#include <QWidget>
#include <QIcon>
#include <QPainter>

namespace Ui
{
class UserIconWidget;
}

class UserIconWidget : public QWidget
{
    Q_OBJECT

public:
    explicit UserIconWidget(QWidget* parent = nullptr);
    ~UserIconWidget();


    QPixmap icon() const;
    void setIcon(QPixmap& icon);
    void paintEvent(QPaintEvent* event);
private:
    Ui::UserIconWidget* ui;
    QPixmap m_icon;
};

#endif // USERICONWIDGET_H
