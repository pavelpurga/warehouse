#include "form.h"
#include "ui_form.h"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    db= QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./testD8.db");
    if(db.open()){
        qDebug("open");
    } else{
        qDebug("no open");
    }
    query = new QSqlQuery(db);
    query->exec("CREATE TABLE SKLAD(ID INT,NAME TEXT,ED_IZM TEXT,PRICE INT,KOLVO INT,DATA TEXT);");
        model=new QSqlTableModel(this,db);
        model->setTable("SKLAD");
        model->select();
        ui->tableView->setModel(model);


}

Form::~Form()
{
    delete ui;
}

void Form::on_tableView_clicked(const QModelIndex &index)
{
    row=index.row();
}



void Form::on_pushButton_clicked()
{
    model->insertRow(model->rowCount());
}


void Form::on_pushButton_2_clicked()
{
    model->removeRow(row);
}


void Form::on_pushButton_3_clicked()
{
    this->close();
}

