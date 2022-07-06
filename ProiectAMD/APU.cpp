#include "APU.h"

APU::APU(void)
{
	this->cores = 0;
	this->threads = 0;
	this->socket = "?";
	this->maximumResolution = "?";
	this->differentVersions = OpenGL;
}

APU::APU(unsigned short int cores, unsigned short int threads, std::string socket, std::string maximumResolution, version differentVersions)
{
	this->cores = cores;
	this->threads = threads;
	this->socket = socket;
	this->maximumResolution = maximumResolution;
	this->differentVersions = differentVersions;
}
