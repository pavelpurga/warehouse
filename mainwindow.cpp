#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "searchwindow.h"
#include <QtSql/qsqldatabase.h>
#include <QDebug>
#include <qstring.h>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    {
    ui->setupUi(this);

    }

MainWindow::~MainWindow()
{
    delete ui;
}





void MainWindow::on_pushButton_clicked()
{
    editwindow.show();
}


void MainWindow::on_pushButton_2_clicked()
{
    searchwindow.show();
}


void MainWindow::on_pushButton_3_clicked()
{
    this->close();
}

