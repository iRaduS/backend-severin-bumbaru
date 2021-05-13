#include "quizcontroller.h"
#include "quiz.h"
#include "tdebug.h"

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
