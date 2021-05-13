#include <QtCore>
#include <TreeFrogView>
#include "applicationhelper.h"

class T_VIEW_EXPORT partial_footerView : public TActionView
{
  Q_OBJECT
public:
  partial_footerView() : TActionView() { }
  QString toString();
};

QString partial_footerView::toString()
{
  responsebody.reserve(313);
  responsebody += QStringLiteral("<footer class=\"footer\">\n  <div class=\"content has-text-centered\">\n    <p>\n      <strong>CWL</strong> made for a better educational process, made with <i class=\"fas fa-heart has-text-danger\"></i> by <strong>Elon Musk's acolytes</strong>\n    </p>\n  </div>\n</footer>");

  return responsebody;
}

T_DEFINE_VIEW(partial_footerView)

#include "partial_footerView.moc"
