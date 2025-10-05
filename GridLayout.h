#ifndef GRID_LAYOUT_H
#define GRID_LAYOUT_H

#include <QWidget>
#include <string>

using namespace std;

class GridLayout {

  public:
    GridLayout(QWidget *window);
    ~GridLayout();

    void displayGrid();    
  

private: 

    QWidget *window;
    string expresion;
};

#endif
