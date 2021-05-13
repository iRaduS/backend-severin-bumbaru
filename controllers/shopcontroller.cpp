#include "shopcontroller.h"
#include "user.h"
#include "tsqlormapper.h"
#include "sqlobjects/userobject.h"

void ShopController::buyItem(const QString &id) {
    if (httpRequest().method() != Tf::Post) {
        renderErrorResponse(Tf::NotFound);
        return;
    }

    auto user = User::getByIdentityKey(this->identityKeyOfLoginUser());
    int prices[] = {350, 30, 30, 1000};

    if (user.credits() < prices[id.toInt() - 1]) {
        QString notice = "Not enough credits.";
        tflash(notice);
        redirect(urla("index"));
        return;
    }
    TSqlORMapper<UserObject> mapper;
    UserObject usr_obj = mapper.findByPrimaryKey(user.id());
    usr_obj.credits = usr_obj.credits - prices[id.toInt() - 1];
    switch (id.toInt()) {
        case 1: {
            usr_obj.isFire = 1;
            break;
        }
        case 2: {
            usr_obj.fiftyFifty += 1;
            break;
        }
        case 3: {
            usr_obj.hintGuesser += 1;
            break;
        }
        case 4: {
            usr_obj.isElonMusk = 1;
            break;
        }
    }
    usr_obj.update();

    redirect(urla("index"));
}

void ShopController::index()
{
    auto user = User::getByIdentityKey(this->identityKeyOfLoginUser());
    texport(user);
    render("index", "dashboard");
}

// Don't remove below this line
T_DEFINE_CONTROLLER(ShopController)
