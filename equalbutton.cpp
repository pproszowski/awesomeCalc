#include "equalbutton.h"
#define ENTER 16777220

EqualButton::EqualButton(QPushButton* btnPtr)
    :Button(btnPtr)
{
    this->addAnotherKey(ENTER);
}


void EqualButton::sendInfoToBuffer(Buffer* buffer){
    buffer->equal();
}
