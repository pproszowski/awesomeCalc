#ifndef BUTTONFACTORY_H
#define BUTTONFACTORY_H
#include "button.h"
#include "deletebutton.h"
#include "dividebutton.h"
#include "dotbutton.h"
#include "multiplybutton.h"
#include "digitbutton.h"
#include "equalbutton.h"

class ButtonFactory
{
public:
    static ButtonFactory* Instance();
    Button* createButton(QPushButton*);
protected:
    explicit ButtonFactory(){}
private:
    static ButtonFactory* _instance;
};

#endif // BUTTONFACTORY_H
