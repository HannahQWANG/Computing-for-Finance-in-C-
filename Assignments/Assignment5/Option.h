//
// Created by 企哥哥 on 3/3/23.
//

#ifndef WANG_HANNAH_ASSIGNMENT_5_OPTION_H
#define WANG_HANNAH_ASSIGNMENT_5_OPTION_H
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;

class Option {
public:
    Option(double K, double T);
    double GetTimeToExpiration() const;
    virtual double GetExpirationPayoff(double ST) const = 0;
protected:
    double K_;
    double T_;
};

class EuropeanCall: public Option
{
public:
    EuropeanCall(double K, double T);
    double GetExpirationPayoff(double ST) const override;
};

class EuropeanPut: public Option
{
public:
    EuropeanPut(double K, double T);
    double GetExpirationPayoff(double ST) const override;
};


class MCPricer
{
public:
    double Price(const Option& option,
                 double S0, double sigma, double r,
                 unsigned long paths);
};


#endif //WANG_HANNAH_ASSIGNMENT_5_OPTION_H
