#ifndef USERICONWIDGET_H
#define USERICONWIDGET_H

#include <QWidget>

namespace Ui {
class UserIconWidget;
}

class UserIconWidget : public QWidget
{
    Q_OBJECT

public:
    explicit UserIconWidget(QWidget *parent = nullptr);
    ~UserIconWidget();

private:
    Ui::UserIconWidget *ui;
};

#endif // USERICONWIDGET_H
