#ifndef SHOPCONTROLLER_H
#define SHOPCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT ShopController : public ApplicationController
{
    Q_OBJECT
public:
    ShopController() : ApplicationController() { }

public slots:
    void buyItem(const QString &id);
    void index();
};

#endif // SHOPCONTROLLER_H
