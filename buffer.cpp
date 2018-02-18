#include "buffer.h"
#include <QTextStream>
#include <QScrollBar>
#include <QTextCursor>

Buffer::Buffer(QLabel* _main, QTextBrowser* _history, QLabel* _result)
    :main(_main), history(_history), result(_result)
{
    main.setText("0");
}

void Buffer::addDigit(int digit){
    if(main.hasResult()){
        history.append(main.text());
        history.save();
        QString s(digit);
        main.setText(s);
        return;
    }

    if(main.append(digit)){
        if(numbers.empty()){
            numbers.push_back(std::vector<int>());
        }
        QChar d(digit);
        numbers.back().push_back(d.digitValue());
        result.calculateAndDisplay(numbers, operators);
    }
}

void Buffer::addDot(){
    if(main.addDot()){
        if(numbers.empty()){
            numbers.push_back(std::vector<int>());
        }
        if(numbers.back().empty()){
            numbers.back().push_back(0);
            if(main.text().isEmpty()){
                main.append('0');
            }
        }
        numbers.back().push_back('.');
    }

    result.calculateAndDisplay(numbers,operators);
}

void Buffer::addOperator(int op){
    if(main.hasResult()){
        history.append(main.text());
        history.save();
        QString r = main.text();
        r.remove(0,2);
        main.setText(r);
        numbers.push_back(std::vector<int>());
        for(QChar i : r){
            numbers.back().push_back(i.unicode());
        }
        addOperator(op);
        return;
    }

    if(numbers.empty()){
        return;
    }else if(operators.size() < numbers.size()){
        history.append(main.text());
        main.clear();
        main.append(op);
        main.append(' ');
        numbers.push_back(std::vector<int>());
    }else{
        main.replaceOperator(op);
        operators.pop_back();
    }

    operators.push_back(op);
    result.calculateAndDisplay(numbers, operators);
}

void Buffer::undo(){
    QTextStream out(stdout);
    out<<numbers.size();
    if(numbers.empty()){
        return;
    }

    QChar popped = main.pop();
    if(popped.isSpace()){
       main.setText(history.popLastLine());
       if(numbers.size() > operators.size()){
           numbers.pop_back();
       }
       operators.pop_back();
    }else{
        numbers.back().pop_back();
        if(numbers.back().empty()){
            numbers.pop_back();
            if(numbers.empty()){
                main.setText("0");
                result.clear();
            }
        }
    }

    result.calculateAndDisplay(numbers, operators);
}

void Buffer::equal(){
   if(numbers.empty() || main.hasResult()){
       return;
   }

   history.append(main.text());
   main.putResult(result.text());
   result.clear();
   numbers.clear();
   operators.clear();
}

