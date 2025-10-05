#include <QAbstractButton>
#include <QtWidgets>
#include <qnamespace.h>

#include "GridLayout.h"
#include "Lexer.h"

using namespace std;

GridLayout::~GridLayout()
{
}


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

  QPushButton *button_one = new QPushButton(QString::fromStdString("1"));
  QPushButton *button_two = new QPushButton(QString::fromStdString("2"));
  QPushButton *button_three = new QPushButton(QString::fromStdString("3"));
  QPushButton *button_four = new QPushButton(QString::fromStdString("4"));
  QPushButton *button_five = new QPushButton(QString::fromStdString("5"));
  QPushButton *button_six = new QPushButton(QString::fromStdString("6"));
  QPushButton *button_seven = new QPushButton(QString::fromStdString("7"));
  QPushButton *button_eight = new QPushButton(QString::fromStdString("8"));
  QPushButton *button_nine = new QPushButton(QString::fromStdString("9"));
  QPushButton *button_zero = new QPushButton(QString::fromStdString("0"));
  QPushButton *button_plus = new QPushButton(QString::fromStdString("+"));
  QPushButton *button_minus = new QPushButton(QString::fromStdString("-"));
  QPushButton *button_multiply = new QPushButton(QString::fromStdString("*"));
  QPushButton *button_divide = new QPushButton(QString::fromStdString("/"));
  QPushButton *button_equal = new QPushButton(QString::fromStdString("="));
  QPushButton *button_clear = new QPushButton(QString::fromStdString("Cl"));
  QPushButton *button_parenthesis_open = new QPushButton(QString::fromStdString("("));
  QPushButton *button_parenthesis_close = new QPushButton(QString::fromStdString(")"));


  layout->addWidget(line, 0, 0, 1, 4);
  layout->addWidget(button_one, 1, 0);
  layout->addWidget(button_two, 1, 1);
  layout->addWidget(button_three, 1, 2);
  layout->addWidget(button_four, 2, 0);
  layout->addWidget(button_five, 2, 1);
  layout->addWidget(button_six, 2, 2);
  layout->addWidget(button_seven, 3, 0);
  layout->addWidget(button_eight, 3, 1);
  layout->addWidget(button_nine, 3, 2);
  layout->addWidget(button_zero, 4, 1);

  layout->addWidget(button_plus, 1, 4);
  layout->addWidget(button_minus, 2, 4);
  layout->addWidget(button_multiply, 3, 4);
  layout->addWidget(button_divide, 4, 4);
  layout->addWidget(button_equal, 4, 2);
  layout->addWidget(button_clear, 4, 0);
  layout->addWidget(button_parenthesis_open, 5, 0);
  layout->addWidget(button_parenthesis_close, 5, 1);

  QObject::connect(button_parenthesis_open, &QPushButton::clicked, [this, line]() {
    this->expresion += "(";
    line->setText(QString::fromStdString(this->expresion));
  });

  QObject::connect(button_parenthesis_close, &QPushButton::clicked, [this, line]() {
    this->expresion += ")";
    line->setText(QString::fromStdString(this->expresion));
  });

  QObject::connect(button_clear, &QPushButton::clicked, [this, line]() {
    this->expresion = "";
    line->setText(QString::fromStdString(this->expresion));
  });

  QObject::connect(button_one, &QPushButton::clicked, [this, line]() {
    this->expresion += "1";
    line->setText(QString::fromStdString(this->expresion));
  });

  QObject::connect(button_two, &QPushButton::clicked, [this, line]() {
    this->expresion += "2";
    line->setText(QString::fromStdString(this->expresion));
  });

  QObject::connect(button_three, &QPushButton::clicked, [this, line]() {
    this->expresion += "3";
    line->setText(QString::fromStdString(this->expresion));
  });

  QObject::connect(button_four, &QPushButton::clicked, [this, line]() {
    this->expresion += "4";
    line->setText(QString::fromStdString(this->expresion));
  });

  QObject::connect(button_five, &QPushButton::clicked, [this, line]() {
    this->expresion += "5";
    line->setText(QString::fromStdString(this->expresion));
  });

  QObject::connect(button_six, &QPushButton::clicked, [this, line]() {
    this->expresion += "6";
    line->setText(QString::fromStdString(this->expresion));
  });

  QObject::connect(button_seven, &QPushButton::clicked, [this, line]() {
    this->expresion += "7";
    line->setText(QString::fromStdString(this->expresion));
  });

  QObject::connect(button_eight, &QPushButton::clicked, [this, line]() {
    this->expresion += "8";
    line->setText(QString::fromStdString(this->expresion));
  });

  QObject::connect(button_nine, &QPushButton::clicked, [this, line]() {
    this->expresion += "9";
    line->setText(QString::fromStdString(this->expresion));
  });

  QObject::connect(button_zero, &QPushButton::clicked, [this, line]() {
    this->expresion += "0";
    line->setText(QString::fromStdString(this->expresion));
  });

  QObject::connect(button_plus, &QPushButton::clicked, [this, line]() {
    this->expresion += "+";
    line->setText(QString::fromStdString(this->expresion));
  });

  QObject::connect(button_minus, &QPushButton::clicked, [this, line]() {
    this->expresion += "-";
    line->setText(QString::fromStdString(this->expresion));
  });

  QObject::connect(button_multiply, &QPushButton::clicked, [this, line]() {
    this->expresion += "*";
    line->setText(QString::fromStdString(this->expresion));
  });

  QObject::connect(button_divide, &QPushButton::clicked, [this, line]() {
    this->expresion += "/";
    line->setText(QString::fromStdString(this->expresion));
  });

  QObject::connect(button_equal, &QPushButton::clicked, [this, line]() {

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

    this->expresion = "";
  });

  this->window->show();
}

