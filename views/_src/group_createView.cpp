#include <QtCore>
#include <TreeFrogView>
#include "applicationhelper.h"
#include "uservalidator.h"

class T_VIEW_EXPORT group_createView : public TActionView
{
  Q_OBJECT
public:
  group_createView() : TActionView() { }
  QString toString();
};

QString group_createView::toString()
{
  responsebody.reserve(670);
  responsebody += QStringLiteral("<div class=\"notification is-link\">\n  ");
  tehex(error);
  responsebody += QStringLiteral("\n  ");
  tehex(notice);
  responsebody += QStringLiteral("\n</div>\n\n<h1 class=\"title\">Create a new group</h1>\n");
  responsebody += QVariant(formTag(urla("create"), Tf::Post, true, a("class", "box"))).toString();
  responsebody += QStringLiteral("\n  <div class=\"field\">\n    <label class=\"label\">Group name</label>\n    <div class=\"control\">\n      <input class=\"input\" type=\"text\" name=\"name\" placeholder=\"e.g. Elon Musk's groups\" />\n    </div>\n  </div>\n  <button class=\"button is-link\">Submit</button>\n</form>");

  return responsebody;
}

T_DEFINE_VIEW(group_createView)

#include "group_createView.moc"
