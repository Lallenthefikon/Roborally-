#include "variablesAndConstants.h"


variablesAndConstants::~variablesAndConstants()
{
}

variablesAndConstants* variablesAndConstants::getInstance(){
	static variablesAndConstants variablesandconstants;
	return &variablesandconstants;
}

// Privates
variablesAndConstants::variablesAndConstants()
{
}

