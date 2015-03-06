#include "OnlySquareVisitor.h"
#include "ValueEliminator.h"

OnlySquareVisitor::OnlySquareVisitor()
{
}


OnlySquareVisitor::~OnlySquareVisitor()
{
}

bool OnlySquareVisitor::Visit(Grid& ioGrid) const
{
	bool visited = false;
	// on rows :
	for (unsigned char i = 0; i < 9; i++)
	{
		NineHolder fullRow = ioGrid.getRow(i);
		ValueEliminator valueEliminator;
		fullRow.flagValues(valueEliminator);
		set<unsigned char> availableValues = valueEliminator.availableValue();
		if (availableValues.size() == 2) // exactly two empty cells
		{
			// get the two missing values
			set<unsigned char>::iterator iter = availableValues.begin();
			int firstValue = *iter;
			iter++;
			int secondValue = *iter;

			// get the two columns corresponding to the two empty cells
			int firstColumnIndex = -1;
			int secondColumnIndex = -1;
			int firstRegionColIndex = -1;
			int secondRegionColIndex = -1;
			for (int j = 0; j < 9; j++)
			{
				if (fullRow.getCell(j).IsEmpty())
				{
					if (firstColumnIndex == -1)
					{
						firstColumnIndex = j;
						firstRegionColIndex = j / 3;
					}						
					else
					{
						secondColumnIndex = j;
						secondRegionColIndex = j / 3;
					}		
				}
			}
			NineHolder firstColumn = ioGrid.getColumn(firstColumnIndex);
			NineHolder secondColumn = ioGrid.getColumn(secondColumnIndex);
			RegionHolder firstRegion = ioGrid.getRegion(i/3, firstRegionColIndex);
			RegionHolder secondRegion = ioGrid.getRegion(i/3, secondRegionColIndex);

			// check if one of the two missing values already in firstColumn or secondColumn
			if (firstColumn.isValuePresent(firstValue))
			{
				fullRow.getCell(firstColumnIndex) = secondValue;
				fullRow.getCell(secondColumnIndex) = firstValue;
				visited = true;
			}
			else if (firstColumn.isValuePresent(secondValue))
			{
				fullRow.getCell(firstColumnIndex) = firstValue;
				fullRow.getCell(secondColumnIndex) = secondValue;
				visited = true;
			}
			else if (secondColumn.isValuePresent(firstValue))
			{
				fullRow.getCell(firstColumnIndex) = firstValue;
				fullRow.getCell(secondColumnIndex) = secondValue;
				visited = true;
			}
			else if (secondColumn.isValuePresent(secondValue))
			{
				fullRow.getCell(firstColumnIndex) = secondValue;
				fullRow.getCell(secondColumnIndex) = firstValue;
				visited = true;
			}
			
			//WARNING: do not execute this if the value has already been set!
			//Because we change the value we just assigned...
			else{
				// check if one of the two missing values already in firstRegion or secondRegion
				if (firstRegionColIndex != secondRegionColIndex)
					// two empty celles are in different regions
				{
					if (firstRegion.isValuePresent(firstValue))
					{
						fullRow.getCell(firstColumnIndex) = secondValue;
						fullRow.getCell(secondColumnIndex) = firstValue;
						visited = true;
					}
					else if (firstRegion.isValuePresent(secondValue))
					{
						fullRow.getCell(firstColumnIndex) = firstValue;
						fullRow.getCell(secondColumnIndex) = secondValue;
						visited = true;
					}
					else if (secondRegion.isValuePresent(firstValue))
					{
						fullRow.getCell(firstColumnIndex) = firstValue;
						fullRow.getCell(secondColumnIndex) = secondValue;
						visited = true;
					}
					else if (secondRegion.isValuePresent(secondValue))
					{
						fullRow.getCell(firstColumnIndex) = secondValue;
						fullRow.getCell(secondColumnIndex) = firstValue;
						visited = true;
					}
				}
			}
		}

	}

	// same for the 9 columns :
	for (unsigned char i = 0; i < 9; i++)
	{
		NineHolder fullColumn = ioGrid.getColumn(i);
		ValueEliminator valueEliminator;
		fullColumn.flagValues(valueEliminator);
		set<unsigned char> availableValues = valueEliminator.availableValue();
		if (availableValues.size() == 2) // exactly two empty cells
		{
			// get the two missing values
			set<unsigned char>::iterator iter = availableValues.begin();
			int firstValue = *iter;
			iter++;
			int secondValue = *iter;

			// get the two rows corresponding to the two empty cells
			int firstRowIndex = -1;
			int secondRowIndex = -1;
			int firstRegionRowIndex = -1;
			int secondRegionRowIndex = -1;
			for (int j = 0; j < 9; j++)
			{
				if (fullColumn.getCell(j).IsEmpty())
				{
					if (firstRowIndex == -1)
					{
						firstRowIndex = j;
						firstRegionRowIndex = j / 3;
					}						
					else
					{
						secondRowIndex = j;
						secondRegionRowIndex = j / 3;
					}				
				}
			}
			NineHolder firstRow = ioGrid.getRow(firstRowIndex);
			NineHolder secondRow = ioGrid.getRow(secondRowIndex);
			RegionHolder firstRegion = ioGrid.getRegion(firstRegionRowIndex, i / 3);
			RegionHolder secondRegion = ioGrid.getRegion(secondRegionRowIndex, i / 3);
			// check if one of the two missing values already in firstRow or secondRow
			if (firstRow.isValuePresent(firstValue))
			{
				fullColumn.getCell(firstRowIndex) = secondValue;
				fullColumn.getCell(secondRowIndex) = firstValue;
				visited = true;
			}
			else if (firstRow.isValuePresent(secondValue))
			{
				fullColumn.getCell(firstRowIndex) = firstValue;
				fullColumn.getCell(secondRowIndex) = secondValue;
				visited = true;
			}
			else if (secondRow.isValuePresent(firstValue))
			{
				fullColumn.getCell(firstRowIndex) = firstValue;
				fullColumn.getCell(secondRowIndex) = secondValue;
				visited = true;
			}
			else if (secondRow.isValuePresent(secondValue))
			{
				fullColumn.getCell(firstRowIndex) = secondValue;
				fullColumn.getCell(secondRowIndex) = firstValue;
				visited = true;
			}
			else
			{
				//WARNING: do not execute this if the value has already been set!
				//Because we change the value we just assigned...
				// check if one of the two missing values already in firstRegion or secondRegion
				if (firstRegionRowIndex != secondRegionRowIndex)
					// two empty celles are in different regions
				{
					if (firstRegion.isValuePresent(firstValue))
					{
						fullColumn.getCell(firstRowIndex) = secondValue;
						fullColumn.getCell(secondRowIndex) = firstValue;
						visited = true;
					}
					else if (firstRegion.isValuePresent(secondValue))
					{
						fullColumn.getCell(firstRowIndex) = firstValue;
						fullColumn.getCell(secondRowIndex) = secondValue;
						visited = true;
					}
					else if (secondRegion.isValuePresent(firstValue))
					{
						fullColumn.getCell(firstRowIndex) = firstValue;
						fullColumn.getCell(secondRowIndex) = secondValue;
						visited = true;
					}
					else if (secondRegion.isValuePresent(secondValue))
					{
						fullColumn.getCell(firstRowIndex) = secondValue;
						fullColumn.getCell(secondRowIndex) = firstValue;
						visited = true;
					}
				}
			}
		}

	}
	return visited;
}
