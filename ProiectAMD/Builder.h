#pragma once

#include "Products.h"
#include "CPU.h"
#include "GPU.h"
#include "APU.h"

class Builder
{
public:
	virtual Products* product(float weight, float height, unsigned short int tdp, unsigned short int nms, unsigned short int memory, float frequency) { return NULL; };
	virtual CPU* cpu(unsigned short int cores, unsigned short int threads, std::string socket) { return NULL; };
	virtual GPU* gpu(std::string maximumResolution, version differentVersions) { return NULL; };
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