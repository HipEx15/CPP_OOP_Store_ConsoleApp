#pragma once

#include "Products.h"
#include "CPU.h"
#include "GPU.h"
#include "APU.h"

class Builder
{
public:
	virtual Products* product(void) = 0;
	virtual CPU* cpu(void) = 0;
	virtual GPU* gpu(void) = 0;
};

class BuildProduct : public Builder
{
	Products* product(float weight, float height, unsigned short int tdp, unsigned short int nms, unsigned short int memory, float frequency);
};

class BuildCPU : public Builder
{
	Products* product(float weight, float height, unsigned short int tdp, unsigned short int nms, unsigned short int memory, float frequency);
	CPU* cpu(unsigned short int cores, unsigned short int threads, std::string socket);
};

class BuildGPU : public Builder
{
	Products* product(float weight, float height, unsigned short int tdp, unsigned short int nms, unsigned short int memory, float frequency);
	GPU* gpu(std::string maximumResolution, version differentVersions);
};

class BuildAPU : public Builder
{
	Products* product(float weight, float height, unsigned short int tdp, unsigned short int nms, unsigned short int memory, float frequency);
	CPU* cpu(unsigned short int cores, unsigned short int threads, std::string socket);
	GPU* gpu(std::string maximumResolution, version differentVersions);
};