#include <QtCore>
#include <TreeFrogView>
#include "group.h" 
#include "groupuser.h" 
#include "applicationhelper.h"
#include "uservalidator.h"

class T_VIEW_EXPORT group_showView : public TActionView
{
  Q_OBJECT
public:
  group_showView() : TActionView() { }
  QString toString();
};

QString group_showView::toString()
{
  responsebody.reserve(1000);
      tfetch(Group, group);
  tfetch(QString, quizes);
  tfetch(GroupUser, view);
  responsebody += QStringLiteral("<h1 class=\"title\">Create a new quiz for</h1>\n<h2 class=\"subtitle\">");
  responsebody += THttpUtility::htmlEscape(group.name());
  responsebody += QStringLiteral("</h2>\n");
  if (view.role() == 2) {
  responsebody += QStringLiteral("<a class=\"button is-link is-outline is-small\" href=\"");
  responsebody += QVariant(url("quiz", "create", group.id())).toString();
  responsebody += QStringLiteral("\">\n  <span>Create a new quiz <i class=\"fas fa-plus\"></i></span>\n</a>\n");
  };
  responsebody += QStringLiteral("<div id=\"list-quiz\" data-role=\"");
  responsebody += THttpUtility::htmlEscape(view.role());
  responsebody += QStringLiteral("\" data-groupid=\"");
  responsebody += THttpUtility::htmlEscape(group.id());
  responsebody += QStringLiteral("\" data-quiz=\"");
  responsebody += THttpUtility::htmlEscape(quizes);
  responsebody += QStringLiteral("\"></div>\n");

  return responsebody;
}

T_DEFINE_VIEW(group_showView)

#include "group_showView.moc"
