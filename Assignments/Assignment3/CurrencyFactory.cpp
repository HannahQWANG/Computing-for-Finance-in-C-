//
// Created by 企哥哥 on 2/16/23.
//

#include "CurrencyFactory.h"

//Initialize the constructor.
CurrencyFactory::CurrencyFactory()
{
    currencies_[USD] = new Currency("USD",1.0);
    currencies_[EUR] = new Currency("EUR",0.7901);
    currencies_[GBP] = new Currency("GBP",0.6201);
    currencies_[CAD] = new Currency("CAD",1.1150);
    currencies_[AUD] = new Currency("AUD",1.1378);
}

//Delete the free-store objects in the destructor.
CurrencyFactory::~CurrencyFactory()
{
    for (auto iter=currencies_.begin();iter != currencies_.end(); ++iter)
    {
        delete iter->second;
    }
}

//Find the currency.
Currency* CurrencyFactory::GetCurrency(CurrencyType Symbol)
{
    auto iter = currencies_.find(Symbol);
    return iter->second;
}


