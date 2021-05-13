#ifndef HOMECONTROLLER_H
#define HOMECONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT HomeController : public ApplicationController
{
    Q_OBJECT
public:
    HomeController() : ApplicationController() { }

public slots:
    void index();
    void dashboard();
    void leaderboard();
    void creditLogs();
};

#endif // HOMECONTROLLER_H
