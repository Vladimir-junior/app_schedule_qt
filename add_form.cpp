#include "add_form.h"
#include "ui_add_form.h"


static QSqlDatabase db;

Add_form::Add_form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Add_form)
{
    ui->setupUi(this);


    if (!db.isValid() || !db.isOpen()) {
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("teachers.sqlite");

        if (!db.open()) {
            qDebug() << "Ошибка при открытии базы данных: " << db.lastError().text();
        }

        QSqlQuery query(db);
        query.prepare("CREATE TABLE IF NOT EXISTS teachers_db (first_name TEXT NOT NULL, last_name TEXT NOT NULL, sur_name TEXT NOT NULL, subject TEXT NOT NULL, time_s TEXT NOT NULL, cabinet INTEGER NOT NULL, date_s TEXT NOT NULL)");
        query.exec();
    }


}

Add_form::~Add_form()
{
    delete ui;
}



void Add_form::on_pushButton_add_clicked()
{
    QString first_name = ui->lineEdit->text();
    QString last_name = ui->lineEdit_2->text();
    QString sur_name = ui->lineEdit_3->text();
    QString subject = ui->comboBox->currentText();
    QTime time_s = ui->timeEdit->time();
    int cabinet = ui->spinBox->value();
    QDate date_s = ui->dateEdit->date();


    QSqlQuery query(db);
    query.prepare("INSERT INTO teachers_db (first_name, last_name, sur_name, subject, time_s, cabinet, date_s) "
                  "VALUES (:first_name, :last_name, :sur_name, :subject, :time_s, :cabinet, :date_s)");
    query.bindValue(":first_name", first_name);
    query.bindValue(":last_name", last_name);
    query.bindValue(":sur_name", sur_name);
    query.bindValue(":subject", subject);
    query.bindValue(":time_s", time_s.toString("hh:mm:ss"));
    query.bindValue(":cabinet", cabinet);
    query.bindValue(":date_s", date_s.toString("yyyy-MM-dd"));

    if (query.exec()) {
        qDebug() << "Данные успешно добавлены в базу данных!";
    } else {
        qDebug() << "Ошибка при добавлении данных: " << query.lastError().text();
    }
}

