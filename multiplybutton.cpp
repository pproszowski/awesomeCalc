#include "multiplybutton.h"

MultiplyButton::MultiplyButton(QPushButton* btnPtr)
    : OperatorButton(btnPtr)
{
    this->addAnotherKey(Qt::Key_X);
    this->addAnotherKey(Qt::Key_Asterisk);
}

