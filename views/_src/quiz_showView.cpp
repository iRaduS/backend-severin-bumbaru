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
  responsebody.reserve(742);
    tfetch(Group, group);
  tfetch(int, userId);
  tfetch(int, fiftyFifty);
  tfetch(int, hintGuesser);
  tfetch(QString, quizes);
  responsebody += QStringLiteral("\n<div id=\"quiz\" data-quiz=\"");
  responsebody += THttpUtility::htmlEscape(quizes);
  responsebody += QStringLiteral("\" data-groupid=\"");
  responsebody += THttpUtility::htmlEscape(group.id());
  responsebody += QStringLiteral("\" data-user=\"");
  responsebody += THttpUtility::htmlEscape(userId);
  responsebody += QStringLiteral("\" \n  data-fifty=\"");
  responsebody += THttpUtility::htmlEscape(fiftyFifty);
  responsebody += QStringLiteral("\" data-hint=\"");
  responsebody += THttpUtility::htmlEscape(hintGuesser);
  responsebody += QStringLiteral("\"\n></div>");

  return responsebody;
}

T_DEFINE_VIEW(quiz_showView)

#include "quiz_showView.moc"
