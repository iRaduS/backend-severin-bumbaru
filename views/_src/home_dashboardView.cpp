#include <QtCore>
#include <TreeFrogView>
#include "user.h"
#include "applicationhelper.h"
#include "uservalidator.h"

class T_VIEW_EXPORT home_dashboardView : public TActionView
{
  Q_OBJECT
public:
  home_dashboardView() : TActionView() { }
  QString toString();
};

QString home_dashboardView::toString()
{
  responsebody.reserve(2872);
    tfetch(User, user);
  responsebody += QStringLiteral("<section class=\"hero is-link is-small is-bold\">\n  <div class=\"hero-body\">\n    <div class=\"container\">\n      <h1 class=\"title\">\n        ");
  responsebody += THttpUtility::htmlEscape(user.name());
  responsebody += QStringLiteral("\n        <small class=\"has-text-light\">");
  responsebody += THttpUtility::htmlEscape(user.username());
  responsebody += QStringLiteral("</small>\n        ");
  if (user.isElonMusk()) {
  responsebody += QStringLiteral("        <img src=\"/images/elon.gif\" height=\"32px\" />\n        ");
  } if (user.isFire()) {
  responsebody += QStringLiteral("        <img src=\"/images/fire.gif\" height=\"32px\" />\n        ");
  };
  responsebody += QStringLiteral("      </h1>\n      <h2 class=\"subtitle\"> <cite>Every child borns as a genius</cite> <strong>Albert Einstein</strong></h2>\n    </div>\n  </div>\n</section>\n\n<section class=\"tiles--info mt-3\">\n  <div class=\"tile is-ancestor has-text-centered\">\n    <div class=\"tile is-parent\">\n      <article class=\"tile is-child box\">\n        <p class=\"title\">\n          ");
  if (user.credits() <= 2800) {
  responsebody += QStringLiteral("            <span class=\"tag is-light\">Beginner</span>\n          ");
  } else if (user.credits() <= 6600) {
  responsebody += QStringLiteral("            <span class=\"tag is-success\">Novice</span>\n          ");
  } else if (user.credits() <= 10000) {
  responsebody += QStringLiteral("            <span class=\"tag is-warning\"><i class=\"fas fa-star\"></i> Professional</span>\n          ");
  } else if (user.credits() <= 13500) {
  responsebody += QStringLiteral("            <span class=\"tag is-link\"><i class=\"fas fa-star\"></i> Expert</span>\n          ");
  } else if (user.credits() <= 16600) {
  responsebody += QStringLiteral("            <span class=\"tag is-danger\"><i class=\"fas fa-star\"></i> Master</span>\n          ");
  } else if (user.credits() <= 22000) {
  responsebody += QStringLiteral("            <span class=\"tag is-black\"><i class=\"fas fa-star\"></i> Elite</span>\n          ");
  };
  responsebody += QStringLiteral("        </p>\n        <p class=\"subtitle\">Your rank</p>\n      </article>\n    </div>\n    <div class=\"tile is-parent\">\n      <article class=\"tile is-child box\">\n        <p class=\"title\">");
  responsebody += THttpUtility::htmlEscape(user.credits());
  responsebody += QStringLiteral("</p>\n        <p class=\"subtitle\">Credits</p>\n      </article>\n    </div>\n    <div class=\"tile is-parent\">\n      <article class=\"tile is-child box\">\n        <p class=\"title\">");
  responsebody += THttpUtility::htmlEscape(user.fiftyFifty() + user.hintGuesser());
  responsebody += QStringLiteral("</p>\n        <p class=\"subtitle\">Products</p>\n      </article>\n    </div>\n  </div>\n</section>");

  return responsebody;
}

T_DEFINE_VIEW(home_dashboardView)

#include "home_dashboardView.moc"
