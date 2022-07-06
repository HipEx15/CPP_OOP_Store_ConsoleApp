#pragma once

#include "CPU.h"
#include "GPU.h"

class APU : public CPU, public GPU
{
public:
	APU(void);
	APU(unsigned short int cores, unsigned short int threads, std::string socket, std::string maximumResolution, version differentVersions);
};