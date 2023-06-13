#include <iostream>
using namespace std;
#include "CurrencyFactory.h"

//I made changes with change 2,3,4,5,6.

int main() {
    CurrencyFactory factory;
    double amount;
    int baseCurrency = 0;
    int foreignCurrency = 0;
    do{
        cout << "Enter amount (Enter 0 to exit): ";
        cin >> amount;
        //If amount is not valid, quit the loop.
        if (amount <=0)
        {
            break;
        }
        cout << "Enter base currency (USD=0, EUR=1, GBP=2, CAD=3, AUD=4): ";
        cin >> baseCurrency;
        cout << "Enter foreign currency (USD=0, EUR=1, GBP=2, CAD=3, AUD=4): ";
        cin >> foreignCurrency;
        //Creat Currency.
        Currency* base = factory.GetCurrency(static_cast<CurrencyType>(baseCurrency));
        Currency* foreign = factory.GetCurrency(static_cast<CurrencyType>(foreignCurrency));
        if (baseCurrency >= 0 && baseCurrency <=4 && foreignCurrency >=0 && foreignCurrency <=4){
            amount = 1/(*base).ConvertFromUSD(1/amount);
            amount = (*foreign).ConvertFromUSD(amount);
            cout << "The amount is: " << amount << endl;
        }
        else{
            cout << "Currency not included." << endl;
        }
    }while (amount >0);
}
