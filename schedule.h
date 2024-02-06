#ifndef SCHEDULE_H
#define SCHEDULE_H
#include <QDateEdit>
#include <QCalendarWidget>
#include <QMainWindow>
#include <add_form.h>
#include <view_form.h>
#include "QDebug"
#include "QLineEdit"



QT_BEGIN_NAMESPACE
namespace Ui { class Schedule; }
QT_END_NAMESPACE

class Schedule : public QMainWindow
{
    Q_OBJECT

public:
    Schedule(QWidget *parent = nullptr);
    ~Schedule();
    QDate selectedDate = QDate::currentDate();
    View_form view_form;
    Ui::Schedule *ui;

signals:
    void dateChanged(QDate newDate);
public slots:
    void updateDateEdits(QDate newDate);
    void onDateEditEditingFinished();
    void updateViewFormDate(QDate newDate);
    void updateSelectedDate(const QDate &newDate);
    void ViewFormM();
private slots:
    void onDateEditChanged(const QDate &date);
    void decreaseDateByOneMonth();
    void decreaseDateByFourDays();
    void on_pushButton_1_clicked();
    void on_pushButton_2_clicked();

private:
    Add_form add_form;




};
#endif
