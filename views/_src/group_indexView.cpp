#include <QtCore>
#include <TreeFrogView>
#include "applicationhelper.h"
#include "uservalidator.h"

class T_VIEW_EXPORT group_indexView : public TActionView
{
  Q_OBJECT
public:
  group_indexView() : TActionView() { }
  QString toString();
};

QString group_indexView::toString()
{
  responsebody.reserve(2804);
  responsebody += QStringLiteral("<h1 class=\"title\">Enter Group</h1>\n");
  responsebody += QVariant(formTag(urla("join"), Tf::Post, true, a("class", "box"))).toString();
  responsebody += QStringLiteral("\n  <div class=\"field\">\n    <label class=\"label\">Group code</label>\n    <div class=\"control\">\n      <input class=\"input\" type=\"text\" name=\"invite\" placeholder=\"e.g. dzcadav\" />\n    </div>\n  </div>\n  <button class=\"button is-link\" type=\"submit\">Enter code</button>\n</form>\n\n<h1 class=\"title\">Listing Group</h1>\n<div class=\"box is-flex is-justify-content-center is-align-items-center\">\n  <table class=\"table is-fullwidth\">\n    <thead>\n      <tr>\n        <th><abbr title=\"Group name\">Group name</abbr></th>\n        <th><abbr title=\"Users in group\">Users in group</abbr></th>\n        <th><abbr title=\"Role in group\">Role in group</abbr></th>\n        <th><abbr title=\"Options\">Options</abbr></th>\n      </tr>\n    </thead>\n    ");
  tfetch(QList<QVariantMap>, groupList);
  responsebody += QStringLiteral("    ");
  for (const auto &i : groupList) {
  responsebody += QStringLiteral("      <tr>\n        <th>");
  responsebody += THttpUtility::htmlEscape(i["name"]);
  responsebody += QStringLiteral("</th>\n        <td>\n          ");
  responsebody += THttpUtility::htmlEscape(i["count"]);
  responsebody += QStringLiteral("\n        </td>\n        <td>\n          <span class=\"tag ");
  responsebody += THttpUtility::htmlEscape(i["role"] == 2 ? "is-warning" : "is-dark");
  responsebody += QStringLiteral("\">\n            ");
  responsebody += THttpUtility::htmlEscape(i["role"] == 2 ? "Teacher" : "Student");
  responsebody += QStringLiteral("\n          </span>\n        </td>\n        \n        <td>\n          ");
  responsebody += QVariant(linkTo("Quizzes", urla("show", i["id"]), a("class", "button is-link is-small"))).toString();
  responsebody += QStringLiteral("\n          ");
  if (i["role"] == 2) {
  responsebody += QStringLiteral("          ");
  responsebody += QVariant(linkTo("Edit", urla("save", i["id"]), a("class", "button is-info is-small"))).toString();
  responsebody += QStringLiteral("\n          ");
  responsebody += QVariant(linkTo("Remove", urla("remove", i["id"]), Tf::Post, "confirm('Are you sure?')", a("class", "button is-danger is-small"))).toString();
  responsebody += QStringLiteral("\n          ");
  } else {
  responsebody += QStringLiteral("          ");
  responsebody += QVariant(linkTo("Leave", urla("leave", i["guid"]), Tf::Post, "confirm('Are you sure?')", a("class", "button is-danger is-small"))).toString();
  responsebody += QStringLiteral("\n          ");
  };
  responsebody += QStringLiteral("        </td>\n      </tr>\n    ");
  };
  responsebody += QStringLiteral("  </table>\n</div>\n");

  return responsebody;
}

T_DEFINE_VIEW(group_indexView)

#include "group_indexView.moc"
