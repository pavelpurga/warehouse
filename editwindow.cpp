#include "editwindow.h"
#include "ui_editwindow.h"

EditWindow::EditWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EditWindow)
{
    ui->setupUi(this);
    db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("./list_tovarov.db");
        if (db.open())
        {
            qDebug("Opened succsessfully!");
        }
        else
        {
            qDebug("Not opened...");
        }
        query = new QSqlQuery(db);
        query->exec("CREATE TABLE sklad(ID INT, Name TEXT,ED_TOV TEXT,Price INT, DATA INT);");
        model = new QSqlTableModel(this, db);
        model->setTable("sklad");
        model->select();
        ui->tableView->setModel(model);
}

EditWindow::~EditWindow()
{
    delete ui;
}

void EditWindow::on_tableView_clicked(const QModelIndex &index)
{
    row = index.row();
}


void EditWindow::on_pushButton_clicked()
{
     model->insertRow(model->rowCount());
}


void EditWindow::on_pushButton_2_clicked()
{
    model->removeRow(row);
        model->select();
}


void EditWindow::on_pushButton_3_clicked()
{
    this->close();
}

