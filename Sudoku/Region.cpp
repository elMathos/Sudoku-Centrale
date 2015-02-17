#include "Region.h"
#include <vector>
using namespace std;

Region::Region()
{

}

Region::Region(string initialValue)
{
	char* letters = (char*)initialValue.c_str();

	_cells = vector<vector<Cell>>(L);

	for (int i = 0; i < L; i++)
	{
		_cells[i] = vector<Cell>(L);

		for (int j = 0; j < L; j++)
		{
			//TODO: test for invalid characters
			int value = initialValue[i*L + j] - '0';
			
			_cells[i][j] = Cell(value);
		}
	}
}


Region::~Region()
{
}

bool Region::IsFull()
{
	//TODO : to be filled
	return false;
}

Region& Region::operator=(const Region& r)
{
	_cells = r._cells;
	return *this;
}
