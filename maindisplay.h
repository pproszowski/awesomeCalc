#ifndef MAINDISPLAY_H
#define MAINDISPLAY_H
#include <QLabel>

class MainDisplay
{
public:
    MainDisplay(QLabel* _main);
    bool append(int, bool isOperator = false);
    bool addDot();
    void clear();
    QString text();
    void replaceOperator(int op);
    QChar pop();
    void setText(QString text);
    void putResult(QString text);
    bool hasResult();
private:
    bool result;
    bool canPutDot;
    QLabel* main;
};

#endif // MAINDISPLAY_H
