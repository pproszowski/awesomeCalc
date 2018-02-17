#include "deletebutton.h"

DeleteButton::DeleteButton(QPushButton* btnPtr)
    : Button(btnPtr)
{
    this->addAnotherKey(Qt::Key_Backspace);
    this->addAnotherKey(Qt::Key_Delete);
}

void DeleteButton::sendInfoToBuffer(Buffer *buffer){
    buffer->undo();
}
