#ifndef DELETEBUTTON_H
#define DELETEBUTTON_H
#include "button.h"


class DeleteButton : public Button
{
public:
    DeleteButton(QPushButton*btnPtr);
    void sendInfoToBuffer(Buffer* buffer);
};

#endif // DELETEBUTTON_H
