#include <iostream>
#include <vector>
#include "Director.h"

using namespace std;

int main(void)
{
	FinalProduct* P;
	FinalCPU* C;
	FinalGPU* G;
	FinalAPU* A;

	BuildCPU BC;
	BuildGPU BG;
	BuildAPU BA;
	Director Dir;

	Dir.setBuilder(&BC);
	C = Dir.getFC(54,23,44,4,8,3.6,6,12,(std::string)"AM4");
	//C->Print();

	Dir.setBuilder(&BG);
	G = Dir.getFG(22, 14, 65, 2, 7, 3.6, (std::string)"1920x1080", DirectX);
	//G->Print();

	Dir.setBuilder(&BA);
	A = Dir.getFA(12, 13, 14, 15, 16, 17.5, 4, 8, (std::string)"AM4+", (std::string)"1280x760", OpenGL);
	//A->Print();


	//VECTORUL CU TOATE OBIECTELE
	std::vector<Inventory*> Inventory;
	Inventory.push_back(C);
	Inventory.push_back(G);
	Inventory.push_back(A);

	for (auto i : Inventory)
		i->Print();

	return 0;
}