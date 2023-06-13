//
// Created by 企哥哥 on 2/23/23.
//

#include "options.h"
#include <cmath>

Option::Option(double K, double T)
        : K_(K), T_(T)
{}

EuropeanCall::EuropeanCall(double K, double T)
        : Option(K,T)
{}

EuropeanPut::EuropeanPut(double K, double T)
        : Option(K,T)
{}

double Option::d1(double S0, double r, double v) {
    return log(S0*exp(r*T_)/K_)/(v*sqrt(T_)) + (v*sqrt(T_))/2;
}

double Option::d2(double S0, double r, double v) {
    return log(S0*exp(r*T_)/K_)/(v*sqrt(T_)) - (v*sqrt(T_))/2;
}

double EuropeanCall::Price(double S0, double r, double v) {
    double d_1 = d1(S0,r,v);
    double d_2 = d2(S0,r,v);
    double n_d1 = cdf(d_1);
    double n_d2 = cdf(d_2);
    return S0*n_d1 - K_*exp(-r*T_)*n_d2;
}

double EuropeanPut::Price(double S0, double r, double v) {
    double d_1 = d1(S0,r,v);
    double d_2 = d2(S0,r,v);
    double n_d1 = cdf(-d_1);
    double n_d2 = cdf(-d_2);
    return -S0*n_d1 + K_*exp(-r*T_)*n_d2;
}

double EuropeanCall::Delta(double S0, double r, double v) {
    double d_1 = d1(S0,r,v);
    return cdf(d_1);
}

double EuropeanPut::Delta(double S0, double r, double v) {
    double d_1 = d1(S0,r,v);
    return cdf(d_1)-1;
}

double Option::Gamma(double S0, double r, double v) {
    double d_1 = d1(S0,r,v);
    return pdf(d_1) / (S0 * v * sqrt(T_));
}
