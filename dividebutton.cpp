#include "dividebutton.h"

DivideButton::DivideButton(QPushButton* btnPtr)
    : OperatorButton(btnPtr)
{
    this->addAnotherKey(Qt::Key_Slash);
}

