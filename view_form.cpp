#include "view_form.h"
#include "ui_view_form.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QDebug>


View_form::View_form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::View_form)
{
    ui->setupUi(this);
}

View_form::~View_form()
{
    delete ui;
}

void View_form::on_pushButton_view_clicked()
{

    const int columnCount = 6;
    ui->tableWidget->setColumnCount(columnCount);

    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);

    QStringList headers;
    headers << "Имя" << "Фамилия" << "Отчество" << "Предмет" << "Время" << "Кабинет";
    ui->tableWidget->setHorizontalHeaderLabels(headers);

    QDate selectedDate = ui->dateEditForm->date();
    QString selectedDateString = selectedDate.toString("yyyy-MM-dd");

    QSqlQuery query;
    query.prepare("SELECT * FROM teachers_db WHERE date_s = :selectedDate");
    query.bindValue(":selectedDate", selectedDateString);

    if (!query.exec()) {
        qDebug() << "gg" << query.lastError().text();
        return;
    }


    int row = 0;

    while (query.next()) {
        QString firstName = query.value(0).toString();
        QString lastName = query.value(1).toString();
        QString surName = query.value(2).toString();
        QString subject = query.value(3).toString();
        QString timeString = query.value(4).toString();
        int cabinet = query.value(5).toInt();

        ui->tableWidget->insertRow(row);
        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(firstName));
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(lastName));
        ui->tableWidget->setItem(row, 2, new QTableWidgetItem(surName));
        ui->tableWidget->setItem(row, 3, new QTableWidgetItem(subject));
        ui->tableWidget->setItem(row, 4, new QTableWidgetItem(timeString));
        ui->tableWidget->setItem(row, 5, new QTableWidgetItem(QString::number(cabinet)));

        ++row;
    }

    if (row > 0) {
        ui->label_3->hide();
        ui->tableWidget->show();
    } else {
        ui->label_3->setText("На выбранную дату экзаменов нет");
        ui->label_3->show();
        ui->tableWidget->hide();
    }
}




void View_form::on_pushButton_exit_clicked()
{
    ui->tableWidget->hide();
    ui->label_3->clear();
    ui->label_3->show();
}

