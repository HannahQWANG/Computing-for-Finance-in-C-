//
// Created by 企哥哥 on 1/23/23.
//

#include "Currency.h"

Currency::Currency(string symbol, double rate)
    :symbol_(symbol),exchange_rate_(rate)
{}

string Currency::GetSymbol()
{
    return symbol_;
}

double Currency::GetExchangeRate()
{
    return exchange_rate_;
}
double Currency::ConvertFromUSD(double amount)
{
    return amount * exchange_rate_;
}

void Currency::SetExchangeRate(double rate)
{
    exchange_rate_ = rate;
}