#include "operatorbutton.h"
#include <QTextStream>

OperatorButton::OperatorButton(QPushButton* btnPtr)
: Button(btnPtr) {}


void OperatorButton::sendInfoToBuffer(Buffer* buffer){
    buffer->addOperator(getKey());
}
