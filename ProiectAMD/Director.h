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
	FinalProduct* getFP(float weight, float height, unsigned short int tdp, unsigned short int nms, unsigned short int memory, float frequency, float priceTag, std::string Name, std::string Date);
	FinalCPU* getFC(float weight, float height, unsigned short int tdp, unsigned short int nms, unsigned short int memory, float frequency, float priceTag, std::string Name, std::string Date, unsigned short int cores, unsigned short int threads, std::string socket);
	FinalGPU* getFG(float weight, float height, unsigned short int tdp, unsigned short int nms, unsigned short int memory, float frequency, float priceTag, std::string Name, std::string Date, std::string maximumResolution, version differentVersions);
	FinalAPU* getFA(float weight, float height, unsigned short int tdp, unsigned short int nms, unsigned short int memory, float frequency, float priceTag, std::string Name, std::string Date, unsigned short int cores, unsigned short int threads, std::string socket, std::string maximumResolution, version differentVersions);
};