#include "schedule.h"
#include "view_form.h"
#include "ui_schedule.h"
#include "ui_view_form.h"
#include "iostream"
using namespace std;


Schedule::Schedule(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Schedule)
{
    ui->setupUi(this);
    ui->dateEdit->setDate(QDate::currentDate());
    connect(ui->dateEdit, SIGNAL(dateChanged(QDate)), this, SLOT(onDateEditChanged(QDate)));
    connect(ui->decreaseButton, SIGNAL(clicked()), this, SLOT(decreaseDateByOneMonth()));
    connect(ui->dateEdit, SIGNAL(editingFinished()), this, SLOT(onDateEditEditingFinished()));
    connect(ui->decreaseButton4Days, SIGNAL(clicked()), this, SLOT(decreaseDateByFourDays()));
    ui->calendarWidget->setSelectionMode(QCalendarWidget::NoSelection);
    connect(ui->dateEdit, &QDateEdit::dateChanged, this, &Schedule::updateSelectedDate);



}

Schedule::~Schedule()
{
    delete ui;
}

void Schedule::updateViewFormDate(QDate newDate) {
    view_form.ui->dateEditForm->setDate(newDate);
}

void Schedule::onDateEditEditingFinished() {
    QDate newDate = ui->dateEdit->date();
    emit dateChanged(newDate);
    updateViewFormDate(newDate);
}
void Schedule::onDateEditChanged(const QDate &date) {
    ui->calendarWidget->setSelectedDate(date);
}
void Schedule::decreaseDateByOneMonth() {
    QDate currentDate = ui->dateEdit->date();
    currentDate = currentDate.addMonths(+1);
    ui->dateEdit->setDate(currentDate);
    emit dateChanged(currentDate);
    updateViewFormDate(currentDate);
}
void Schedule::decreaseDateByFourDays() {
    QDate currentDate = ui->dateEdit->date();
    currentDate = currentDate.addDays(-4);
    ui->dateEdit->setDate(currentDate);
    emit dateChanged(currentDate);
    updateViewFormDate(currentDate);
}

void Schedule::on_pushButton_1_clicked()
{
    view_form.show();
    view_form.setWindowTitle("Schedule");
}


void Schedule::on_pushButton_2_clicked()
{
    add_form.show();
    add_form.setWindowTitle("Schedule");

}

void Schedule::updateDateEdits(QDate newDate) {
    ui->dateEdit->setDate(newDate);
    view_form.ui->dateEditForm->setDate(newDate);
}


void Schedule::updateSelectedDate(const QDate &newDate) {
    selectedDate = newDate;
}

void Schedule::ViewFormM() {
    view_form.on_pushButton_view_clicked();
}














