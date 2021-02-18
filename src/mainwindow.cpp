#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_btnGroup = new QButtonGroup(this);
    m_btnGroup->addButton(ui->btnNote);
    m_btnGroup->addButton(ui->btnChart);

    m_fourQWidget = new FourQWidget(this);
    QHBoxLayout* lay = new QHBoxLayout(this);
    ui->pageChart->setLayout(lay);
    lay->addWidget(m_fourQWidget);
    lay->setContentsMargins(0, 0, 0, 0);
    m_whereStr = " where 2>1 ";
    showInfos(m_whereStr);



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateBtnIcon()
{
    if (ui->btnNote->isChecked())
    {
        ui->btnNote->setIcon(QIcon(":/res/note_down.png"));
    }
    else
    {
        ui->btnNote->setIcon(QIcon(":/res/note.png"));
    }

    if (ui->btnChart->isChecked())
    {
        ui->btnChart->setIcon(QIcon(":/res/chart_down.png"));
    }
    else
    {
        ui->btnChart->setIcon(QIcon(":/res/chart.png"));
    }
}

void MainWindow::addInfo(QString s, int isEmergency, int isImportant)
{
    QString sql = QString("insert into t_info(info,isImportant,isEmergency) values('%1',%2,%3)")
                  .arg(s).arg(isImportant).arg(isEmergency);
    sqliteDao()->sqliteWrapper()->execute(sql);
    QListWidgetItem* item = new QListWidgetItem();
    item->setSizeHint(QSize(ui->lvData->width() - 24, 101));
    InfoWidget* w = new InfoWidget(this);
    w->setInfo(s);
    w->setCreateTime(QDateTime::currentDateTime());
    ui->lvData->addItem(item);
    ui->lvData->setItemWidget(item, w);
    ui->lvData->setCurrentRow(ui->lvData->count() - 1);

}

void MainWindow::showInfos(QString whereStr)
{
    QSqlQuery qry;
    QString sql = "select * from t_info " + whereStr + " order by id";
    sqliteDao()->sqliteWrapper()->select(sql, qry);
    ui->lvData->clear();
    m_fourQWidget->clear();
    while (qry.next())
    {
        QListWidgetItem* item = new QListWidgetItem();
        item->setSizeHint(QSize(ui->lvData->width() - 24, 101));
        InfoWidget* w = new InfoWidget(this);
        w->setInfo(qry.value("info").toString());
        w->setCreateTime(qry.value("createtime").toDateTime());
        ui->lvData->addItem(item);
        ui->lvData->setItemWidget(item, w);
        FourQWidgetItem* newItem = new FourQWidgetItem(this);
        newItem->setInfo(qry.value("info").toString());
        newItem->setImportant(qry.value("isImportant").toInt());
        newItem->setEmergency(qry.value("isEmergency").toInt());
        newItem->setCreateTime(qry.value("createtime").toDateTime());
        m_fourQWidget->items << newItem;


    }
    m_fourQWidget->update();
}


void MainWindow::on_btnNote_clicked()
{
    updateBtnIcon();
    ui->wgtPages->setCurrentWidget(ui->pageNote);
}

void MainWindow::on_btnChart_clicked()
{
    updateBtnIcon();
    showInfos(m_whereStr);
    ui->wgtPages->setCurrentWidget(ui->pageChart);
    m_fourQWidget->resetCenter();
}

void MainWindow::on_btnOk_clicked()
{
    int isImprtant = ui->btnIsImportant->isChecked() ? 1 : 0;
    int isEmergency = ui->btnIsEmergent->isChecked() ? 1 : 0;
    addInfo(ui->edtInput->toPlainText(),  isEmergency, isImprtant);
    ui->edtInput->clear();
    ui->btnIsEmergent->setChecked(false);
    ui->btnIsImportant->setChecked(false);


}

void MainWindow::on_btnSearch_clicked()
{
    SearchDialog* dlg = new SearchDialog();
    int ret = dlg->exec();
    if (ret == QDialog::Accepted)
    {
        m_whereStr = dlg->getWhereStr();
        showInfos(m_whereStr);
    }
    delete  dlg;

}
