#include "digitbutton.h"
#include <QTextStream>

DigitButton::DigitButton(QPushButton* btnPtr)
    : Button(btnPtr)
{

}

void DigitButton::sendInfoToBuffer(Buffer* buffer){
    buffer->addDigit(getKey());
}

