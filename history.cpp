#include "history.h"

History::History(QTextBrowser* _history)
    :history(_history)
{

}

void History::append(QString text){
    if(! history->toPlainText().isEmpty()){
        history->setText(history->toPlainText() + '\n');
    }

    history->setText(history->toPlainText() + text);
    rightAlign();
}

QString History::popLastLine(){

    QString lastLine;
    if(history->toPlainText().contains('\n')){
        int counter = 1;
        while(history->toPlainText().at(history->toPlainText().size() - counter) != '\n'){
            lastLine.push_front(history->toPlainText().at(history->toPlainText().size() - counter));
            counter++;
        }

        QString text = history->toPlainText();
        text.chop(counter);
        history->setText(text);
    }
    else{
        lastLine = history->toPlainText();
        history->clear();
    }

    rightAlign();
    return lastLine;
}

void History::rightAlign(){

    history->setText(history->toPlainText());

    history->selectAll();
    history->setAlignment(Qt::AlignRight);
    QTextCursor cursor = history->textCursor();
    cursor.movePosition(QTextCursor::End);
    history->setTextCursor(cursor);
}

void History::save(){
    history->setText(history->toPlainText() + "\n---------------------------");
    rightAlign();
}
