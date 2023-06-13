//
// Created by 企哥哥 on 2/3/23.
//
//
// Created by 企哥哥 on 2/3/23.
//
#include "CurrencyFactory.h"
enum CurrencyType{USD=0, AUD, CAD};

CurrencyFactory::CurrencyFactory()
{
    currencies_[USD] = new Currency("USD", "USA", 1.0);
    currencies_[AUD] = new Currency("AUD", "Australia", 1.3);
    currencies_[CAD] = new Currency("CAD", "Canada", 1.1);
}

Currency* CurrencyFactory::GetCurrency(int currencyType)
{
    return currencies_[currencyType];
}

Currency* GetCurrency() const {
    return currencies_[currencyType];
    Currency* GetCurrency(int currencyType);