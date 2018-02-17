#ifndef __BUTTON_H__
#define __BUTTON_H__
#include <QPushButton>
#include <QChar>
#include <vector>
#include <QObject>
#include "buffer.h"

class Button : protected QObject{
public:
    Button(QPushButton*);
    bool hasKey(int);
    void click();
    virtual void sendInfoToBuffer(Buffer*) = 0;
protected:
    int getKey();
    void addAnotherKey(int);
private:
    QPushButton* buttonPtr;
    std::vector<int> keys;
};

#endif
