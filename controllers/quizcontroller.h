#ifndef QUIZCONTROLLER_H
#define QUIZCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT QuizController : public ApplicationController
{
    Q_OBJECT
public:
    QuizController() : ApplicationController() { }

public slots:
    void finish(const QString &quiz_id, const QString &id);
    void user(const QString &id);
    void show(const QString &group_id, const QString &id);
    void remove(const QString &group_id, const QString &id);
    void create(const QString &id);
};

#endif // QUIZCONTROLLER_H
