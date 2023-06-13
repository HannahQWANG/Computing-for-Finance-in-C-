//
// Created by 企哥哥 on 1/23/23.
//
#include <iostream>
using namespace std;

class Currency
{
public:
    Currency(string symbol, double rate);

    double GetExchangeRate();
    void SetExchangeRate(double rate);
    string GetSymbol();

    double ConvertFromUSD(double value);

private:
    string symbol_;
    double exchange_rate_;
};

