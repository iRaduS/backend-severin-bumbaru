#include <QtCore>
#include <TreeFrogView>
#include "applicationhelper.h"
#include "uservalidator.h"

class T_VIEW_EXPORT account_loginView : public TActionView
{
  Q_OBJECT
public:
  account_loginView() : TActionView() { }
  QString toString();
};

QString account_loginView::toString()
{
  responsebody.reserve(2089);
  responsebody += QStringLiteral("<div class=\"columns is-vcentered is-gapless is-paddingless is-marginless\">\n  <div class=\"column is-6 is-fullheight column__fullheight is-flex is-align-content-center is-justify-content-center\">\n    <section class=\"section container\">\n      <h1 class=\"title has-text-centered\">CWL</h1>\n      <h2 class=\"subtitle has-text-centered\">Login into your account</h2>\n\n      <div class=\"notification is-danger\">\n        ");
  tehex(message);
  responsebody += QStringLiteral("\n      </div>\n\n      ");
  responsebody += QVariant(formTag(urla("login"), Tf::Post)).toString();
  responsebody += QStringLiteral("\n        <div class=\"field\">\n          <label class=\"label\">Username</label>\n          <div class=\"control has-icons-right\">\n            <input class=\"input\" name=\"username\" type=\"text\" autocomplete=\"off\">\n            <span class=\"icon is-small is-right\">\n                  <i class=\"fa fa-user\"></i>\n                </span>\n          </div>\n        </div>\n\n        <div class=\"field\">\n          <label class=\"label\">Password</label>\n          <div class=\"control has-icons-right\">\n            <input class=\"input\" name=\"password\" type=\"password\" autocomplete=\"off\">\n            <span class=\"icon is-small is-right\">\n                  <i class=\"fa fa-key\"></i>\n                </span>\n          </div>\n        </div>\n\n        <div class=\"has-text-centered\">\n          <button type=\"submit\" class=\"button is-vcentered is-info is-outlined is-fullwidth\">Login</button>\n        </div>\n      </form>\n    </section>\n  </div>\n  <div id=\"particles-js\" class=\"column is-6 is-fullheight column__fullheight has-background-info\">\n    <a class=\"mx-2 my-2 button is-small is-white is-outlined\" href=\"");
  responsebody += QVariant(urla("showRegister")).toString();
  responsebody += QStringLiteral("\">I don't have an account. Go register! <i class=\"fas fa-user\"></i></a>\n  </div>\n</div>\n<script src=\"/js/particles.js\" type=\"application/javascript\"></script>");

  return responsebody;
}

T_DEFINE_VIEW(account_loginView)

#include "account_loginView.moc"
