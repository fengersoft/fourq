#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QButtonGroup>

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

private slots:
    void on_btnNote_clicked();

    void on_btnChart_clicked();

private:
    Ui::MainWindow* ui;
    QButtonGroup* m_btnGroup;
};
#endif // MAINWINDOW_H
