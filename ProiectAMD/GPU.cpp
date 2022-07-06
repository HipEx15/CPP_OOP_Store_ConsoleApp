#include "GPU.h"

GPU::GPU(void)
{
	this->maximumResolution = "?";
	this->differentVersions = OpenGL;
}

GPU::GPU(std::string maximumResolution, version differentVersions)
{
	this->maximumResolution = maximumResolution;
	this->differentVersions = differentVersions;
}

