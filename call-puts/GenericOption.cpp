#include <iostream>
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
GenericOption::~GenericOption() 
{
	
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
	GenericOption option(100.0, OptionType_Put, 1.1);
	double price1 = 120.0;
	double value = option.valueAtExpiration(price1);
	cout << "For 100PUT, value at expiration for price " << price1 << " is " << value << endl;
	double price2 = 85.0;
	value = option.valueAtExpiration(price2);
	cout << "For 85PUT, value at expiration for price " << price2 << " is " << value << endl;
	auto limit = 120.0;
	for(auto price = 80.0; price <= limit; price += 0.1){
		value = option.profitAtExpiration(price);
		cout << price << ", " << value << endl; 
	}
	return 0;
}