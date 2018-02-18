#include "result.h"
#include <QTextStream>

Result::Result(QLabel* _result)
    :result(_result)
{
}

void Result::calculateAndDisplay(std::vector<std::vector<int>> n,std::vector<int> operators){
    if(n.empty()){
        return;
    }

    if(n.size() == operators.size()){
        operators.pop_back();
    }

   std::vector<double> numbers = convertToDoubleVector(n);
   QTextStream out(stdout);
   for(unsigned int i = 0; i < numbers.size(); i++){
       out<<numbers.at(i)<<endl;
   }

   unsigned int index = 0;
   while(true){
       for(index = 0; index < operators.size() - 1; index++){
           if(firstIsMoreImportantOrEqual(operators.at(index), operators.at(index+1))){
              if(index == operators.size() - 2){
                  index++;
              }else{
                  break;
              }
           }
       }

       numbers[index] = calculate(numbers[index], numbers[index + 1], operators.at(index));
       operators.erase(operators.begin() + index);
       numbers.erase(numbers.begin() + index + 1);
       if(operators.empty()) break;
   }

}

double Result::calculate(double a, double b, int op){
    return 1.23;
}

bool Result::firstIsMoreImportantOrEqual(int a, int b){
    if(a == Qt::Key_Minus || a == Qt::Key_Plus){
        if(b == Qt::Key_multiply || b == Qt::Key_division){
            return false;
        }
    }
    return true;
}

std::vector<double> Result::convertToDoubleVector(std::vector<std::vector<int>> n){
    std::vector<double> doubles;
    double d = 0;
    double divider = 0;
    for(int i = 0; i < n.size(); i++){
        for(int j = 0; j < n.at(i).size(); j++){
            if(n.at(i).at(j) == Qt::Key_Period){
                divider = pow(10, -(n.at(i).size() - j - 1));
                if(j == 1 && n.at(i).at(0) == Qt::Key_0){
                    divider /= 10;
                    continue;
                }
            }
            QChar ch(n.at(i).at(j));
            d += ch.digitValue() * pow(10, n.at(i).size() - j - 1);
        }
        if(divider != 0) d /= divider;
        doubles.push_back(d);
    }

    return doubles;
}

QString Result::text(){
    return result->text();
}

void Result::clear()
{
    result->clear();
}
