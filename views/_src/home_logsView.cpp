#include <QtCore>
#include <TreeFrogView>
#include "applicationhelper.h"
#include "uservalidator.h"

class T_VIEW_EXPORT home_logsView : public TActionView
{
  Q_OBJECT
public:
  home_logsView() : TActionView() { }
  QString toString();
};

QString home_logsView::toString()
{
  responsebody.reserve(1145);
  responsebody += QStringLiteral("<h1 class=\"title\">Credit Logs</h1>\n");
  tfetch(QList<QVariantMap>, result);
  responsebody += QStringLiteral("<div class=\"container\">\n  ");
  for (int i = 0; i < result.size(); ++i) {
  responsebody += QStringLiteral("  <div class=\"mt-3\">\n    <div class=\"card has-text-centered\">\n      <div class=\"card-content\">\n        ");
  responsebody += THttpUtility::htmlEscape(result.at(i)["action"]);
  responsebody += QStringLiteral("\n        which has a cost of\n        ");
  if (result.at(i)["credits"].toInt() >= 0) {
  responsebody += QStringLiteral("          <span class=\"tag is-success\">");
  responsebody += THttpUtility::htmlEscape(result.at(i)["credits"].toInt());
  responsebody += QStringLiteral(" Credits</span>\n        ");
  } else {
  responsebody += QStringLiteral("          <span class=\"tag is-danger\">");
  responsebody += THttpUtility::htmlEscape(-result.at(i)["credits"].toInt());
  responsebody += QStringLiteral(" Credits</span>\n        ");
  };
  responsebody += QStringLiteral("      </div>\n    </div>\n  </div>\n  ");
  };
  responsebody += QStringLiteral("</div>");

  return responsebody;
}

T_DEFINE_VIEW(home_logsView)

#include "home_logsView.moc"
