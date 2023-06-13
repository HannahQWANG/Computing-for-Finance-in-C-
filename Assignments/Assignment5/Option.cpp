//
// Created by 企哥哥 on 3/3/23.
//

#include "Option.h"
#include <cstdlib>
const double PI = 3.14;
double BoxMuller()
{
    double x = static_cast<double>(rand()) / RAND_MAX;
    double y = static_cast<double>(rand()) /  RAND_MAX;
    double z = sqrt(-2.0*log(x)) * cos(2*PI*y);
    return z;
}
Option::Option(double K, double T)
        : K_(K), T_(T)
{}

EuropeanCall::EuropeanCall(double K, double T)
        : Option(K,T)
{}

EuropeanPut::EuropeanPut(double K, double T)
        : Option(K,T)
{}

double EuropeanCall::GetExpirationPayoff(double ST) const
{
    return max(ST-K_,0.0);
}

double EuropeanPut::GetExpirationPayoff(double ST) const
{
    return max(K_-ST,0.0);
}

double Option::GetTimeToExpiration() const
{
    return T_;
}

double MCPricer::Price(const Option& option, double S0, double sigma, double r, unsigned long paths) {
    double T = option.GetTimeToExpiration();
    double sum_path = 0;
    for (unsigned int i=0; i<paths; ++i)
    {
        double z_i = BoxMuller();
        double ST_i = S0*exp((r-sigma*sigma/2.0)*T + sigma*z_i*sqrt(T));
        double payoff = option.GetExpirationPayoff(ST_i);
        sum_path += payoff;
    }
    return exp(-r*T)*sum_path/paths;
}