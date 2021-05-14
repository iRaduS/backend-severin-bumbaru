#include <QtCore>
#include <TreeFrogView>
#include "group.h" 
#include "applicationhelper.h"
#include "uservalidator.h"

class T_VIEW_EXPORT group_saveView : public TActionView
{
  Q_OBJECT
public:
  group_saveView() : TActionView() { }
  QString toString();
};

QString group_saveView::toString()
{
  responsebody.reserve(2945);
    tfetch(QVariantMap, group);
  responsebody += QStringLiteral("<h1 class=\"title\">Show Group Informations</h1>\n");
  responsebody += QVariant(formTag(urla("save", group["id"]), Tf::Post, true, a("class", "box"))).toString();
  responsebody += QStringLiteral("\n  <div class=\"field\">\n    <label class=\"label\">Group name</label>\n    <div class=\"control\">\n      <input class=\"input\" type=\"text\" name=\"group[name]\" value=\"");
  responsebody += THttpUtility::htmlEscape(group["name"]);
  responsebody += QStringLiteral("\" placeholder=\"e.g. Elon Musk's groups\" />\n    </div>\n  </div>\n  <div class=\"field\">\n    <label class=\"label\">Invite link</label>\n    <div class=\"control is-flex\">\n      <input id=\"invite\" class=\"input\" type=\"text\" name=\"group[invite]\" value=\"");
  responsebody += THttpUtility::htmlEscape(group["invite"]);
  responsebody += QStringLiteral("\" placeholder=\"DEFAULT_INVITE\" />\n      <a class=\"button is-warning is-selected\" onclick=\"document.getElementById('invite').value = Math.random().toString(36).replace(/[^a-z]+/g, '');\"><i class=\"fas fa-sync-alt\"></i></a>\n    </div>\n  </div>\n  <button class=\"button is-link\" type=\"submit\">Submit</button>\n</form>\n");
  tfetch(QList<QVariantMap>, memberList);
  responsebody += QStringLiteral("<h1 class=\"title\">Listing Members</h1>\n<div class=\"box is-flex is-justify-content-center is-align-items-center\">\n  <table class=\"table is-fullwidth\">\n    <thead>\n      <tr>\n        <th><abbr title=\"Group name\">Username and name</abbr></th>\n        <th><abbr title=\"Role in group\">Role in group</abbr></th>\n        <th><abbr title=\"Options\">Options</abbr></th>\n      </tr>\n    </thead>\n    ");
  for (const auto &i : memberList) {
  responsebody += QStringLiteral("      <tr>\n        <th>\n          ");
  responsebody += THttpUtility::htmlEscape(i["name"]);
  responsebody += QStringLiteral("\n          <small class=\"has-text-gray\">");
  responsebody += THttpUtility::htmlEscape(i["username"]);
  responsebody += QStringLiteral("</small>\n        </th>\n        <td>\n          <span class=\"tag ");
  responsebody += THttpUtility::htmlEscape(i["role"] == 2 ? "is-warning" : "is-dark");
  responsebody += QStringLiteral("\">\n            ");
  responsebody += THttpUtility::htmlEscape(i["role"] == 2 ? "Teacher" : "Student");
  responsebody += QStringLiteral("\n          </span>\n        </td>\n        \n        <td>\n          ");
  if (i["role"] != 2) {
  responsebody += QStringLiteral("          ");
  responsebody += QVariant(linkTo("Kick", urla("kick", (QStringList() << i["uid"].toString() << group["id"].toString())), Tf::Post, "confirm('Are you sure?')", a("class", "button is-danger is-small"))).toString();
  responsebody += QStringLiteral("\n          ");
  };
  responsebody += QStringLiteral("        </td>\n      </tr>\n    ");
  };
  responsebody += QStringLiteral("  </table>\n</div>");

  return responsebody;
}

T_DEFINE_VIEW(group_saveView)

#include "group_saveView.moc"
