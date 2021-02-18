#include "usericonwidget.h"
#include "ui_usericonwidget.h"

UserIconWidget::UserIconWidget(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::UserIconWidget)
{
    ui->setupUi(this);
}

UserIconWidget::~UserIconWidget()
{
    delete ui;
}

QPixmap UserIconWidget::icon() const
{
    return m_icon;
}

void UserIconWidget::setIcon(QPixmap& icon)
{
    m_icon = icon;
    update();
}

void UserIconWidget::paintEvent(QPaintEvent* event)
{
    QPainter painter;
    painter.begin(this);
    painter.drawPixmap(rect(), m_icon, m_icon.rect());
    painter.end();

}
