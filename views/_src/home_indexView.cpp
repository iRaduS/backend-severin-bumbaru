#include <QtCore>
#include <TreeFrogView>
#include "applicationhelper.h"

class T_VIEW_EXPORT home_indexView : public TActionView
{
  Q_OBJECT
public:
  home_indexView() : TActionView() { }
  QString toString();
};

QString home_indexView::toString()
{
  responsebody.reserve(2188);
  responsebody += QStringLiteral("<section class=\"hero is-medium is-info is-bold\">\n  <div class=\"hero-body\">\n    <div class=\"container has-text-centered\">\n      <h1 class=\"title\"><i class=\"fas fa-user-edit\"></i> CWL</h1>\n      <h6 class=\"subtitle\">An educational tool to enhance your learning experience</h6>\n    </div>\n  </div>\n</section>\n<div class=\"box\">\n  <p class=\"has-text-centered\">\n    <span class=\"tag is-info\">NEW</span> An updated and ready to go version to help teachers.\n  </p>\n</div>\n<section class=\"container\">\n  <div class=\"columns pt-6 pb-6\">\n    <div class=\"column is-4\">\n      <div class=\"card has-shadow mb-2\">\n        <div class=\"card-image has-text-centered\">\n          <i class=\"fa fa-user fa-6x pt-2 pb-2 has-text-info\"></i>\n        </div>\n        <div class=\"card-content\">\n          <div class=\"content mt-1 ml-1\">\n            <h4>User friendly</h4>\n            <p>We wanted to build a user friendly application which is easy to use and built for a large crowd of users.</p>\n          </div>\n        </div>\n      </div>\n    </div>\n\n    <div class=\"column is-4\">\n      <div class=\"card has-shadow mb-2\">\n        <div class=\"card-image has-text-centered\">\n          <i class=\"fa fa-level-up-alt fa-6x pt-2 pb-2 has-text-info\"></i>\n        </div>\n        <div class=\"card-content\">\n          <div class=\"content mt-1 ml-1\">\n            <h4>Competitive learning</h4>\n            <p>We wanted to build a fun way to take your tests made possible using it in a competitive manner.</p>\n          </div>\n        </div>\n      </div>\n    </div>\n\n    <div class=\"column is-4\">\n      <div class=\"card has-shadow mb-2\">\n        <div class=\"card-image has-text-centered\">\n          <i class=\"fa fa-cogs fa-6x pt-2 pb-2 has-text-info\"></i>\n        </div>\n        <div class=\"card-content\">\n          <div class=\"content mt-1 ml-1\">\n            <h4>Complexity</h4>\n            <p>The web application offers a large variety of options to choose and tools for students and teachers.</p>\n          </div>\n        </div>\n      </div>\n    </div>\n  </div>\n</section>");

  return responsebody;
}

T_DEFINE_VIEW(home_indexView)

#include "home_indexView.moc"
