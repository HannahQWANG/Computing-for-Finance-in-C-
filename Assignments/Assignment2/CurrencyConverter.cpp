//
// Created by 企哥哥 on 1/23/23.
//

#include "CurrencyConverter.h"
#include "Currency.h"

double ConvertFromUSD(CurrencyType currencyType, double amount)
{
    double rate = 1.0;
    double foreignAmount = 0;
    switch (currencyType)
    {
        case CAD:
        {
            Currency cad("CAD", 1.24);
            foreignAmount = cad.ConvertFromUSD(amount);
            break;
        }
        case GBP:
        {
            Currency gbp("GBP", 0.74);
            foreignAmount = gbp.ConvertFromUSD(amount);
            break;
        }
        case EUR:
        {
            Currency eur("EUR", 0.88);
            foreignAmount = eur.ConvertFromUSD(amount);
            break;
        }
        case AUD:
        {
            Currency aud("AUD", 1.39);
            foreignAmount = aud.ConvertFromUSD(amount);
            break;
        }
        case CNY:
        {
            Currency cny("CNY", 6.78);
            foreignAmount = cny.ConvertFromUSD(amount);
            break;
        }
        case HKD:
        {
            Currency hkd("HKD", 7.83);
            foreignAmount = hkd.ConvertFromUSD(amount);
            break;
        }
        default:
        {
            Currency usd("USD", 1.0);
            foreignAmount = usd.ConvertFromUSD(amount);
        }
    }
    return foreignAmount;
}