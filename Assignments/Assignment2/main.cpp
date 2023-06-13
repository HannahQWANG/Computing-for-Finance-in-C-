#include <iostream>
using namespace std;
#include "Currency.h"
#include "CurrencyConverter.h"

int main() {
    double amount;
    int baseCurrency=0;
    int foreignCurrency=0;
    do{
        cout << "Enter amount (Enter 0 to exit): ";
        cin >> amount;
        if (amount <=0) {
            break;
        }
        cout << "Enter base currency (USD=0, EUR=1, GBP=2, CAD=3, AUD=4, CNY=5, HKD=6): ";
        cin >> baseCurrency;
        cout << "Enter foreign currency (USD=0, EUR=1, GBP=2, CAD=3, AUD=4, CNY=5, HKD=6): ";
        cin >> foreignCurrency;
        if (baseCurrency == 0 && foreignCurrency >= 0 && foreignCurrency <= 6){
            amount = ConvertFromUSD(static_cast<CurrencyType>(foreignCurrency), amount);
            cout << "Amount in foreign: " << amount << endl;
        }
        else if (baseCurrency > 0 && baseCurrency <= 6 && foreignCurrency >=0 && foreignCurrency <=6){
            amount = 1/ConvertFromUSD(static_cast<CurrencyType>(baseCurrency), 1/amount);
            amount = ConvertFromUSD(static_cast<CurrencyType>(foreignCurrency), amount);
            cout << "Amount in foreign: " << amount << endl;
        }
        else{
            cout << "Currency Type not included." << endl;
        }
    }while (amount >0);
}
