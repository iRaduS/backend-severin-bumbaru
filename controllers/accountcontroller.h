#ifndef ACCOUNTCONTROLLER_H
#define ACCOUNTCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT AccountController : public ApplicationController
{
    Q_OBJECT
public:
    AccountController() : ApplicationController() { }

public slots:
    void showRegister();
    void showLogin();
    void login();
    void registration();
    void logout();

protected:
    virtual bool preFilter();
};

#endif // ACCOUNTCONTROLLER_H
