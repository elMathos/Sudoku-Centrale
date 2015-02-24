#pragma once

#ifdef SUDOKUSOLVER_EXPORTS
#define ExportedByDll __declspec(dllexport)
#else
#define ExportedByDll __declspec(dllimport)
#endif

class IVisitor;

#include "Region.h"
#include "NineHolder.h"
#include <string>
#include <vector>

using namespace std;


class ExportedByDll Grid
{
public:
	//TODO fix the constructor when prof specifies input format of grids.
	Grid(vector<string>& values);
	Grid(vector<Region>& regions);
	~Grid();
	Region& GetRegion(unsigned char i, unsigned char j);
	NineHolder GetRow(unsigned char i);
	//TODO implement GetColumn
	bool IsFull();
	bool Accept(const IVisitor& visitor);

private:
	Region _rNW;
	Region _rN;
	Region _rNE;
	Region _rW;
	Region _rC;
	Region _rE;
	Region _rSW;
	Region _rS;
	Region _rSE;
};
