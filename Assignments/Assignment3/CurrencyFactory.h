//
// Created by 企哥哥 on 2/16/23.
//
#include "Currency.h"

class CurrencyFactory
{
public:
    //Create the constructor.
    CurrencyFactory();
    //Create the destructor.
    ~CurrencyFactory();
    Currency* GetCurrency(CurrencyType Symbol);
private:
    //Define the map to store Currency objects.
    map<CurrencyType, Currency*> currencies_;
};
