#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include <QSqlDatabase>
#include <QMainWindow>
#include<QDebug>
#include<QSqlQuery>
#include<QSqlTableModel>
namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();

private slots:
    void on_tableView_clicked(const QModelIndex &index);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Form *ui;
    QSqlDatabase db;
    QSqlQuery *query;
    QSqlTableModel *model;
    int row;
};

#endif // FORM_H
