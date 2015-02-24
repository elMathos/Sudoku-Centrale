#include "Grid.h"
#include "IVisitor.h"
#include <vector>
#include <string>
using namespace std;

Grid::Grid(vector<string>& values)
{	
	if (values.size() != 9) {
		throw invalid_argument("Length of the string should be 9.\n");
	}

	_rNW = Region(values[0]);
	_rN = Region(values[1]);
	_rNE = Region(values[2]);
	_rW = Region(values[3]);
	_rC = Region(values[4]);
	_rE = Region(values[5]);
	_rSW = Region(values[6]);
	_rS = Region(values[7]);
	_rSE = Region(values[8]);
}

Grid::Grid(vector<Region>& regions)
{
	if (regions.size() != 9) {
		throw invalid_argument("Length of the string should be 9.\n");
	}

	_rNW = regions[0];
	_rN = regions[1];
	_rNE = regions[2];
	_rW = regions[3];
	_rC = regions[4];
	_rE = regions[5];
	_rSW = regions[6];
	_rS = regions[7];
	_rNW = regions[8];
}


Grid::~Grid()
{
}


bool Grid::IsFull(){
	//A grid is full iff its 9 regions are
	bool isFull = _rNW.IsFull() && _rN.IsFull() && _rNE.IsFull() && _rW.IsFull() && _rC.IsFull() && _rE.IsFull() && _rSW.IsFull() && _rS.IsFull() && _rSE.IsFull();
	return isFull;
}

Region& Grid::Get_rNW()
{
	return _rNW;
}

Region& Grid::Get_rN()
{
	return _rN;
}

Region& Grid::Get_rNE()
{
	return _rNE;
}

Region& Grid::Get_rW()
{
	return _rW;
}

Region& Grid::Get_rC()
{
	return _rC;
}

Region& Grid::Get_rE()
{
	return _rE;
}

Region& Grid::Get_rSW()
{
	return _rSW;
}

Region& Grid::Get_rS()
{
	return _rS;
}

Region& Grid::Get_rSE()
{
	return _rSE;
}

bool Grid::Accept(const IVisitor& visitor)
{
	return visitor.Visit(*this);
}