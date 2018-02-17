#ifndef OPERATORBUTTON_H
#define OPERATORBUTTON_H
#include "button.h"


class OperatorButton : public Button
{
public:
    OperatorButton(QPushButton*);
    void sendInfoToBuffer(Buffer* buffer) override;
};

#endif // OPERATORBUTTON_H
