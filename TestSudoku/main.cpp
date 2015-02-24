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
		printf("Expected 1, got %i\n", myRegion1.GetCell(0,0).GetValue());
		printf("Expected -1, got %i\n", myRegion1.GetCell(0,1).GetValue());
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

	RegionHolder regHold1 = RegionHolder(grid1.GetRegion(2,2));
	regHold1.Get_cNW() = 8;
	printf("Expected 8, got %i\n", grid1.GetRegion(2,2).GetCell(0,0).GetValue());

	RegionHolder regHold2 = RegionHolder(grid1.GetRegion(0,0));
	RowHolder topRow1 = regHold2.TopRow();
	RowHolder middleRow1 = regHold2.MiddleRow();
	RowHolder bottomRow1 = regHold2.BottomRow();

	LastCellFinder last1 = LastCellFinder(topRow1, middleRow1, bottomRow1);
	printf("Expected -1, got %i\n", grid1.GetRegion(0, 0).GetCell(1,1).GetValue());
	last1.fill();
	printf("Expected 5, got %i\n", grid1.GetRegion(0, 0).GetCell(1,1).GetValue());


	return 0;
}
