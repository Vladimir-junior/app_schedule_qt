#ifndef TEACHERS_H
#define TEACHERS_H
#include "schedule.h"

class Teachers : public Schedule
{
public:
    Teachers();
    ~Teachers();
    void get_info();
    QString first_name;
    QString last_name;
    QString sur_name;
    QDate date_s;
};

#endif
