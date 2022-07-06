#pragma once

#include "Builder.h"
#include "FinalObjects.h"

class Director
{
private:
	Builder* builder;

public:
	Director(Builder* builder);
	FinalProduct* getFP(void);
	FinalCPU* getFC(void);
	FinalGPU* getFG(void);
	FinalAPU* getFA(void);
};