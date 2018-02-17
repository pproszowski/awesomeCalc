#include "buttonfactory.h"
#include <QTextStream>



ButtonFactory* ButtonFactory::_instance = 0;

ButtonFactory* ButtonFactory::Instance(){
    if(_instance == 0){
        _instance = new ButtonFactory;
    }

    return _instance;
}

Button* ButtonFactory::createButton(QPushButton* buttonPtr){
   switch(buttonPtr->text().at(0).unicode()){
   case Qt::Key_Equal:
       return new EqualButton(buttonPtr);
   case Qt::Key_division:
       return new DivideButton(buttonPtr);
       break;
   case Qt::Key_Plus:
   case Qt::Key_Minus:
       return new OperatorButton(buttonPtr);
       break;
   case Qt::Key_multiply:
       return new MultiplyButton(buttonPtr);
       break;
   case Qt::Key_Period:
       return new DotButton(buttonPtr);
       break;
   case Qt::Key_C:
       return new DeleteButton(buttonPtr);
       break;
   default:
       return new DigitButton(buttonPtr);
   }

}

