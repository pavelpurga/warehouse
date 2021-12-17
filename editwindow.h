#ifndef EDITWINDOW_H
#define EDITWINDOW_H


#include <QtWidgets/QWidget>
#include "ui_editwindow.h"
#include <QtSql/qsqldatabase.h>
#include <QDebug>
#include <QtSql/qsqlquery.h>
#include <QtSql/qsqltablemodel.h>
#include <qspinbox.h>
namespace Ui {
class EditWindow;
}

class EditWindow : public QWidget
{
    Q_OBJECT

public:
    explicit EditWindow(QWidget *parent = nullptr);
    ~EditWindow();

private slots:
    void on_tableView_clicked(const QModelIndex &index);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::EditWindow *ui;

        QSqlDatabase db;
        QSqlQuery* query;
        QSqlTableModel *model;
        int row;
};

#endif // EDITWINDOW_H
