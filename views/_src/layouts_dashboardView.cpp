#include <QtCore>
#include <TreeFrogView>
#include "applicationhelper.h"
#include "uservalidator.h"

class T_VIEW_EXPORT layouts_dashboardView : public TActionView
{
  Q_OBJECT
public:
  layouts_dashboardView() : TActionView() { }
  QString toString();
};

QString layouts_dashboardView::toString()
{
  responsebody.reserve(3074);
  responsebody += QStringLiteral("<!DOCTYPE html>\n<html lang=\"en\">\n<head>\n  <meta charset=\"UTF-8\">\n  <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n  <meta name=\"keywords\" content=\"educational, multi-purpose, real-time\">\n  <meta name=\"description\" content=\"CWL\">\n  <title>CWL</title>\n\n  <meta property=\"og:type\" content=\"website\">\n  <meta property=\"og:url\" content=\"\">\n  <meta property=\"og:title\" content=\"CWL\">\n  <meta property=\"og:description\" content=\"Educational site with entertaining content.\">\n  <meta property=\"og:image\" content=\"\">\n\n  <meta property=\"twitter:card\" content=\"summary_large_image\">\n  <meta property=\"twitter:url\" content=\"\">\n  <meta property=\"twitter:title\" content=\"CWL\">\n  <meta property=\"twitter:description\" content=\"Educational site with entertaining content.\">\n  <meta property=\"twitter:image\" content=\"\">\n\n  <script src=\"/js/bulma.js\" defer></script>\n  <script src=\"/js/main.js\" defer></script>\n\n\n  <link rel=\"dns-prefetch\" href=\"//fonts.gstatic.com\">\n  <link href=\"https://fonts.googleapis.com/css2?family=PT+Sans:ital,wght@0,400;0,700;1,400;1,700&display=swap\" rel=\"stylesheet\">\n  <link href=\"/css/bulma.min.css\" rel=\"stylesheet\">\n  <link href=\"/css/all.min.css\" rel=\"stylesheet\">\n  <link href=\"/css/custom.css\" rel=\"stylesheet\">\n</head>\n<body>\n  ");
  responsebody += QVariant(renderPartial("navbar")).toString();
  responsebody += QStringLiteral("\n  <div class=\"hero is-light is-fullheight\">\n    <div class=\"p-6 m-6\">\n      <div class=\"columns\">\n        <div class=\"column is-2\">\n          <aside class=\"menu is-hidden-mobile\">\n            <a class=\"button is-link is-rounded is-small\" href=\"");
  responsebody += QVariant(url("group", "create")).toString();
  responsebody += QStringLiteral("\">\n            <span>Create a new group <i class=\"fas fa-plus\"></i></span>\n            </a>\n            <p class=\"menu-label\">\n              General\n            </p>\n            <ul class=\"menu-list\">\n              <li><a href=\"");
  responsebody += QVariant(url("group", "index")).toString();
  responsebody += QStringLiteral("\">Groups</a></li>\n              <li><a href=\"");
  responsebody += QVariant(url("home", "leaderboard")).toString();
  responsebody += QStringLiteral("\">Leaderboard</a></li>\n              <li><a href=\"");
  responsebody += QVariant(url("shop", "index")).toString();
  responsebody += QStringLiteral("\">Shop</a></li>\n              <li><a href=\"");
  responsebody += QVariant(url("home", "creditLogs")).toString();
  responsebody += QStringLiteral("\">Credit Logs</a></li>\n            </ul>\n          </aside>\n        </div>\n        <div class=\"column is-10\">\n          ");
  responsebody += QVariant(yield()).toString();
  responsebody += QStringLiteral("\n        </div>\n      </div>\n    </div>\n  </div>\n  ");
  responsebody += QVariant(renderPartial("footer")).toString();
  responsebody += QStringLiteral("\n</body>\n</html>");

  return responsebody;
}

T_DEFINE_VIEW(layouts_dashboardView)

#include "layouts_dashboardView.moc"
