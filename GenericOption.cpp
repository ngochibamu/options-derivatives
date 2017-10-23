#include "GenericOption.h"

using namespace std;

GenericOption::GenericOption(double strike, OptionType type, double cost) 
: strike(strike), type(type),cost(cost)
{

}

GenericOption::GenericOption(const GenericOption &p)
{

}