#pragma once

#include "Builder.h"
#include "FinalObjects.h"

class Director
{
private:
	Builder* builder;

public:
	Director(void) {};
	Director(Builder* builder);
	void setBuilder(Builder* builder);
	FinalProduct* getFP(float weight, float height, unsigned short int tdp, unsigned short int nms, unsigned short int memory, float frequency);
	FinalCPU* getFC(float weight, float height, unsigned short int tdp, unsigned short int nms, unsigned short int memory, float frequency, unsigned short int cores, unsigned short int threads, std::string socket);
	FinalGPU* getFG(float weight, float height, unsigned short int tdp, unsigned short int nms, unsigned short int memory, float frequency, std::string maximumResolution, version differentVersions);
	FinalAPU* getFA(float weight, float height, unsigned short int tdp, unsigned short int nms, unsigned short int memory, float frequency, unsigned short int cores, unsigned short int threads, std::string socket, std::string maximumResolution, version differentVersions);
};