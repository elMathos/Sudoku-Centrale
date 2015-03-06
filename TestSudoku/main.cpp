#include "Region.h"
#include "Grid.h"
#include "RegionHolder.h"
#include "LastCellFinder.h"
#include <stdexcept>
#include <string.h>
#include <iostream>

using namespace std;

// a few tests are here, the rest can be found as UT in unittest1.cpp (project SudokuUnitTest)

int main(int argc, char *argv[])
{
	Cell myCell1;
	cout << "Cell value: expected -1, got " << myCell1.getValue() << "\n";

	Cell myCell2(9);
	cout << "Cell value: expected 9, got " << myCell2.getValue() << "\n";

	try{
		Cell myCell3(-1);
	}
	catch (const invalid_argument& e){
		cout << e.what();
	}

	try{
		Cell myCell4(10);
	}
	catch (const invalid_argument& e){
		cout << e.what();
	}

	try{
		Region myRegion1("1-3456789");
		cout << "Expected 1, got " << myRegion1.getCell(0, 0).getValue() << "\n";
		cout << "Expected -1, got  " << myRegion1.getCell(0, 1).getValue() << "\n";
	}
	catch (const invalid_argument& e){
		cout << e.what();
	}

	try{
		Region myRegion1("1------a-");
	}
	catch (const invalid_argument& e){
		cout << e.what();
	}

	vector<string> values1 = vector<string>(9);
	values1[0] = "1234-6789";
	for (unsigned char i = 1; i < 9; i++)
	{
			values1[i] = "123456789";
	}

	Grid grid1(values1);
	RegionHolder regHold1(grid1.getRegion(2,2));
	regHold1.getCell(0, 0) = 8;
	cout << "Expected 8, got " << grid1.getRegion(2, 2).getCell(0, 0).getValue() << "\n";

	RegionHolder regHold2(grid1.getRegion(0,0));
	RowHolder topRow1 = regHold2.TopRow();
	RowHolder middleRow1 = regHold2.MiddleRow();
	RowHolder bottomRow1 = regHold2.BottomRow();

	LastCellFinder last1(topRow1, middleRow1, bottomRow1);
	cout << "Expected -1, got " << grid1.getRegion(0, 0).getCell(1, 1).getValue() << "\n";
	last1.fill();
	cout << "Expected 5, got " << grid1.getRegion(0, 0).getCell(1, 1).getValue() << "\n";

	return 0;
}
