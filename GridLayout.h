#ifndef GRID_LAYOUT_H
#define GRID_LAYOUT_H

#include <QtWidgets>
#include <qpushbutton.h>
#include <string>

using namespace std;

class GridLayout {

  public:
    GridLayout(QWidget *window);
    ~GridLayout();

    void displayGrid();    
  

private: 

    QPushButton *createButton(const QString &text, QLineEdit *line);
    QWidget *window;
    string expresion;
};

#endif
