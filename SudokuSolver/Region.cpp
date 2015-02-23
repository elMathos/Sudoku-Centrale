#include "Region.h"
#include <vector>
using namespace std;

Region::Region()
{

}

Region::Region(string initialValue)
{
	if (initialValue.length() != 9) {
		throw invalid_argument("Length of the string should be 9.\n");
	}

	string allowed = "123456789-";
	int value = initialValue[0] - '0';
	_cNW = Cell(value, allowed);
	int value = initialValue[1] - '0';
	_cN = Cell(value, allowed);
	int value = initialValue[2] - '0';
	_cNE = Cell(value, allowed);
	int value = initialValue[3] - '0';
	_cW = Cell(value, allowed);
	int value = initialValue[4] - '0';
	_cC = Cell(value, allowed);
	int value = initialValue[5] - '0';
	_cE = Cell(value, allowed);
	int value = initialValue[6] - '0';
	_cSW = Cell(value, allowed);
	int value = initialValue[7] - '0';
	_cS = Cell(value, allowed);
	int value = initialValue[8] - '0';
	_cSE = Cell(value, allowed);
}


Region::~Region()
{
}

Cell& Region::Get_cNW(){ return _cNW; }
//TODO 9 more accessors

bool Region::IsFull()
{
	bool gridIsEmpty = _cNW.IsEmpty() || _cN.IsEmpty() || _cNE.IsEmpty() || _cW.IsEmpty() || _cC.IsEmpty() || _cE.IsEmpty() || _cSW.IsEmpty() || _cS.IsEmpty() || _cSE.IsEmpty();

	return !gridIsEmpty;
}

Region& Region::operator=(const Region& r)
{
	_cNW = r._cNW;
	_cN = r._cN;
	_cNE = r._cNE;
	_cW = r._cW;
	_cC = r._cC;
	_cE = r._cE;
	_cSW = r._cSW;
	_cS = r._cS;
	_cSE = r._cSE;
	return *this;
}
