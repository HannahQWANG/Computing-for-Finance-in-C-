//
// Created by 企哥哥 on 2/23/23.
//

#ifndef WANG_HANNAH_ASSIGNMENT_4_OPTIONS_H
#define WANG_HANNAH_ASSIGNMENT_4_OPTIONS_H
#include "functions.h"

class Option {
public:
    Option(double K, double T);
    virtual double Price(double S0, double r, double v) = 0;
    virtual double Delta(double S0, double r, double v) = 0;
    double Gamma(double S0, double r, double v);
protected:
    double d1(double S0, double r, double v);
    double d2(double S0, double r, double v);
    double K_;
    double T_;
};

class EuropeanCall: public Option
{
public:
    EuropeanCall(double K, double T);
    double Price(double S0, double r, double v) override;
    double Delta(double S0, double r, double v) override;
};

class EuropeanPut: public Option
{
public:
    EuropeanPut(double K, double T);
    double Price(double S0, double r, double v) override;
    double Delta(double S0, double r, double v) override;
};





#endif //WANG_HANNAH_ASSIGNMENT_4_OPTIONS_H
