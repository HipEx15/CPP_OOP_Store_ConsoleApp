#include <iostream>
#include "Director.h"

using namespace std;

int main(void)
{
	FinalProduct* P;
	FinalCPU* C;
	FinalGPU* G;
	FinalAPU* A;

	BuildCPU B;
	Director Dir(&B);

	C = Dir.getFC(54,23,44,4,8,3.6,6,12,(std::string)"AM4");
	C->PrintC();
	return 0;
}