#ifndef SEARCHWINDOW_H
#define SEARCHWINDOW_H


#include <QWidget>
#include "ui_searchwindow.h"
#include <QtSql/qsqldatabase.h>
#include <QDebug>
#include <QtSql/qsqlquery.h>
#include <QtSql/qsqltablemodel.h>
namespace Ui {
class SearchWindow;
}

class SearchWindow : public QWidget
{
    Q_OBJECT

public:
    explicit SearchWindow(QWidget *parent = nullptr);
    ~SearchWindow();

private slots:
    void on_checkBox_price_stateChanged(int);
       void checkBox_data_stateChanged(int);
       // void spinBox_price_stateChanged(int);
        void checkBox_stop_stateChanged(int);
        void checkBox_tovar_stateChanged(int);
        void on_checkBoxminmax_stateChanged(int);
       void on_checkBox_maxmin_stateChanged(int);
    void on_pushButton_reset_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void on_Search_clicked();



    void on_pushButton_exit_clicked();

    void on_sortButton_clicked();

private:
    Ui::SearchWindow *ui;
    QSqlDatabase db;
        QSqlQuery* query;
        QSqlTableModel* model;
};

#endif // SEARCHWINDOW_H





