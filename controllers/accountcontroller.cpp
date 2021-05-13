#include "accountcontroller.h"
#include "uservalidator.h"
#include "user.h"
#include "tcryptmac.h"

bool AccountController::preFilter() {
    if (isUserLoggedIn() && this->activeAction() != "logout") {
        redirect(url("home", "dashboard"));
        return false;
    } else if (!isUserLoggedIn() && this->activeAction() == "logout") {
        redirect(url("account", "showLogin"));
        return false;
    }

    return true;
}

void AccountController::showRegister() {
    render("register", "auth");
}

void AccountController::showLogin() {
    render("login", "auth");
}

void AccountController::login() {
    QString username = httpRequest().formItemValue("username");
    QString password = httpRequest().formItemValue("password");

    User user = User::authenticate(username, password);
    if (!user.isNull()) {
        userLogin(&user);
        redirect(url("home", "dashboard"));
    } else {
        QString message = "Incorrect login attempt, check your credentials!";
        tflash(message);
        redirect(urla("showLogin"));
    }

}

void AccountController::registration() {
    auto data = httpRequest().formItems("register");
    UserValidator validator;

    if (!validator.validate(data)) {
        QStringList errors = validator.errorMessages();
    } else {
        auto model = User::create(data);

        if (!model.isNull()) {
            QString message = "Now that you've registered, login into your account!";
            tflash(message);
            redirect(urla("showLogin"));
        } else {
            QString message = "Failed to create, please check if the data is valid.";
            tflash(message);
            redirect(urla("showRegister"));
        }
    }
}

void AccountController::logout() {
    userLogout();
    redirect(urla("showLogin"));
}

// Don't remove below this line
T_DEFINE_CONTROLLER(AccountController)
