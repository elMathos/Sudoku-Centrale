#pragma once

#ifdef SUDOKUSOLVER_EXPORTS
#define ExportedByDll __declspec(dllexport)
#else
#define ExportedByDll __declspec(dllimport)
#endif

class IVisitor;

#include "Region.h"
#include <string>
#include <vector>
#include <memory>

using namespace std;


class ExportedByDll Grid
{
public:
	//TODO fix the constructor when prof specifies input format of grids.
	Grid(vector<string>& values);
	Grid(vector<Region>& regions);
	~Grid();
	bool IsFull();
	Region& GetRegion(unsigned char i, unsigned char j);
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

