#include "Grid.h"
#include "IVisitor.h"
#include "RegionHolder.h"
#include "OnlyOneChoiceGlobalVisitor.h"
#include "OnlySquareVisitor.h"
#include "TwoOutOfThreeColumnVisitor.h"
#include "TwoOutOfThreeRowVisitor.h"
#include "RowColumnRegionVisitor.h"

#include "stdio.h"
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
		throw invalid_argument("Exactly 9 regions must be provided.\n");
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

RegionHolder Grid::GetRegion(unsigned char i, unsigned char j)
{
	if (i == 0 && j == 0) return _rNW;
	if (i == 0 && j == 1) return _rN;
	if (i == 0 && j == 2) return _rNE;
	if (i == 1 && j == 0) return _rW;
	if (i == 1 && j == 1) return _rC;
	if (i == 1 && j == 2) return _rE;
	if (i == 2 && j == 0) return _rSW;
	if (i == 2 && j == 1) return _rS;
	if (i == 2 && j == 2) return _rSE;
	else throw invalid_argument("i and j must be between 0 and 2.\n");
}

bool Grid::Accept(const IVisitor& visitor)
{
	return visitor.Visit(*this);
}

NineHolder Grid::GetRow(unsigned char i)
{
	if (i == 0)
	{
		RegionHolder r1 = RegionHolder(_rNW);
		RegionHolder r2 = RegionHolder(_rN);
		RegionHolder r3 = RegionHolder(_rNE);
		TripleHolder t1 = r1.TopRow();
		TripleHolder t2 = r2.TopRow();
		TripleHolder t3 = r3.TopRow();
		return NineHolder(t1, t2, t3);
	}
	if (i == 1)
	{
		RegionHolder r1 = RegionHolder(_rNW);
		RegionHolder r2 = RegionHolder(_rN);
		RegionHolder r3 = RegionHolder(_rNE);
		TripleHolder t1 = r1.MiddleRow();
		TripleHolder t2 = r2.MiddleRow();
		TripleHolder t3 = r3.MiddleRow();
		return NineHolder(t1, t2, t3);
	}
	if (i == 2)
	{
		RegionHolder r1 = RegionHolder(_rNW);
		RegionHolder r2 = RegionHolder(_rN);
		RegionHolder r3 = RegionHolder(_rNE);
		TripleHolder t1 = r1.BottomRow();
		TripleHolder t2 = r2.BottomRow();
		TripleHolder t3 = r3.BottomRow();
		return NineHolder(t1, t2, t3);
	}if (i == 3)
	{
		RegionHolder r1 = RegionHolder(_rW);
		RegionHolder r2 = RegionHolder(_rC);
		RegionHolder r3 = RegionHolder(_rE);
		TripleHolder t1 = r1.TopRow();
		TripleHolder t2 = r2.TopRow();
		TripleHolder t3 = r3.TopRow();
		return NineHolder(t1, t2, t3);
	}
	if (i == 4)
	{
		RegionHolder r1 = RegionHolder(_rW);
		RegionHolder r2 = RegionHolder(_rC);
		RegionHolder r3 = RegionHolder(_rE);
		TripleHolder t1 = r1.MiddleRow();
		TripleHolder t2 = r2.MiddleRow();
		TripleHolder t3 = r3.MiddleRow();
		return NineHolder(t1, t2, t3);
	}
	if (i == 5)
	{
		RegionHolder r1 = RegionHolder(_rW);
		RegionHolder r2 = RegionHolder(_rC);
		RegionHolder r3 = RegionHolder(_rE);
		TripleHolder t1 = r1.BottomRow();
		TripleHolder t2 = r2.BottomRow();
		TripleHolder t3 = r3.BottomRow();
		return NineHolder(t1, t2, t3);
	}if (i == 6)
	{
		RegionHolder r1 = RegionHolder(_rSW);
		RegionHolder r2 = RegionHolder(_rS);
		RegionHolder r3 = RegionHolder(_rSE);
		TripleHolder t1 = r1.TopRow();
		TripleHolder t2 = r2.TopRow();
		TripleHolder t3 = r3.TopRow();
		return NineHolder(t1, t2, t3);
	}
	if (i == 7)
	{
		RegionHolder r1 = RegionHolder(_rSW);
		RegionHolder r2 = RegionHolder(_rS);
		RegionHolder r3 = RegionHolder(_rSE);
		TripleHolder t1 = r1.MiddleRow();
		TripleHolder t2 = r2.MiddleRow();
		TripleHolder t3 = r3.MiddleRow();
		return NineHolder(t1, t2, t3);
	}
	if (i == 8)
	{
		RegionHolder r1 = RegionHolder(_rSW);
		RegionHolder r2 = RegionHolder(_rS);
		RegionHolder r3 = RegionHolder(_rSE);
		TripleHolder t1 = r1.BottomRow();
		TripleHolder t2 = r2.BottomRow();
		TripleHolder t3 = r3.BottomRow();
		return NineHolder(t1, t2, t3);
	}
	else {
		throw invalid_argument("Required row index must be between 0 and 8.\n");

	}
}

NineHolder Grid::GetColumn(unsigned char i)
{
	if (i == 0)
	{
		RegionHolder r1 = RegionHolder(_rNW);
		RegionHolder r2 = RegionHolder(_rW);
		RegionHolder r3 = RegionHolder(_rSW);
		TripleHolder t1 = r1.LeftColumn();
		TripleHolder t2 = r2.LeftColumn();
		TripleHolder t3 = r3.LeftColumn();
		return NineHolder(t1, t2, t3);
	}
	if (i == 1)
	{
		RegionHolder r1 = RegionHolder(_rNW);
		RegionHolder r2 = RegionHolder(_rW);
		RegionHolder r3 = RegionHolder(_rSW);
		TripleHolder t1 = r1.MiddleColumn();
		TripleHolder t2 = r2.MiddleColumn();
		TripleHolder t3 = r3.MiddleColumn();
		return NineHolder(t1, t2, t3);
	}
	if (i == 2)
	{
		RegionHolder r1 = RegionHolder(_rNW);
		RegionHolder r2 = RegionHolder(_rW);
		RegionHolder r3 = RegionHolder(_rSW);
		TripleHolder t1 = r1.RightColumn();
		TripleHolder t2 = r2.RightColumn();
		TripleHolder t3 = r3.RightColumn();
		return NineHolder(t1, t2, t3);
	}if (i == 3)
	{
		RegionHolder r1 = RegionHolder(_rN);
		RegionHolder r2 = RegionHolder(_rC);
		RegionHolder r3 = RegionHolder(_rS);
		TripleHolder t1 = r1.LeftColumn();
		TripleHolder t2 = r2.LeftColumn();
		TripleHolder t3 = r3.LeftColumn();
		return NineHolder(t1, t2, t3);
	}
	if (i == 4)
	{
		RegionHolder r1 = RegionHolder(_rN);
		RegionHolder r2 = RegionHolder(_rC);
		RegionHolder r3 = RegionHolder(_rS);
		TripleHolder t1 = r1.MiddleColumn();
		TripleHolder t2 = r2.MiddleColumn();
		TripleHolder t3 = r3.MiddleColumn();
		return NineHolder(t1, t2, t3);
	}
	if (i == 5)
	{
		RegionHolder r1 = RegionHolder(_rN);
		RegionHolder r2 = RegionHolder(_rC);
		RegionHolder r3 = RegionHolder(_rS);
		TripleHolder t1 = r1.RightColumn();
		TripleHolder t2 = r2.RightColumn();
		TripleHolder t3 = r3.RightColumn();
		return NineHolder(t1, t2, t3);
	}if (i == 6)
	{
		RegionHolder r1 = RegionHolder(_rNE);
		RegionHolder r2 = RegionHolder(_rE);
		RegionHolder r3 = RegionHolder(_rSE);
		TripleHolder t1 = r1.LeftColumn();
		TripleHolder t2 = r2.LeftColumn();
		TripleHolder t3 = r3.LeftColumn();
		return NineHolder(t1, t2, t3);
	}
	if (i == 7)
	{
		RegionHolder r1 = RegionHolder(_rNE);
		RegionHolder r2 = RegionHolder(_rE);
		RegionHolder r3 = RegionHolder(_rSE);
		TripleHolder t1 = r1.MiddleColumn();
		TripleHolder t2 = r2.MiddleColumn();
		TripleHolder t3 = r3.MiddleColumn();
		return NineHolder(t1, t2, t3);
	}
	if (i == 8)
	{
		RegionHolder r1 = RegionHolder(_rNE);
		RegionHolder r2 = RegionHolder(_rE);
		RegionHolder r3 = RegionHolder(_rSE);
		TripleHolder t1 = r1.RightColumn();
		TripleHolder t2 = r2.RightColumn();
		TripleHolder t3 = r3.RightColumn();
		return NineHolder(t1, t2, t3);
	}
	else {
		throw invalid_argument("Required column index must be between 0 and 8.\n");

	}
}

bool Grid::isConsistent()
{
	for (int i = 0; i < 9; i++)
	{
		NineHolder row = GetRow(i);
		if (!row.isConsistent()) return false;

		NineHolder col = GetColumn(i);
		if (!col.isConsistent()) return false;

	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			RegionHolder reg = GetRegion(i, j);
			if (!reg.isConsistent()) return false;
		}
	}
	return true;
}

bool Grid::isFull()
{
	bool full = true;
	// grid fulled if each row is
	for (int i = 0; i < 9; i++)
	{
		NineHolder row = GetRow(i);
		full &= row.isFull();

		if (!full)
			break;
	}

	return full;
}

//TODO more complex strategy, with hypothesis (part 4)
void Grid::SolveWithEasyStrategies()
{
	OnlyOneChoiceGlobalVisitor onlyOneVis;
	OnlySquareVisitor onlySquareVis;
	TwoOutOfThreeColumnVisitor twoOutOfThreeColVis;
	TwoOutOfThreeRowVisitor twoOutOfThreeRowVis;
	RowColumnRegionVisitor rowColRegVis;
	bool gridHasChanged = true;
	bool onlyOneChanged = true;
	bool onlySquareChanged = true;
	bool twoOutOfThreeColChanged = true;
	bool twoOutOfThreeRowChanged = true;
	bool rowColRegChanged = true;

	while (gridHasChanged)
	{
		onlyOneChanged = Accept(onlyOneVis);
		onlySquareChanged = Accept(onlySquareVis);
		twoOutOfThreeColChanged = Accept(twoOutOfThreeColVis);
		twoOutOfThreeRowChanged = Accept(twoOutOfThreeRowVis);
		rowColRegChanged = Accept(rowColRegVis);

		gridHasChanged = onlyOneChanged || onlySquareChanged || twoOutOfThreeColChanged 
			|| twoOutOfThreeRowChanged || rowColRegChanged;
		// if true, at least one visitor has changed the grid
		// we can iterate again
	}
	// check if the grid is full or not
	if (isFull())
		printf("Congratulations, the grid has been solved !\n");
	else
		printf("Sorry, we could not solve this grid.\n");
	//[elmathos]TODO: possibly make this method return a bool rather than printing?
	//In contradiction with the assignment but much more logical to me
}


void Grid::Solve()
{
	Solve();
	if (!isFull())
	{
		//find cell with minimal number of possible choices
		int best_i = 0;
		int best_j = 0;
		int best_values = 9;
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				RegionHolder regHold = GetRegion(i / 3, j / 3);
				if (regHold.GetCell(i % 3, j % 3).IsEmpty())
				{
					NineHolder fullRow = GetRow(i);
					NineHolder fullCol = GetColumn(j);
					int possibleValues = 9;
					for (unsigned char digit = 1; digit < 10; digit++)
					{
						if (regHold.isValuePresent(digit) || fullCol.isValuePresent(digit)
							|| fullRow.isValuePresent(digit))
						{
							possibleValues--;
						}
					}
					if (possibleValues < best_values)
					{
						best_values = possibleValues;
						best_i = i;
						best_j = j;
					}
				}
			}
		}
		//retrieve availables values for cell best_i, best_j:
		RegionHolder regHold = GetRegion(best_i / 3, best_j / 3);
		NineHolder fullRow = GetRow(best_i);
		NineHolder fullCol = GetColumn(best_j);
		set<unsigned char> possibleValueSet;
		for (unsigned char dig = 1; dig < 10; dig++) {
			if (!(regHold.isValuePresent(dig) || fullCol.isValuePresent(dig)
				|| fullRow.isValuePresent(dig))){
				possibleValueSet.insert(dig);
			}
		}
		//making assumption
		set<unsigned char>::iterator pHypothesisValue = possibleValueSet.begin();
		regHold.GetCell(best_i % 3, best_j % 3) = *pHypothesisValue;
		//try to solve without hypothesis
		Solve();
		if (!isConsistent())
		{
		
		}
		else {
			if (isFull()) { return; }
			else
			{
				try{ HypSolve(); }
				catch (...) //todo bad practice
				{
					possibleValueSet.erase(pHypothesisValue);
				}
			}
		}

		

	}
}