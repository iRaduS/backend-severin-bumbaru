#include <QtCore>
#include <TreeFrogView>
#include "user.h"
#include "applicationhelper.h"
#include "uservalidator.h"

class T_VIEW_EXPORT partial_navbarView : public TActionView
{
  Q_OBJECT
public:
  partial_navbarView() : TActionView() { }
  QString toString();
};

QString partial_navbarView::toString()
{
  responsebody.reserve(2284);
    responsebody += QStringLiteral("<nav class=\"navbar is-info\" role=\"navigation\" aria-label=\"main navigation\">\n  <div class=\"navbar-brand\">\n    <a class=\"navbar-item\" href=\"");
  responsebody += QVariant(QUrl("/")).toString();
  responsebody += QStringLiteral("\">\n      <span>\n        <i class=\"has-text-white fas fa-user-edit\"></i> <strong class=\"has-text-white\">CWL</strong>\n      </span>\n    </a>\n\n    <a role=\"button\" class=\"navbar-burger\" aria-label=\"menu\" aria-expanded=\"false\" data-target=\"navbarBasic\">\n      <span aria-hidden=\"true\"></span>\n      <span aria-hidden=\"true\"></span>\n      <span aria-hidden=\"true\"></span>\n    </a>\n  </div>\n\n  <div id=\"navbarBasic\" class=\"navbar-menu\">\n    ");
  if (controller()->isUserLoggedIn() == true) {
       auto user = User::getByIdentityKey(controller()->identityKeyOfLoginUser());
  responsebody += QStringLiteral("    <div class=\"navbar-start\">\n      <div class=\"navbar-item\">\n        <a class=\"button is-outlined is-white is-small\" href=\"");
  responsebody += QVariant(url("home", "dashboard")).toString();
  responsebody += QStringLiteral("\">\n          <span>Dashboard, ");
  responsebody += QVariant(user.name()).toString();
  responsebody += QStringLiteral(" <i class=\"fas fa-arrow-right\"></i></span>\n        </a>\n      </div>\n      <a class=\"navbar-item\" href=\"");
  responsebody += QVariant(url("account", "logout")).toString();
  responsebody += QStringLiteral("\">\n        Logout\n      </a>\n    </div>\n    ");
  } else {
  responsebody += QStringLiteral("    <div class=\"navbar-end\">\n      <div class=\"navbar-item\">\n        <div class=\"buttons\">\n          <a class=\"button is-white is-small\" href=\"");
  responsebody += QVariant(url("account", "showRegister")).toString();
  responsebody += QStringLiteral("\">\n            <span><strong>Register</strong> <i class=\"fas fa-user-plus\"></i></span>\n          </a>\n          <a class=\"button is-outlined is-white is-small\" href=\"");
  responsebody += QVariant(url("account", "showLogin")).toString();
  responsebody += QStringLiteral("\">\n            Login\n          </a>\n        </div>\n      </div>\n    </div>\n    ");
  };
  responsebody += QStringLiteral("  </div>\n</nav>");

  return responsebody;
}

T_DEFINE_VIEW(partial_navbarView)

#include "partial_navbarView.moc"
