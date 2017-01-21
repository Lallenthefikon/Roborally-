#include "GenericFunctions.h"


GenericFunctions::~GenericFunctions()
{
}

GenericFunctions* GenericFunctions::getInstance(){
	static GenericFunctions genericfunctions;
	return &genericfunctions;
}


// Privates

GenericFunctions::GenericFunctions()
{
}
