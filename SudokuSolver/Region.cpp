#include "Region.h"
#include <vector>
using namespace std;

Region::Region()
{

}

Region::Region(string initialValue)
{
	char* letters = (char*)initialValue.c_str();

	cells = vector<vector<Cell>>(L);

	for (int i = 0; i < L; i++)
	{
		cells[i] = vector<Cell>(L);

		for (int j = 0; j < L; j++)
		{
			//TODO: test for invalid characters
			int value = initialValue[i*L + j] - '0';
			
			cells[i][j] = Cell(value);
		}
	}
}


Region::~Region()
{
}

bool Region::IsFull()
{
	for (int i = 0; i < L; i++){
		for (int j = 0; j < L; j++){
			if (cells[i][j].IsEmpty()) {
				return false;
			}
		}
	}
	//If we get out of the loop, all the cells are full (not empty)
	return true;
}

Region& Region::operator=(const Region& r)
{
	cells = r.cells;
	return *this;
}
