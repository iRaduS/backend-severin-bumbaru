#include <QtCore>
#include <TreeFrogView>
#include "group.h" 
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
  responsebody.reserve(480);
    tfetch(Group, group);
  responsebody += QStringLiteral("<h1 class=\"title\">Create a new quiz for</h1>\n<h2 class=\"subtitle\">");
  responsebody += THttpUtility::htmlEscape(group.name());
  responsebody += QStringLiteral("</h2>\n<a class=\"button is-link is-outline is-small\" href=\"");
  responsebody += QVariant(url("quiz", "create", group.id())).toString();
  responsebody += QStringLiteral("\">\n  <span>Create a new quiz <i class=\"fas fa-plus\"></i></span>\n</a>\n");

  return responsebody;
}

T_DEFINE_VIEW(group_showView)

#include "group_showView.moc"
