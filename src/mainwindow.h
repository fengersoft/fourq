#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QButtonGroup>
#include "./api/sql/sqlitedao.h"
#include "infowidget.h"
#include <QScrollBar>
#include "./widgets/fourqwidget.h"
#include "./dialogs/searchdialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();
    void updateBtnIcon();
    ///添加信息
    void addInfo(QString s, int isEmergency, int isImportant);
    void showInfos(QString whereStr = " where 2>1 ");

private slots:
    void on_btnNote_clicked();

    void on_btnChart_clicked();

    void on_btnOk_clicked();

    void on_btnSearch_clicked();

private:
    Ui::MainWindow* ui;
    QButtonGroup* m_btnGroup;
    FourQWidget* m_fourQWidget;
    QString m_whereStr;

};
#endif // MAINWINDOW_H
