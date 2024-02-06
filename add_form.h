#ifndef ADD_FORM_H
#define ADD_FORM_H

#include <QWidget>
#include "QDebug"
#include <QtSql>


namespace Ui {
class Add_form;
}

class Add_form : public QWidget
{
    Q_OBJECT

public:
    explicit Add_form(QWidget *parent = nullptr);
    ~Add_form();




private slots:
    void on_pushButton_add_clicked();

private:
    Ui::Add_form *ui;
};

#endif
