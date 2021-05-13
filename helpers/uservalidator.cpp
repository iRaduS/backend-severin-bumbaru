#include "uservalidator.h"

UserValidator::UserValidator() : TFormValidator()
{
    setRule("name", Tf::MinLength, 4);
    setRule("name", Tf::Required, true);
    setRule("name", Tf::MaxLength, 32);

    setRule("username", Tf::Required, true);
    setRule("username", Tf::MinLength, 4);
    setRule("username", Tf::MaxLength, 32);

    setRule("email", Tf::EmailAddress, true);
    setRule("required", Tf::Required, true);

    setRule("password", Tf::Required, true);
    setRule("password", Tf::MinLength, 4);
    setRule("password", Tf::MaxLength, 64);
}
