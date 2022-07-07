#include <iostream>
#include <vector>
#include "Administrator.h"

int User::ID = 0;

int main(void)
{
	FinalProduct* P;
	FinalCPU* C;
	FinalGPU* G;
	FinalAPU* A;

	BuildCPU BC;
	BuildGPU BG;
	BuildAPU BA;
	Admin Admin;

	Admin.setBuilder(&BC);
	C = Admin.getFC(54,23,44,4,8,3.6,6,12,(std::string)"AM4");
	//C->Print();

	Admin.setBuilder(&BG);
	G = Admin.getFG(22, 14, 65, 2, 7, 3.6, (std::string)"1920x1080", DirectX);
	//G->Print();

	Admin.setBuilder(&BA);
	A = Admin.getFA(12, 13, 14, 15, 16, 17.5, 4, 8, (std::string)"AM4+", (std::string)"1280x760", OpenGL);
	//A->Print();


	//VECTORUL CU TOATE OBIECTELE
	//TO DO -> FILTRELE pe VECTOR 
	
	/*Inventory.push_back(C);
	Inventory.push_back(G);
	Inventory.push_back(A);*/

	Admin.addProduct(C);
	Admin.addProduct(G);
	Admin.addProduct(A);

	Admin.printAllProducts();

	return 0;
}