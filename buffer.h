#ifndef BUFFER_H
#define BUFFER_H
#include <vector>
#include <string>
#include <QLabel>
#include <QTextBrowser>

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
    bool canPutDot;
    bool canPutOperator;
    std::vector< std::vector<int> > numbers;
    std::vector<int> operators;
    std::string toDisplay;
    QLabel* main;
    QLabel* result;
    QTextBrowser* history;
    QString mainString;
    QString historyString;

};

#endif // BUFFER_H
