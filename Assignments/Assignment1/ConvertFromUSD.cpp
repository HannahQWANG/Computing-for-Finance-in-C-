//
// Created by 企哥哥 on 1/20/23.
//


#include <iostream>
using namespace std;

enum CurrencyType{USD=0, EUR=1, GBP=2, CAD=3, AUD=4, CNY=5, HKD=6};
double ConvertFromUSD(double amount, int currencyType){
    double rate;
    switch (currencyType){
        case EUR:
            rate = 0.88;
            break;
        case GBP:
            rate = 0.73;
            break;
        case CAD:
            rate = 1.25;
            break;
        case AUD:
            rate = 1.39;
            break;
        case CNY:
            rate = 6.78;
            break;
        case HKD:
            rate = 7.83;
            break;
        default:
            rate = 1.0;
    }
    return rate * amount;
}

