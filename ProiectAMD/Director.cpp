#include "Director.h"

Director::Director(Builder* builder)
{
	this->builder = builder;
}

void Director::setBuilder(Builder* builder)
{
	this->builder = builder;
}

FinalProduct* Director::getFP(float weight, float height, unsigned short int tdp, unsigned short int nms, unsigned short int memory, float frequency)
{
	FinalProduct* FP = new FinalProduct();

	FP->p = builder->product(weight,height,tdp,nms,memory,frequency);

	return FP;
}

FinalCPU* Director::getFC(float weight, float height, unsigned short int tdp, unsigned short int nms, unsigned short int memory, float frequency, unsigned short int cores, unsigned short int threads, std::string socket)
{
	FinalCPU* FC = new FinalCPU();

	FC->p = builder->product(weight, height, tdp, nms, memory, frequency);
	FC->c = builder->cpu(cores, threads, socket);

	return FC;
}

FinalGPU* Director::getFG(float weight, float height, unsigned short int tdp, unsigned short int nms, unsigned short int memory, float frequency, std::string maximumResolution, version differentVersions)
{
	FinalGPU* FG = new FinalGPU();

	FG->p = builder->product(weight, height, tdp, nms, memory, frequency);
	FG->g = builder->gpu(maximumResolution, differentVersions);

	return FG;
}

FinalAPU* Director::getFA(float weight, float height, unsigned short int tdp, unsigned short int nms, unsigned short int memory, float frequency, unsigned short int cores, unsigned short int threads, std::string socket, std::string maximumResolution, version differentVersions)
{
	FinalAPU* FA = new FinalAPU();

	FA->p = builder->product(weight, height, tdp, nms, memory, frequency);
	FA->c = builder->cpu(cores, threads, socket);
	FA->g = builder->gpu(maximumResolution, differentVersions);

	return FA;
}
