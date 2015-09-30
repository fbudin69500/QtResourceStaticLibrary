#include "TestQt4.h"
#include <QApplication>
#include "QtIconCLP.h"

int main( int argc , char** argv )
{
  QApplication app(argc, argv);
  Q_INIT_RESOURCE(resources);
  TestQt4 window;
  window.show();
  
  return app.exec();
  
}
