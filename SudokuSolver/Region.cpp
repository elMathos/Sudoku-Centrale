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
	int value = initialValue[0];
	_cNW = Cell(value, allowed);
	value = initialValue[1];
	_cN = Cell(value, allowed);
	value = initialValue[2];
	_cNE = Cell(value, allowed);
	value = initialValue[3];
	_cW = Cell(value, allowed);
	value = initialValue[4];
	_cC = Cell(value, allowed);
	value = initialValue[5];
	_cE = Cell(value, allowed);
	value = initialValue[6];
	_cSW = Cell(value, allowed);
	value = initialValue[7];
	_cS = Cell(value, allowed);
	value = initialValue[8];
	_cSE = Cell(value, allowed);
}


Region::~Region()
{
}

Cell& Region::Get_cNW(){ return _cNW; }
Cell& Region::Get_cN(){ return _cN; }
Cell& Region::Get_cNE(){ return _cNE; }
Cell& Region::Get_cW(){ return _cW; }
Cell& Region::Get_cC(){ return _cC; }
Cell& Region::Get_cE(){ return _cE; }
Cell& Region::Get_cSW(){ return _cSW; }
Cell& Region::Get_cS(){ return _cS; }
Cell& Region::Get_cSE(){ return _cSE; }

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
