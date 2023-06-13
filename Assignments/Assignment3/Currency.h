//
// Created by 企哥哥 on 1/23/23.
//
#include <iostream>
#include <string>
#include <map>
using namespace std;
enum CurrencyType{USD=0, EUR, GBP, CAD, AUD};
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

