#include "buffer.h"
#include <QTextStream>
#include <QScrollBar>
#include <QTextCursor>

Buffer::Buffer(QLabel* _main, QTextBrowser* _history, QLabel* _result){
    canPutDot = true;
    canPutOperator = false;
    main = _main;
    history = _history;
    result = _result;
}

void Buffer::addDigit(int digit){
    if(numbers.empty()) numbers.push_back(std::vector<int>());
    if(numbers.size() == 1){
        if(numbers.back().empty()){
            if(digit == '0'){
                return;
            }
            mainString.clear();
        }
    }
    numbers.back().push_back(digit);
    mainString += digit;
    canPutOperator = true;
    display();
}

void Buffer::addDot(){
    if(canPutDot){
        if(numbers.back().size() < 1){
            numbers.back().push_back(0);
            mainString += '0';
        }
        numbers.back().push_back('.');
        mainString += '.';
        canPutDot = false;
        canPutOperator = true;
    }
    display();
}

void Buffer::addOperator(int op){
    if(canPutOperator){
        numbers.push_back(std::vector<int>());
        canPutOperator = false;
        operators.push_back(op);
        if(!historyString.isEmpty()){
            historyString += '\n';
        }
        historyString += mainString;
        mainString = op;
        mainString += ' ';
    }else if(!operators.empty()){
        operators.pop_back();
        operators.push_back(op);
        mainString.replace(0, 1, op);
    }else{
        return;
    }



    display();
}

void Buffer::undo(){
    if(numbers.empty() || mainString.contains('=')) return;

    if(mainString.at(mainString.size() - 1).isDigit() || mainString.at(mainString.size() - 1) == '.'){
        mainString.chop(1);
        numbers.back().pop_back();
        if(numbers.back().empty()){
            numbers.pop_back();
            if(numbers.empty()){
                canPutOperator = false;
            }
        }
    }else{
        if(operators.size() < numbers.size())
        operators.pop_back();
        mainString.clear();
        int counter = 1;

        if(historyString.contains('\n')){
            while(historyString.at(historyString.size() - counter) != '\n'){
            mainString.push_front(historyString.at(historyString.size() - counter));
            counter++;
            }
            historyString.chop(counter);
       }else{
            mainString = historyString;
            historyString.clear();
       } 
    }

    display();
}

void Buffer::display(){
    if(numbers.empty()){
        result->setText("");
        mainString = "0";
    }else if(mainString.contains('=')){
            result->clear();
        }else{
            result->setText("= result");
        }

    main->setText(mainString);
    history->setText(historyString);
    history->selectAll();
    history->setAlignment(Qt::AlignRight);
    QTextCursor cursor = history->textCursor();
    cursor.movePosition(QTextCursor::End);
    history->setTextCursor(cursor);
}

void Buffer::equal(){
    if(numbers.empty()){
        return;
    }
    if(mainString.contains('=')){
        return;
    }


    historyString += '\n';
    historyString += main->text();
    mainString = "= result";
    result->clear();
    display();
}

void Buffer::afterResult(){
    history->append('\n--------------------------------------------------------');
}
