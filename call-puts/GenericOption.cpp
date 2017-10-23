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

GenericOption::&GenericOption operator=(const GenericOption &p)
{
	if(this != &p){
		strike = p.strike;
		cost = p.cost;
		type = p.type;
	}
	return *this;
}

double valueAtExpiration(double underlyingAtExpiration)
{
	double value = 0.0
	if(type == OptionType_Call){
		if(underlyingAtExpiration > strike)
		{
			value = underlyingAtExpiration - strike;
		}
	}
	else
	{
		if(underlyingAtExpiration < strike)
		{
			value = strike - underlyingAtExpiration;
		}
	}
	return value;
}