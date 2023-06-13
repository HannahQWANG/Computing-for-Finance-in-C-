#include <iostream>
#include "Option.h"
using namespace std;

int main() {
    MCPricer mc;
    double S0 = 100.0;
    double sigma = 0.3;
    double r = 0.01;
    double T = 2.0;
    double K = 100.0;
    unsigned long paths[3] = {10000, 100000, 1000000};
    EuropeanCall call(K,T);
    EuropeanPut put(K, T);
    for(int i = 0; i<3; i++){
        double callPrice = mc.Price(call, S0, sigma, r, paths[i]);
        cout << "Call Price: " << callPrice << endl;
        double putPrice = mc.Price(put, S0, sigma, r, paths[i]);
        cout << "Put Price: " << putPrice << endl;
    }
}
