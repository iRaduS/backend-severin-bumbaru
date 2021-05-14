#include <QtCore>
#include <TreeFrogView>
#include "group.h"
#include "applicationhelper.h"
#include "uservalidator.h"

class T_VIEW_EXPORT quiz_showView : public TActionView
{
  Q_OBJECT
public:
  quiz_showView() : TActionView() { }
  QString toString();
};

QString quiz_showView::toString()
{
  responsebody.reserve(356);
    tfetch(Group, group);
  tfetch(int, userId);
  tfetch(QString, quizes);
  responsebody += QStringLiteral("\n<div id=\"quiz\" data-quiz=\"");
  responsebody += THttpUtility::htmlEscape(quizes);
  responsebody += QStringLiteral("\" data-groupid=\"");
  responsebody += THttpUtility::htmlEscape(group.id());
  responsebody += QStringLiteral("\"></div>");

  return responsebody;
}

T_DEFINE_VIEW(quiz_showView)

#include "quiz_showView.moc"
