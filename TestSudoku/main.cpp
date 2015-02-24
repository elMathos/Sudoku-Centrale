#include "Region.h"
#include "Grid.h"
#include "RegionHolder.h"
#include "LastCellFinder.h"
#include "stdio.h"
#include <stdexcept>
#include <string.h>

using namespace std;

int main(int argc, char *argv[])
{
	//Other testing
	//Testing branching
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

	vector<string> values1 = vector<string>(9);
	values1[0] = "1234-6789";
	for (int i = 1; i < 9; i++)
	{
			values1[i] = "123456789";
	}

	Grid grid1 = Grid(values1);

	RegionHolder regHold1 = RegionHolder(grid1.Get_rSE());
	regHold1.Get_cNW() = 8;
	printf("Expected 8, got %i\n", grid1.Get_rSE().Get_cNW().GetValue());

	RegionHolder regHold2 = RegionHolder(grid1.Get_rNW());
	RowHolder topRow1 = regHold2.TopRow();
	RowHolder middleRow1 = regHold2.MiddleRow();
	RowHolder bottomRow1 = regHold2.BottomRow();

	LastCellFinder last1 = LastCellFinder(topRow1, middleRow1, bottomRow1);
	printf("Expected -1, got %i\n", grid1.Get_rNW().Get_cC().GetValue());
	last1.fill();
	printf("Expected 5, got %i\n", grid1.Get_rNW().Get_cC().GetValue());



	return 0;
}
