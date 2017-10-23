#include "GenericOption.h"

using namespace std;

GenericOption::GenericOption(double strike, OptionType type, double cost) 
: strike(strike), type(type),cost(cost)
{

}

GenericOption::GenericOption(const GenericOption &p)
:strike(p.strike), type(p.type), cost(p.cost)
{

}

GenericOption &GenericOption::operator=(const GenericOption &p)
{
	if(this != &p){
		strike = p.strike;
		cost = p.cost;
		type = p.type;
	}
	return *this;
}

double GenericOption::valueAtExpiration(double underlyingAtExpiration)
{
	double value = 0.0;
	if(this->type == OptionType_Call){
		if(underlyingAtExpiration > this->strike)
		{
			value = underlyingAtExpiration - this->strike;
		}
	}
	else
	{
		if(underlyingAtExpiration < this->strike)
		{
			value = this->strike - underlyingAtExpiration;
		}
	}
	return value;
}

double GenericOption::profitAtExpiration(double underlyingAtExpiration)
{
	double profit = 0.0;
	double finalValue = valueAtExpiration(underlyingAtExpiration);
	if(finalValue > this->cost){
		profit = finalValue - this->cost;
	}
	return profit;
}


int main() 
{
	return 0;
}