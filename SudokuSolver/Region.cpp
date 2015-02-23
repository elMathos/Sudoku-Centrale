#include "Region.h"
#include <vector>
using namespace std;

Region::Region()
{

}

Region::Region(string initialValue)
{
	//TODO test string length
	//TODO test for invalid characters in cell
	//TODO sepcial case for '-'
	int value = initialValue[0] - '0';
	_cNW = Cell(value);
	int value = initialValue[1] - '0';
	_cN = Cell(value);
	//TODO do this for the others cell
}


Region::~Region()
{
}

bool Region::IsFull()
{
	//TODO complete with 7 other ||...
	bool gridIsEmpty = _cNW.IsEmpty() || _cN.IsEmpty();
	//If we get out of the loop, all the cells are full (not empty)
	return true;
}

Region& Region::operator=(const Region& r)
{
	//TODO do this for 8 other cells
	_cNW = r._cNW;
	return *this;
}
