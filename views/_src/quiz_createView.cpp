#include <QtCore>
#include <TreeFrogView>
#include "applicationhelper.h"
#include "uservalidator.h"

class T_VIEW_EXPORT quiz_createView : public TActionView
{
  Q_OBJECT
public:
  quiz_createView() : TActionView() { }
  QString toString();
};

QString quiz_createView::toString()
{
  responsebody.reserve(190);
  tfetch(QString, id);
  responsebody += QStringLiteral("<div id=\"create-quiz\" data-id=\"");
  responsebody += THttpUtility::htmlEscape(id);
  responsebody += QStringLiteral("\"></div>");

  return responsebody;
}

T_DEFINE_VIEW(quiz_createView)

#include "quiz_createView.moc"
