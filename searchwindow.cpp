#include "searchwindow.h"
#include "ui_searchwindow.h"

SearchWindow::SearchWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SearchWindow)
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

SearchWindow::~SearchWindow()
{
   // delete ui;
    delete query;
        delete model;
}

void SearchWindow::on_pushButton_exit_clicked()
{
    this->close();
}


void SearchWindow::on_tableView_clicked(const QModelIndex &index)
{

}


void SearchWindow::on_Search_clicked()
{
    bool isSearch = false;
        QString filter;
        if (ui->checkBox_stop->isChecked())
        {
            filter = "Type='davno_ne_postovlyaly'";
            isSearch = true;
        }
        if (ui->checkBox_tovar->isChecked())
        {
            filter = "Type='0'";
            isSearch = true;
        }
        /*if (ui.RAMcheckBox->isChecked())
        {
            filter = "Type='RAM'";
            isSearch = true;
        }
        if (ui.GPUcheckBox->isChecked())
        {
            filter = "Type='GPU'";
            isSearch = true;
        }*/
        if (ui->spinBox_price->value() != 0)
        {
            int x = ui->spinBox_price->value();
            QString str = QString::number(x, 10);
            str.prepend("Price='");
            str.append("'");
            if (isSearch)
            {
                str.prepend(" and ");
                filter.append(str);
            }
            else
            {
                isSearch = true;
                filter = str;
            }
        }
        /*if (ui->lineEdit_name->value() != 0)
        {
            int x = ui->lineEdit_name->value();
            QString str = QString::number(x, 10);
            str.prepend("Name='");
            str.append("'");
            if (isSearch)
            {
                str.prepend(" and ");
                filter.append(str);
            }
            else
            {
                isSearch = true;
                filter = str;
            }
        }*/
        if (ui->lineEdit_name->isModified())
        {
            QString str;
            str=ui->lineEdit_name->text();
            str.prepend("Name LIKE '%");
            str.append("%'");
            if (isSearch)
            {
                str.prepend(" and ");
                filter.append(str);
            }
            else
            {
                isSearch = true;
                filter = str;
            }
        }
        if (!isSearch)
        {
            model->setTable("sklad");
        }
        else
        {
            model->setFilter(filter);
        }
        model->select();
}






void SearchWindow::checkBox_tovar_stateChanged(int arg1)
{
    if (arg1 == Qt::Checked)
    {
        ui->checkBox_tovar->setChecked(false);
        ui->checkBox_stop->setChecked(false);

    }
}

void SearchWindow::checkBox_stop_stateChanged(int arg1)
{
    if (arg1 == Qt::Checked)
    {
        ui->checkBox_stop->setChecked(false);
        ui->checkBox_tovar->setChecked(false);

    }
}



void SearchWindow::on_pushButton_reset_clicked()
{
    ui->checkBox_price->setChecked(false);
    ui->checkBox_data->setChecked(false);
    ui->checkBox_stop->setChecked(false);
    ui->checkBox_tovar->setChecked(false);
    //ui.priceBox->setValue(0);
    ui->spinBox_price->setValue(0);
    ui->lineEdit_name->clear();
    model->setTable("sklad");
    model->select();
}

void SearchWindow::on_checkBox_price_stateChanged(int arg)
{
    if (arg == Qt::Checked)
    {
        ui->checkBox_price->setChecked(false);
    }
}

void SearchWindow::checkBox_data_stateChanged(int arg)
{
    if (arg == Qt::Checked)
    {
        ui->checkBox_data->setChecked(false);
    }
}

void SearchWindow::on_checkBoxminmax_stateChanged(int arg)
{
    if (arg == Qt::Checked)
    {
        ui->checkBox_maxmin->setChecked(false);
    }
}

void SearchWindow::on_checkBox_maxmin_stateChanged(int arg)
{
    if (arg == Qt::Checked)
    {
        ui->checkBoxminmax->setChecked(false);
    }
}








void SearchWindow::on_sortButton_clicked()
{
    if ((ui->checkBox_price->isChecked() || ui->checkBox_data->isChecked()) && (ui->checkBoxminmax->isChecked() || ui->checkBox_maxmin->isChecked()))
    {
        if (ui->checkBox_price->isChecked())
        {
            if (ui->checkBoxminmax->isChecked())
            {
                model->setSort(1, Qt::AscendingOrder);
            }
            else
            {
                model->setSort(1, Qt::DescendingOrder);
            }
        }
        else
        {
            if (ui->checkBox_maxmin->isChecked())
            {
                model->setSort(2, Qt::DescendingOrder);
            }
            else
            {
                model->setSort(2, Qt::AscendingOrder);
            }
        }
        model->select();
      }

}
