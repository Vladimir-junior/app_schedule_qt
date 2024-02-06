#ifndef VIEW_FORM_H
#define VIEW_FORM_H
#include <QDateEdit>

#include <QWidget>
#include <QtSql>



namespace Ui {
class View_form;
}

class View_form : public QWidget
{
    Q_OBJECT

public:
    explicit View_form(QWidget *parent = nullptr);
    ~View_form();
    Ui::View_form *ui;



public slots:
    void on_pushButton_view_clicked();
    void on_pushButton_exit_clicked();

private:


};

#endif // VIEW_FORM_H
