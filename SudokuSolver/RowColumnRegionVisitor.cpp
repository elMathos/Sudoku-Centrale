#include "RowColumnRegionVisitor.h"
#include <set>
#include <algorithm>
#include "RegionHolder.h"
#include "NineHolder.h"


using namespace std;

RowColumnRegionVisitor::RowColumnRegionVisitor()
{
}


RowColumnRegionVisitor::~RowColumnRegionVisitor()
{
}


bool RowColumnRegionVisitor::Visit(Grid& ioGrid) const
{
	bool visited = false;
	//test all 81 cells
	for (int iReg = 0; iReg < 3; iReg++)
	{
		for (int jReg = 0; jReg < 3; jReg++)
		{
			RegionHolder regHold = ioGrid.getRegion(iReg, jReg);
			// test all cells of the region
			for (int iCell = 0; iCell < 3; iCell++)
			{
				for (int jCell = 0; jCell < 3; jCell++)
				{
					//TODO: This CAN be speeded up by instantiating the 18 nineholders once and for all before the loop (to be stored in 2 sets)
					if (regHold.getCell(iCell, jCell).IsEmpty())
					{
						NineHolder fullCol = ioGrid.getColumn(3 * jReg + jCell);
						NineHolder fullRow = ioGrid.getRow(3 * iReg + iCell);
						int possibleValues = 9;
						int valueToSet = 0;
						for (unsigned char digit = 1; digit < 10; digit++)
						{
							if (regHold.isValuePresent(digit) || fullCol.isValuePresent(digit)
								|| fullRow.isValuePresent(digit))
							{
								possibleValues--;
							}
							else 
							{
								valueToSet = digit;
							}
						}
						if (possibleValues == 1)
							//we've been exactly 8 times in the if, 1 time in the else
							//we can set the value of the cell to valueToSet
						{
							regHold.getCell(iCell, jCell) = valueToSet;
							visited = true;
						}
					}
				}
			}
		}

	}
	return visited;
}

