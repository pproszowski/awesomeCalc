#include "dotbutton.h"

DotButton::DotButton(QPushButton* btnPtr)
    : Button(btnPtr)
{
    this->addAnotherKey(Qt::Key_Comma);
}

void DotButton::sendInfoToBuffer(Buffer *buffer){
    buffer->addDot();
}

