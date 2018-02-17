#include "button.h"
#include <QTextStream>

Button::Button(QPushButton* _buttonPtr){
    this->buttonPtr = _buttonPtr;
    this->keys.push_back(_buttonPtr->text().at(0).unicode());
}

void Button::click(){
    this->buttonPtr->animateClick();
}

bool Button::hasKey(int  _key){

    for(int key : this->keys){
        if(key == _key){
            return true;
        }
    }
    return false;
}

void Button::addAnotherKey(int key){
    this->keys.push_back(key);
}

int Button::getKey(){
    return this->keys.at(0);
}
