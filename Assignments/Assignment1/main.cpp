#include <iostream>
using namespace std;
#include "ConvertFromUSD.h"
#include "ConvertToUSD.h"

int main() {
    double amount;
    int baseCurrency;
    int foreignCurrency;
    do{
        cout << "Enter amount (Enter 0 to exit): ";
        cin >> amount;
        if (amount <=0){
            break;
        }
        cout << "Enter base currency (USD=0, EUR=1, GBP=2, CAD=3, AUD=4, CNY=5, HKD=6): ";
        cin >> baseCurrency;
        cout << "Enter foreign currency (USD=0, EUR=1, GBP=2, CAD=3, AUD=4, CNY=5, HKD=6): ";
        cin >> foreignCurrency;
        if (baseCurrency == 0 && foreignCurrency >= 0 && foreignCurrency <= 6){
            amount = ConvertFromUSD(amount, foreignCurrency);
            cout << "Amount in foreign: " << amount << endl;
        }
        else if (baseCurrency > 0 && baseCurrency <= 6 && foreignCurrency >=0 && foreignCurrency <=6){
            amount = ConvertToUSD(amount, baseCurrency);
            amount = ConvertFromUSD(amount, foreignCurrency);
            cout << "Amount in foreign: " << amount << endl;
        }
        else{
            cout << "Currency Type not included." << endl;
        }
    }while (amount >0);
}



auto [it, inserted] = currencies_.emplace(currencyType, nullptr);
if (inserted) {
it->second = new Currency(currencyType);
}
return it->second;


class Fruit {
public:
    static Fruit* GetFruit(const std::string& type);
    static void PrintCurrentTypes();

private:
    // Note: constructor private forcing one to use static |GetFruit|.
    Fruit(const std::string& type) : type_(type) {}

    static std::map<std::string, Fruit*> types;

    std::string type_;
};

// static
std::map<std::string, Fruit*> Fruit::types;

// Lazy Factory method, gets the |Fruit| instance associated with a certain
// |type|.  Creates new ones as needed.
Fruit* Fruit::GetFruit(const std::string& type) {
    auto [it, inserted] = types.emplace(type, nullptr);
    if (inserted) {
        it->second = new Fruit(type);
    }
    return it->second;
}

