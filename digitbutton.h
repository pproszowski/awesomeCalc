#ifndef DIGITBUTTON_H
#define DIGITBUTTON_H
#include "button.h"

class DigitButton : public Button
{
public:
    DigitButton(QPushButton* btnPtr);
    void sendInfoToBuffer(Buffer* buffer) override;
};

#endif // DIGITBUTTON_H
