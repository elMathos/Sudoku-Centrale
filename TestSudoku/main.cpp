#include "Region.h"
#include "Grid.h"
#include "RegionHolder.h"
#include "stdio.h"
#include <stdexcept>
#include <string.h>

using namespace std;

int main(int argc, char *argv[])
{
	Cell myCell1 =  Cell();
	printf("Expected -1, got %i\n", myCell1.GetValue());

	Cell myCell2 =  Cell(9);
	printf("Expected 9, got %i\n", myCell2.GetValue());

	try{
		Cell myCell3 =  Cell(-1);
	}
	catch (const invalid_argument& e){
		printf(e.what());
	}

	try{
		Cell* myCell4 = new Cell(10);
	}
	catch (const invalid_argument& e){
		printf(e.what());
	}

	try{
		Region myRegion1 = Region("1-3456789");
		printf("Expected 1, got %i\n", myRegion1.Get_cNW().GetValue());
		printf("Expected -1, got %i\n", myRegion1.Get_cN().GetValue());
	}
	catch (const invalid_argument& e){
		printf(e.what());
	}

	try{
		Region myRegion1 =  Region("1------a-");
	}
	catch (const invalid_argument& e){
		printf(e.what());
	}

	vector<string> values = vector<string>(9);
	for (int i = 0; i < 9; i++)
	{

	
		
			values[i] = "123456789";
		
	}

	Grid grid1 = Grid(values);

	RegionHolder regHold1 = RegionHolder(grid1.Get_rSE());
	regHold1.Get_cNW() = 8;
	printf("Expected 8, got %i\n", grid1.Get_rSE().Get_cNW().GetValue());

	return 0;
}
