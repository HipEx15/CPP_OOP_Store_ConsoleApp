#pragma once

#include <string>
#include "Products.h"

enum version {OpenGL, DirectX};

class GPU
{
protected:
	std::string maximumResolution;
	version differentVersions;

public:
	GPU(void);
	GPU(std::string maximumResolution, version differentVersions);
};