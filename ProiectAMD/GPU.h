#pragma once

#include <string>
#include "Products.h"

enum version {OpenGL = 1, DirectX };

class GPU
{
protected:
	std::string maximumResolution;
	version differentVersions;

public:
	GPU(void);
	GPU(std::string maximumResolution, version differentVersions);
	void PrintG(void);
	std::string enumtoString(void);
};