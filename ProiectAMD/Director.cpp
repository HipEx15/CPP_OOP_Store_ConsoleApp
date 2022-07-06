#include "Director.h"

Director::Director(Builder* builder)
{
	this->builder = builder;
}

FinalProduct* Director::getFP(void)
{
	FinalProduct* FP = new FinalProduct();

	FP->p = builder->product();

	return FP;
}

FinalCPU* Director::getFC(void)
{
	FinalCPU* FC = new FinalCPU();

	FC->p = builder->product();
	FC->c = builder->cpu();

	return FC;
}

FinalGPU* Director::getFG(void)
{
	FinalGPU* FG = new FinalGPU();

	FG->p = builder->product();
	FG->g = builder->gpu();

	return FG;
}

FinalAPU* Director::getFA(void)
{
	FinalAPU* FA = new FinalAPU();

	FA->p = builder->product();
	FA->c = builder->cpu();
	FA->g = builder->gpu();

	return FA;
}
