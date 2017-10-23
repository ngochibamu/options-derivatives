#ifndef __CppOptions__GenericOption__
#define __CppOptions__GenericOption__

#include <stdio.h>

enum OptionType {
	OptionType_Call,
	OptionType_Put
};


class GenericOption {

public:
	GenericOption(double strike, OptionType type, double cost);
	GenericOption(const GenericOption &genericOption);
	~GenericOption();
	GenericOption &operator=(const GenericOption &genericOption);

	double valueAtExpiration(double underLyingAtExpiration);
	double profitAtExpiration(double underLyingAtExpiration);

private:
	double strike;
	OptionType type;
	double cost;
};
#endif