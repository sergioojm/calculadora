#include <QAbstractButton>
#include <QtWidgets>
#include <qnamespace.h>

#include "GridLayout.h"
#include "Lexer.h"

using namespace std;

#define DIGITS_COUNT 10
#define OPERATORS_COUNT 8


GridLayout::~GridLayout() {}


GridLayout::GridLayout(QWidget *window)
{
  this->window = window;
  this->expresion = "";
}

void GridLayout::displayGrid()
{
  this->window->setWindowTitle(QString::fromStdString("Calculator"));
  QGridLayout *layout = new QGridLayout(this->window);

  QLineEdit *line = new QLineEdit();
  line->setReadOnly(true);
  line->setAlignment(Qt::AlignCenter);

  string digits[DIGITS_COUNT] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "0"};
  int digits_counter = 0;

  for (int i = 1; i <= 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      layout->addWidget(this->createButton(QString::fromStdString(digits[digits_counter++]), line), i, j);
    }
  }
  layout->addWidget(this->createButton(QString::fromStdString("0"), line), 4, 1);
  layout->addWidget(line, 0, 0, 1, 4);


  // usar un map seria mejor
  string operators[OPERATORS_COUNT] = {"+", "-", "*", "/", "=", "Cl", "(", ")"};
  int operator_pos[OPERATORS_COUNT][2] = {
    {1, 4},
    {2, 4},
    {3, 4},
    {4, 4},
    {4, 2},
    {4, 0},
    {5, 0},
    {5, 1},
  }; 


  for (int i = 0; i < OPERATORS_COUNT; i++)
  {
    layout->addWidget(this->createButton(QString::fromStdString(operators[i]), line), operator_pos[i][0], operator_pos[i][1]);
  }


  this->window->show();
}


QPushButton *GridLayout::createButton(const QString &text, QLineEdit *line)
{
  QPushButton *button = new QPushButton(text);

  QObject::connect(button, &QPushButton::clicked, [this, line, text]() 
  {
      if (text == "Cl")
      {
        this->expresion.clear();
        line->clear();
      }
      else if (text == "=")
      {
        if (this->expresion == "" || this->expresion.empty())
        {
          line->setText(QString::fromStdString("No expression to resolve"));
          return;
        }

        Lexer *lexer = new Lexer();

        lexer->parse(this->expresion);
        Expression* result = lexer->execute();
        lexer->printExpr(result);
        cout << endl;
        double resolved_result = lexer->resolve(result);

        cout << "resolved_result -> " << resolved_result << endl;

        line->setText(QString::number(resolved_result, 'f', 10));

        delete result;
        this->expresion = "";
      }
      else
      {
        this->expresion += text.toStdString();
        line->setText(QString::fromStdString(this->expresion));
      }


  });


  return button;
}


