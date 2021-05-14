#include "quizcontroller.h"
#include "quiz.h"
#include "group.h"
#include "user.h"
#include "tdebug.h"
#include "creditlog.h"
#include "tsqlormapper.h"
#include "sqlobjects/userobject.h"
#include "userquiz.h"

void QuizController::remove(const QString &group_id, const QString &id) {
    if (httpRequest().method() != Tf::Delete) {
        renderErrorResponse(Tf::NotFound);
        return;
    }

    auto quiz = Quiz::get(id.toInt());
    quiz.remove();
    redirect(url("group", "show", group_id.toInt()));
}

void QuizController::show(const QString &group_id, const QString &id) {
    auto user = User::getByIdentityKey(this->identityKeyOfLoginUser());
    int userId = user.id();
    int fiftyFifty = user.fiftyFifty();
    int hintGuesser = user.hintGuesser(); 
    auto group = Group::get(group_id.toInt());
    auto quiz = Quiz::get(id.toInt());

    QString quizes;
    quizes += "{\"id\": \"";
    quizes += QString::number(quiz.id()); 
    quizes += "\", \"name\": \"";
    quizes += quiz.name(); 
    quizes += "\", \"details\":";
    quizes += quiz.details(); 
    quizes += "}";

    texport(fiftyFifty);
    texport(hintGuesser);
    texport(userId);
    texport(group);
    texport(quizes);
    render("show", "quiz");
}

void QuizController::user(const QString &id) {
    if (httpRequest().method() != Tf::Post) {
        renderErrorResponse(Tf::NotFound);
        return;
    }

    QString fifty = httpRequest().formItemValue("fifty");
    QString hint = httpRequest().formItemValue("hint");

    TSqlORMapper<UserObject> mapper;
    UserObject user = mapper.findByPrimaryKey(id.toInt());
    user.fiftyFifty = fifty.toInt();
    user.hintGuesser = hint.toInt();
    user.update();
}

void QuizController::finish(const QString &quiz_id, const QString &id) {
    if (httpRequest().method() != Tf::Post) {
        renderErrorResponse(Tf::NotFound);
        return;
    }

    QString fifty = httpRequest().formItemValue("fifty");
    QString hint = httpRequest().formItemValue("hint");
    QString coins = httpRequest().formItemValue("coins");

    TSqlORMapper<UserObject> mapper;
    UserObject user = mapper.findByPrimaryKey(id.toInt());
    user.credits = user.credits + coins.toInt();
    user.fiftyFifty = fifty.toInt();
    user.hintGuesser = hint.toInt();
    user.update();

    CreditLog::create(id.toInt(), coins.toInt(), "Finished a quiz");
    UserQuiz::create(id.toInt(), quiz_id.toInt());
}

void QuizController::create(const QString &id) {
    switch (httpRequest().method()) {
    case Tf::Get:
        texport(id);
        render("create", "dashboard");
        break;

    case Tf::Post: {
        auto name = httpRequest().formItemValue("title");
        auto details = httpRequest().formItemValue("content");
        
        QVariantMap inserter;

        inserter["groupId"] = QVariant(id.toInt());
        inserter["name"] = QVariant(name);
        inserter["details"] = QVariant(details);
        
        auto insert = Quiz::create(inserter);
        redirect(url("group", "show", id.toInt()));
        break;
    }

    default:
        renderErrorResponse(Tf::NotFound);
        break;
    }
}

// Don't remove below this line
T_DEFINE_CONTROLLER(QuizController)
