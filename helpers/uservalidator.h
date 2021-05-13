#ifndef USERVALIDATOR_H
#define USERVALIDATOR_H

#include <TGlobal>
#include <TFormValidator>

class T_HELPER_EXPORT UserValidator : public TFormValidator
{
public:
    UserValidator();
};

Q_DECLARE_METATYPE(UserValidator)

#endif // USERVALIDATOR_H
