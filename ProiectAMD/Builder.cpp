#include "Builder.h"

Products* BuildProduct::product(float weight, float height, unsigned short int tdp, unsigned short int nms, unsigned short int memory, float frequency)
{
	Products* P = new Products(weight, height, tdp, nms, memory, frequency);
	return P;
}

Products* BuildCPU::product(float weight, float height, unsigned short int tdp, unsigned short int nms, unsigned short int memory, float frequency)
{
	Products* P = new Products(weight, height, tdp, nms, memory, frequency);
	return P;
}

CPU* BuildCPU::cpu(unsigned short int cores, unsigned short int threads, std::string socket)
{
	CPU* C = new CPU(cores, threads, socket);
	return C;
}

Products* BuildGPU::product(float weight, float height, unsigned short int tdp, unsigned short int nms, unsigned short int memory, float frequency)
{
	Products* P = new Products(weight, height, tdp, nms, memory, frequency);
	return P;
}

GPU* BuildGPU::gpu(std::string maximumResolution, version differentVersions)
{
	GPU* G = new GPU(maximumResolution, differentVersions);
	return G;
}

Products* BuildAPU::product(float weight, float height, unsigned short int tdp, unsigned short int nms, unsigned short int memory, float frequency)
{
	Products* P = new Products(weight, height, tdp, nms, memory, frequency);
	return P;
}

CPU* BuildAPU::cpu(unsigned short int cores, unsigned short int threads, std::string socket)
{
	CPU* C = new CPU(cores, threads, socket);
	return C;
}

GPU* BuildAPU::gpu(std::string maximumResolution, version differentVersions)
{
	GPU* G = new GPU(maximumResolution, differentVersions);
	return G;
}
