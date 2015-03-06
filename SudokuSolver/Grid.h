#pragma once

#ifdef SUDOKUSOLVER_EXPORTS
#define ExportedByDll __declspec(dllexport)
#else
#define ExportedByDll __declspec(dllimport)
#endif

class IVisitor;

#include "RegionHolder.h"
#include "NineHolder.h"
#include <string>
#include <vector>
#include <set>

using namespace std;


class ExportedByDll Grid
{
public:
	//TODO fix the constructor when prof specifies input format of grids.
	Grid(vector<string>& values);
	Grid(vector<Region>& regions);
	~Grid();
	RegionHolder getRegion(unsigned char i, unsigned char j);
	NineHolder getRow(unsigned char i);
	NineHolder getColumn(unsigned char i);
	bool Accept(const IVisitor& visitor);
	bool isConsistent();
	bool isFull();
	set<unsigned char> getPossibleValues(unsigned char rowIdx, unsigned char colIdx);
	vector<unsigned char> getIndicesCellWithLessChoices();
	void SolveWithEasyStrategies();
	void Solve();

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
