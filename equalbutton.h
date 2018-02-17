#ifndef EQUALBUTTON_H
#define EQUALBUTTON_H
#include "button.h"


class EqualButton : public Button
{
public:
    EqualButton(QPushButton *btnPtr);
    void sendInfoToBuffer(Buffer*) override;
};

#endif // EQUALBUTTON_H
