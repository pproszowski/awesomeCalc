#ifndef DOTBUTTON_H
#define DOTBUTTON_H
#include "button.h"

class DotButton : public Button
{
public:
    DotButton(QPushButton*btnPtr);
    void sendInfoToBuffer(Buffer* buffer) override;
};

#endif // DOTBUTTON_H
