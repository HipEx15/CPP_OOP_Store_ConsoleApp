#pragma once

#include <string>
#include "Products.h"

enum version {OpenGL, DirectX};

class GPU : virtual public Products
{
protected:
	std::string maximumResolution;
	version differentVersions;
};