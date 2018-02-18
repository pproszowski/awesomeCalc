#ifndef RPNCALCULATOR_H
#define RPNCALCULATOR_H
#include <vector>
#include <QChar>

class RPNcalculator
{
public:
    RPNcalculator(std::vector<std::vector<int>>, std::vector<int>);
private:
    std::vector<std::vector<int>> numbers;
    std::vector<int> operators;
};

#endif // RPNCALCULATOR_H
