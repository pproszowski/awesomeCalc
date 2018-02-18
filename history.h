#ifndef HISTORY_H
#define HISTORY_H
#include <QTextBrowser>

class History
{
public:
    History(QTextBrowser* _history);
    void append(QString text);
    QString popLastLine();
    void save();
private:
    void rightAlign();
    QString savedHistoryString;
    QTextBrowser* history;
};

#endif // HISTORY_H
