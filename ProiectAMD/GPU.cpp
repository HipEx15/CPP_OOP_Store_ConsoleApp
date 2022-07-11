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

void GPU::PrintG(void)
{
	std::cout << "\n\tMaximum resolution: " << this->getMaximumResolution() << "\n\tVersion: " << this->enumtoString();
}

std::string GPU::enumtoString(void)
{
	if (this->differentVersions == 1)
		return "OpenGL";
	else if (this->differentVersions == 2)
		return "DirectX";
}

std::string GPU::getMaximumResolution(void)
{
	return this->maximumResolution;
}

version GPU::getDifferentVersions(void)
{
	return this->differentVersions;
}

