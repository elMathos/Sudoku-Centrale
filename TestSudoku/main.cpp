#include "Region.h"
#include "Grid.h"
#include "RegionHolder.h"
#include "LastCellFinder.h"
#include <stdexcept>
#include <string.h>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	Cell myCell1 =  Cell();
	cout << "Cell value: expected -1, got " << myCell1.GetValue() << "\n";

	Cell myCell2 =  Cell(9);
	cout << "Cell value: expected 9, got " << myCell2.GetValue() << "\n";

	try{
		Cell myCell3 =  Cell(-1);
	}
	catch (const invalid_argument& e){
		cout << e.what();
	}

	try{
		Cell myCell4 = Cell(10);
	}
	catch (const invalid_argument& e){
		cout << e.what();
	}

	try{
		Region myRegion1 = Region("1-3456789");
		cout << "Expected 1, got " << myRegion1.GetCell(0, 0).GetValue() << "\n";
		cout << "Expected -1, got  " << myRegion1.GetCell(0, 1).GetValue() << "\n";
	}
	catch (const invalid_argument& e){
		cout << e.what();
	}

	try{
		Region myRegion1 =  Region("1------a-");
	}
	catch (const invalid_argument& e){
		cout << e.what();
	}

	vector<string> values1 = vector<string>(9);
	values1[0] = "1234-6789";
	for (int i = 1; i < 9; i++)
	{
			values1[i] = "123456789";
	}

	Grid grid1 = Grid(values1);
	RegionHolder regHold1 = RegionHolder(grid1.GetRegion(2,2));
	regHold1.GetCell(0, 0) = 8;
	cout << "Expected 8, got " << grid1.GetRegion(2, 2).GetCell(0, 0).GetValue() << "\n";

	RegionHolder regHold2 = RegionHolder(grid1.GetRegion(0,0));
	RowHolder topRow1 = regHold2.TopRow();
	RowHolder middleRow1 = regHold2.MiddleRow();
	RowHolder bottomRow1 = regHold2.BottomRow();

	LastCellFinder last1 = LastCellFinder(topRow1, middleRow1, bottomRow1);
	cout << "Expected -1, got " << grid1.GetRegion(0, 0).GetCell(1, 1).GetValue() << "\n";
	last1.fill();
	cout << "Expected 5, got " << grid1.GetRegion(0, 0).GetCell(1, 1).GetValue() << "\n";

	return 0;
}
