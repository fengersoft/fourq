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


void MainWindow::on_btnNote_clicked()
{
    updateBtnIcon();
}

void MainWindow::on_btnChart_clicked()
{
    updateBtnIcon();
}
