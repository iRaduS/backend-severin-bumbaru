#include <QtCore>
#include <TreeFrogView>
#include "applicationhelper.h"
#include "uservalidator.h"

class T_VIEW_EXPORT home_leaderboardView : public TActionView
{
  Q_OBJECT
public:
  home_leaderboardView() : TActionView() { }
  QString toString();
};

QString home_leaderboardView::toString()
{
  responsebody.reserve(3993);
  responsebody += QStringLiteral("<h1 class=\"title\">Leaderboard</h1>\n");
  tfetch(QList<QVariantMap>, result);
  responsebody += QStringLiteral("<div class=\"container mt-6 is-fullhd\">\n  <div class=\"box\">\n    <div class=\"columns\">\n      <div class=\"column column--flex is-one-fifth\"></div>\n      <div class=\"column column--flex column-1 is-one-fifth\">\n        <div class=\"icon1 is-large fas fa-trophy\"></div>\n      </div>\n      <div class=\"column column--flex column-2 is-one-fifth\">\n        <div class=\"icon2 is-large fas fa-trophy\"></div>\n      </div>\n      <div class=\"column column--flex column-3 is-one-fifth\">\n        <div class=\"icon3 is-large fas fa-trophy\"></div>\n      </div>\n      <div class=\"column column--flex is-one-fifth\"></div>\n    </div>\n    <div class=\"columns\">\n      <div class=\"column column--flex is-one-fifth\"></div>\n      <div class=\"column column--flex column-1 is-one-fifth has-text-centered\">\n        ");
  if (result.size() >= 2) {
  responsebody += QStringLiteral("          <div class=\"mx-1\">");
  responsebody += THttpUtility::htmlEscape(result.at(1)["name"]);
  responsebody += QStringLiteral("</div>\n          <span class=\"tag is-warning\">");
  responsebody += THttpUtility::htmlEscape(result.at(1)["credits"]);
  responsebody += QStringLiteral("</span>\n        ");
  } else {
  responsebody += QStringLiteral("          <div>N/A</div>\n        ");
  };
  responsebody += QStringLiteral("      </div>\n      <div class=\"column column--flex column-2 is-one-fifth has-text-centered\">\n        ");
  if (result.size() >= 1) {
  responsebody += QStringLiteral("          <div class=\"mx-1\">");
  responsebody += THttpUtility::htmlEscape(result.at(0)["name"]);
  responsebody += QStringLiteral("</div>\n          <span class=\"tag is-warning\">");
  responsebody += THttpUtility::htmlEscape(result.at(0)["credits"]);
  responsebody += QStringLiteral("</span>\n        ");
  } else {
  responsebody += QStringLiteral("          <div>N/A</div>\n        ");
  };
  responsebody += QStringLiteral("      </div>\n      <div class=\"column column--flex column-3 is-one-fifth has-text-centered\">\n        ");
  if (result.size() >= 3) {
  responsebody += QStringLiteral("          <div class=\"mx-1\">");
  responsebody += THttpUtility::htmlEscape(result.at(2)["name"]);
  responsebody += QStringLiteral("</div>\n          <span class=\"tag is-warning\">");
  responsebody += THttpUtility::htmlEscape(result.at(2)["credits"]);
  responsebody += QStringLiteral("</span>\n        ");
  } else {
  responsebody += QStringLiteral("          <div>N/A</div>\n        ");
  };
  responsebody += QStringLiteral("      </div>\n      <div class=\"column column--flex is-one-fifth\"></div>\n    </div>\n  </div>\n  <div class=\"box is-flex is-justify-content-center is-align-items-center\">\n    <table class=\"table\">\n      <thead>\n        <tr>\n          <th><abbr title=\"#\">#</abbr></th>\n          <th><abbr title=\"Username & name\">Username & name</abbr></th>\n          <th><abbr title=\"Credits\">Credits</abbr></th>\n        </tr>\n      </thead>\n      <tbody>\n        ");
  for (int i = 3; i < result.size(); ++i) {
  responsebody += QStringLiteral("          <tr>\n            <th>");
  responsebody += THttpUtility::htmlEscape(i + 1);
  responsebody += QStringLiteral("</th>\n            <td>\n              ");
  responsebody += THttpUtility::htmlEscape(result.at(i)["name"]);
  responsebody += QStringLiteral(" <small class=\"has-text-link\">");
  responsebody += THttpUtility::htmlEscape(result.at(i)["username"]);
  responsebody += QStringLiteral("</small>\n            </td>\n            <td>\n              <span class=\"tag is-warning\">");
  responsebody += THttpUtility::htmlEscape(result.at(i)["credits"]);
  responsebody += QStringLiteral(" Credits</span>\n            </td>\n          </tr>\n        ");
  };
  responsebody += QStringLiteral("      </tbody>\n    </table>\n  </div>\n</div>");

  return responsebody;
}

T_DEFINE_VIEW(home_leaderboardView)

#include "home_leaderboardView.moc"
