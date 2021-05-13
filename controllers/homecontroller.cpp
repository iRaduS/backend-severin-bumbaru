#include "homecontroller.h"
#include "sqlobjects/userobject.h"
#include "sqlobjects/creditlogobject.h"
#include "tsqlormapper.h"
#include "tsqlormapperiterator.h"
#include "user.h"
#include "creditlog.h"

void HomeController::index() {
    render(); // va afisa view-ul din home/index
}

void HomeController::dashboard() {
    auto user = User::getByIdentityKey(this->identityKeyOfLoginUser());
    texport(user);

    render("dashboard", "dashboard");
}

void HomeController::leaderboard() {
    TSqlORMapper<UserObject> user;
    user.orderBy("credits", Tf::DescendingOrder).find();
    QList<QVariantMap> result;

    for (TSqlORMapperIterator<UserObject> i(user); i.hasNext(); ) {
       result.push_back(User(i.next()).toVariantMap());
    }

    texport(result);
    render("leaderboard", "dashboard");
}

void HomeController::creditLogs() {
    int id = User::getByIdentityKey(this->identityKeyOfLoginUser()).id();
    TCriteria crt(CreditLogObject::UserId, id);
    TSqlORMapper<CreditLogObject> logs;
    
    logs.orderBy("id", Tf::DescendingOrder).find(crt);
    QList<QVariantMap> result;

    for (TSqlORMapperIterator<CreditLogObject> i(logs); i.hasNext(); ) {
        result.push_back(CreditLog(i.next()).toVariantMap());
    }

    texport(result);
    render("logs", "dashboard");
}

// Don't remove below this line
T_DEFINE_CONTROLLER(HomeController)
