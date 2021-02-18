#include "searchdialog.h"
#include "ui_searchdialog.h"

SearchDialog::SearchDialog(QWidget* parent) :
    QDialog(parent),
    ui(new Ui::SearchDialog)
{
    ui->setupUi(this);
    ui->edtEnd->setDate(QDate::currentDate());
    ui->edtStart->setDate(QDate::currentDate().addDays(-7));
}

SearchDialog::~SearchDialog()
{
    delete ui;
}

QString SearchDialog::getWhereStr()
{
    QString s = " where (info like '%" + ui->edtKeyword->text() + "%') and (createtime>='" +
                ui->edtStart->date().toString("yyyy-MM-dd 00:00:00") + "' and createtime<='" +
                ui->edtEnd->date().toString("yyyy-MM-dd 23:59:59") + "')";
    return  s;
}

void SearchDialog::on_btnSearch_clicked()
{
    accept();
}
