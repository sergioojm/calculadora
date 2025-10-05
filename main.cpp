#include <QApplication>
#include <QPushButton>
#include <QtWidgets>
#include <qgridlayout.h>
#include <qpushbutton.h>

#include "GridLayout.h"


int main(int argc, char *argv[]) 
{
  QApplication app(argc, argv);

  QWidget *window = new QWidget();
  GridLayout gridLayout(window);
  gridLayout.displayGrid();

  return app.exec();
}
