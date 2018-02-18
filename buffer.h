#ifndef BUFFER_H
#define BUFFER_H
#include <vector>
#include <string>
#include <QLabel>
#include <QTextBrowser>
#include "maindisplay.h"
#include "history.h"
#include "result.h"

class Buffer
{
public:
    Buffer(QLabel*, QTextBrowser*, QLabel*);
    void addDigit(int);
    void addDot();
    void addOperator(int);
    void undo();
    void display();
    void equal();
private:
    std::vector< std::vector<int> > numbers;
    std::vector<int> operators;
    std::string toDisplay;
    MainDisplay main;
    History history;
    Result result;

};

#endif // BUFFER_H
