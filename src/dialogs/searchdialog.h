#ifndef SEARCHDIALOG_H
#define SEARCHDIALOG_H

#include <QDialog>

namespace Ui
{
class SearchDialog;
}

class SearchDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SearchDialog(QWidget* parent = nullptr);
    ~SearchDialog();
    QString getWhereStr();

private slots:
    void on_btnSearch_clicked();

private:
    Ui::SearchDialog* ui;
};

#endif // SEARCHDIALOG_H
