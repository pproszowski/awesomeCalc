#ifndef RESULT_H
#define RESULT_H
#include <QLabel>
#include <stack>
#include <sstream>

class Result
{
public:
    Result(QLabel*);
    void calculateAndDisplay(std::vector< std::vector<int>>,
                             std::vector<int>);
    QString text();
    bool firstIsMoreImportantOrEqual(int,int);
    void clear();
    std::vector<double> convertToDoubleVector(std::vector<std::vector<int>> n);
    double calculate(double, double, int);
private:
    QLabel* result;
};

#endif // RESULT_H
