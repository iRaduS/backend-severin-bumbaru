#include <QtCore>
#include <TreeFrogView>
#include "applicationhelper.h"

class T_VIEW_EXPORT layouts_applicationView : public TActionView
{
  Q_OBJECT
public:
  layouts_applicationView() : TActionView() { }
  QString toString();
};

QString layouts_applicationView::toString()
{
  responsebody.reserve(1632);
  responsebody += QStringLiteral("<!DOCTYPE html>\n<html lang=\"en\">\n<head>\n  <meta charset=\"UTF-8\">\n  <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n  <meta name=\"keywords\" content=\"educational, multi-purpose, real-time\">\n  <meta name=\"description\" content=\"CWL\">\n  <title>CWL</title>\n\n  <meta property=\"og:type\" content=\"website\">\n  <meta property=\"og:url\" content=\"\">\n  <meta property=\"og:title\" content=\"CWL\">\n  <meta property=\"og:description\" content=\"Educational site with entertaining content.\">\n  <meta property=\"og:image\" content=\"\">\n\n  <meta property=\"twitter:card\" content=\"summary_large_image\">\n  <meta property=\"twitter:url\" content=\"\">\n  <meta property=\"twitter:title\" content=\"CWL\">\n  <meta property=\"twitter:description\" content=\"Educational site with entertaining content.\">\n  <meta property=\"twitter:image\" content=\"\">\n\n  <script src=\"/js/bulma.js\" defer></script>\n\n  <link rel=\"dns-prefetch\" href=\"//fonts.gstatic.com\">\n  <link href=\"https://fonts.googleapis.com/css2?family=PT+Sans:ital,wght@0,400;0,700;1,400;1,700&display=swap\" rel=\"stylesheet\">\n  <link href=\"/css/bulma.min.css\" rel=\"stylesheet\">\n  <link href=\"/css/all.min.css\" rel=\"stylesheet\">\n</head>\n<body>\n  ");
  responsebody += QVariant(renderPartial("navbar")).toString();
  responsebody += QStringLiteral("\n  ");
  responsebody += QVariant(yield()).toString();
  responsebody += QStringLiteral("\n  ");
  responsebody += QVariant(renderPartial("footer")).toString();
  responsebody += QStringLiteral("\n</body>\n</html>");

  return responsebody;
}

T_DEFINE_VIEW(layouts_applicationView)

#include "layouts_applicationView.moc"
