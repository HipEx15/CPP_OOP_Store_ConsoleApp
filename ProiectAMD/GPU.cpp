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
	std::cout << "\n\tMaximum resolution: " << this->maximumResolution << "\n\tVersion: " << this->enumtoString();
}

std::string GPU::enumtoString(void)
{
	/*if (this->differentVersions == 1)
		return "OpenGL";
	else if (this->differentVersions == 2)
		return "DirectX";*/

	switch (this->differentVersions)
	{
	case 1:
		return "OpenGL";
	case 2:
		return "DirectX";
	default:
		break;
	}
}

