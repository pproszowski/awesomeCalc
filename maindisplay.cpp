#include "maindisplay.h"

MainDisplay::MainDisplay(QLabel* _main)
    :main(_main)
{
    result = false;
    canPutDot = true;
}

bool MainDisplay::append(int digit, bool isOperator){
    result = false;

    if(main->text().size() == 1){
        if(main->text().at(0) == '0'){
            if(digit == '0'){
                return false;
            }else{
                main->clear();
            }
        }
    }

    main->setText(main->text() + digit);
    if(isOperator){
        canPutDot = true;
    }

    return true;
}

bool MainDisplay::addDot(){
    result = false;
    if(canPutDot){
        canPutDot = false;
        main->setText(main->text() + '.');
        return true;
    }

    return false;
}

QString MainDisplay::text(){
    return main->text();
}

void MainDisplay::replaceOperator(int op){
    main->clear();
    main->setText(op + " ");
}

QChar MainDisplay::pop(){
    result = false;
    QChar lastChar = main->text().at(main->text().size() - 1);
    QString s = main->text();
    s.chop(1);
    main->setText(s);
    return lastChar;
}

void MainDisplay::clear(){
    result = false;
    main->clear();
}

void MainDisplay::setText(QString text){
    result = false;
    main->setText(text);
}

void MainDisplay::putResult(QString text){
    result = true;
    main->setText(text);
}

bool MainDisplay::hasResult(){
    return result;
}

