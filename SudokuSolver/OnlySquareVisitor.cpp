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
		NineHolder fullRow = ioGrid.GetRow(i);
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
			for (int i = 0; i < 9; i++)
			{
				if (fullRow.GetCell(i).IsEmpty())
				{
					if (firstColumnIndex == -1)
						firstColumnIndex = i;
					else
						secondColumnIndex = i;
				}
			}
			NineHolder firstColumn = ioGrid.GetColumn(firstColumnIndex);
			NineHolder secondColumn = ioGrid.GetColumn(secondColumnIndex);

			// check if one of the two missing values already in firstColumn or secondColumn
			if (firstColumn.isValuePresent(firstValue))
			{
				fullRow.GetCell(firstColumnIndex) = secondValue;
				fullRow.GetCell(secondColumnIndex) = firstValue;
				visited = true;
			}
			else if (firstColumn.isValuePresent(secondValue))
			{
				fullRow.GetCell(firstColumnIndex) = firstValue;
				fullRow.GetCell(secondColumnIndex) = secondValue;
				visited = true;
			}
			else if (secondColumn.isValuePresent(firstValue))
			{
				fullRow.GetCell(firstColumnIndex) = firstValue;
				fullRow.GetCell(secondColumnIndex) = secondValue;
				visited = true;
			}
			else if (secondColumn.isValuePresent(secondValue))
			{
				fullRow.GetCell(firstColumnIndex) = secondValue;
				fullRow.GetCell(secondColumnIndex) = firstValue;
				visited = true;
			}
		}

	}

	// same for the 9 columns :
	for (unsigned char i = 0; i < 9; i++)
	{
		NineHolder fullColumn = ioGrid.GetColumn(i);
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
			for (int i = 0; i < 9; i++)
			{
				if (fullColumn.GetCell(i).IsEmpty())
				{
					if (firstRowIndex == -1)
						firstRowIndex = i;
					else
						secondRowIndex = i;
				}
			}
			NineHolder firstRow = ioGrid.GetRow(firstRowIndex);
			NineHolder secondColumn = ioGrid.GetColumn(secondRowIndex);

			// check if one of the two missing values already in firstRow or secondRow
			if (firstRow.isValuePresent(firstValue))
			{
				fullColumn.GetCell(firstRowIndex) = secondValue;
				fullColumn.GetCell(secondRowIndex) = firstValue;
				visited = true;
			}
			else if (firstRow.isValuePresent(secondValue))
			{
				fullColumn.GetCell(firstRowIndex) = firstValue;
				fullColumn.GetCell(secondRowIndex) = secondValue;
				visited = true;
			}
			else if (secondColumn.isValuePresent(firstValue))
			{
				fullColumn.GetCell(firstRowIndex) = firstValue;
				fullColumn.GetCell(secondRowIndex) = secondValue;
				visited = true;
			}
			else if (secondColumn.isValuePresent(secondValue))
			{
				fullColumn.GetCell(firstRowIndex) = secondValue;
				fullColumn.GetCell(secondRowIndex) = firstValue;
				visited = true;
			}
		}

	}


	return visited;
}
