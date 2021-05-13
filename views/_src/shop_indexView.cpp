#include <QtCore>
#include <TreeFrogView>
#include "user.h"
#include "applicationhelper.h"
#include "uservalidator.h"

class T_VIEW_EXPORT shop_indexView : public TActionView
{
  Q_OBJECT
public:
  shop_indexView() : TActionView() { }
  QString toString();
};

QString shop_indexView::toString()
{
  responsebody.reserve(5122);
    tfetch(User, user);
  responsebody += QStringLiteral("<div class=\"notification is-link\">\n  ");
  tehex(notice);
  responsebody += QStringLiteral("\n</div>\n<div class=\"container\">\n  <div class=\"is-size-3 text has-font-weight-bold\">\n    <strong>SHOP</strong>\n  </div>\n  <p class=\"credits\" style=\"has-text-right\">Credits: <span class=\"tag is-warning\">");
  responsebody += THttpUtility::htmlEscape(user.credits());
  responsebody += QStringLiteral("</span></p>\n  <div class=\"mt-4 columns is-multiline is-mobile\">\n    <div class=\"column is-one-quarter\">\n      <div class=\"card\">\n          <div class=\"card-content\">\n              <div class=\"content\">\n                  <p class=\"has-text-centered is-size-4\">Fire profile icon</p>\n                  <p>\n                    <strong>Description:</strong>\n                    <div class=\"has-text-centered\">\n                      <img src=\"/images/fire.gif\" />\n                    </div>\n                  </p>\n                  ");
  if (user.isFire()) {
  responsebody += QStringLiteral("                    <label>\n                      <span class=\"tag is-success\">\n                        owned\n                      </span>\n                    </label>\n                  ");
  } else {
  responsebody += QStringLiteral("                    ");
  responsebody += QVariant(linkTo("Buy - 350 credits", urla("buyItem", 1), Tf::Post, "confirm('Are you sure?')", a("class", "button is-black"))).toString();
  responsebody += QStringLiteral("\n                  ");
  };
  responsebody += QStringLiteral("              </div>\n          </div>\n      </div>\n    </div>\n    <div class=\"column is-one-quarter\">\n        <div class=\"card\">\n            <div class=\"card-content\">\n                <div class=\"content\">\n                    <p class=\"has-text-centered is-size-4\">Gambit</p>\n                    <p><strong>Description:</strong>\n                        With this power your very first question in your quiz will have only 2\n                    answers possible.</p>\n                    ");
  responsebody += QVariant(linkTo("Buy - 30 credits", urla("buyItem", 2), Tf::Post, "confirm('Are you sure?')", a("class", "button is-black"))).toString();
  responsebody += QStringLiteral("\n                    <label>\n                    ");
  if (user.fiftyFifty()) {
  responsebody += QStringLiteral("                        <span class=\"tag is-success\">\n                          ");
  responsebody += THttpUtility::htmlEscape(user.fiftyFifty());
  responsebody += QStringLiteral(" owned\n                        </span>\n                      ");
  };
  responsebody += QStringLiteral("                    </label>\n                </div>\n            </div>\n        </div>\n    </div>\n    <div class=\"column is-one-quarter\">\n        <div class=\"card\">\n            <div class=\"card-content\">\n                <div class=\"content\">\n                    <p class=\"has-text-centered is-size-4\">Riddle</p>\n                    <p><strong>Description:</strong><br>\n                        With this power you can receive a hint from your teacher\n                    based on your question.</p>\n                    ");
  responsebody += QVariant(linkTo("Buy - 30 credits", urla("buyItem", 3), Tf::Post, "confirm('Are you sure?')", a("class", "button is-black"))).toString();
  responsebody += QStringLiteral("\n                    <label>\n                      ");
  if (user.hintGuesser()) {
  responsebody += QStringLiteral("                        <span class=\"tag is-success\">\n                          ");
  responsebody += THttpUtility::htmlEscape(user.hintGuesser());
  responsebody += QStringLiteral(" owned\n                        </span>\n                      ");
  };
  responsebody += QStringLiteral("                    </label>\n                </div>\n            </div>\n        </div>\n    </div>\n    <div class=\"column is-one-quarter\">\n      <div class=\"card\">\n          <div class=\"card-content\">\n              <div class=\"content\">\n                  <p class=\"has-text-centered is-size-4\">Elon Musk's profile icon</p>\n                  <p>\n                    <strong>Description:</strong>\n                    <div class=\"has-text-centered\">\n                      <img src=\"/images/elon.gif\" />\n                    </div>\n                  </p>\n                  ");
  if (user.isElonMusk()) {
  responsebody += QStringLiteral("                  <label>\n                      <span class=\"tag is-success\">\n                        owned\n                      </span>\n                  </label>\n                  ");
  } else {
  responsebody += QStringLiteral("                    ");
  responsebody += QVariant(linkTo("Buy - 1000 credits", urla("buyItem", 4), Tf::Post, "confirm('Are you sure?')", a("class", "button is-black"))).toString();
  responsebody += QStringLiteral("\n                  ");
  };
  responsebody += QStringLiteral("              </div>\n          </div>\n      </div>\n    </div>\n  </div>\n</div>");

  return responsebody;
}

T_DEFINE_VIEW(shop_indexView)

#include "shop_indexView.moc"
