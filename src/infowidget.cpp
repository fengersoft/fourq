#include "infowidget.h"
#include "ui_infowidget.h"

InfoWidget::InfoWidget(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::InfoWidget)
{
    ui->setupUi(this);
    QPixmap pix(":/res/users/0.png");
    ui->wgtIcon->setIcon(pix);
}

InfoWidget::~InfoWidget()
{
    delete ui;
}

QString InfoWidget::info() const
{
    return m_info;
}

void InfoWidget::setInfo(const QString& info)
{
    m_info = info;
    ui->edtInfo->setText(m_info);
}

QDateTime InfoWidget::createTime() const
{
    return m_createTime;
}

void InfoWidget::setCreateTime(const QDateTime& createTime)
{
    m_createTime = createTime;
    ui->lblDate->setText(m_createTime.toString("yyyy-MM-dd hh:mm:ss"));
}
