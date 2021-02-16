#include "usericonwidget.h"
#include "ui_usericonwidget.h"

UserIconWidget::UserIconWidget(QWidget *parent) :
      QWidget(parent),
      ui(new Ui::UserIconWidget)
{
    ui->setupUi(this);
}

UserIconWidget::~UserIconWidget()
{
    delete ui;
}
