#include "TwoOutOfThreeColumnVisitor.h"
#include "NineHolder.h"
#include "ValueEliminator.h"
#include <set>

using namespace std;

TwoOutOfThreeColumnVisitor::TwoOutOfThreeColumnVisitor()
{
}


TwoOutOfThreeColumnVisitor::~TwoOutOfThreeColumnVisitor()
{
}

//This method is quite similar to TwoOutOfThreeRowVisitor::Visit(). Make sure to change both when editting.
bool TwoOutOfThreeColumnVisitor::Visit(Grid& ioGrid) const
{
	bool visited = false;
	for (unsigned char i = 0; i < 3; i++)
	{
		NineHolder FullLeftColumn = ioGrid.GetColumn(3 * i);
		NineHolder FullMiddleColumn = ioGrid.GetColumn(3 * i + 1);
		NineHolder FullRightColumn = ioGrid.GetColumn(3 * i + 2);

		for (unsigned char digit = 1; digit < 10; digit++)
		{
			unsigned char columnDigitAbsent = 0;
			unsigned char absences = 0;
			set<unsigned char> rowAbsence;
			rowAbsence.insert(0);
			rowAbsence.insert(1);
			rowAbsence.insert(2);
			if (!FullLeftColumn.isValuePresent(digit))
			{
				columnDigitAbsent = 3 * i; 
				absences++;
			}
			else{ //erase Row in which the digit is present from the set rowAbsence
				if (FullLeftColumn.GetCell(0).GetValue() == digit || FullLeftColumn.GetCell(1).GetValue() == digit
					|| FullLeftColumn.GetCell(2).GetValue() == digit)
				{
					rowAbsence.erase(0);
				}
				if (FullLeftColumn.GetCell(3).GetValue() == digit || FullLeftColumn.GetCell(4).GetValue() == digit
					|| FullLeftColumn.GetCell(5).GetValue() == digit)
				{
					rowAbsence.erase(1);
				}
				if (FullLeftColumn.GetCell(6).GetValue() == digit || FullLeftColumn.GetCell(7).GetValue() == digit
					|| FullLeftColumn.GetCell(8).GetValue() == digit)
				{
					rowAbsence.erase(2);
				}

			}
			if (!FullMiddleColumn.isValuePresent(digit))
			{
				columnDigitAbsent = 3 * i + 1; absences++;
			}
			else{ //erase Row in which the digit is present from the set rowAbsence
				if (FullMiddleColumn.GetCell(0).GetValue() == digit || FullMiddleColumn.GetCell(1).GetValue() == digit
					|| FullMiddleColumn.GetCell(2).GetValue() == digit)
				{
					rowAbsence.erase(0);
				}
				if (FullMiddleColumn.GetCell(3).GetValue() == digit || FullMiddleColumn.GetCell(4).GetValue() == digit
					|| FullMiddleColumn.GetCell(5).GetValue() == digit)
				{
					rowAbsence.erase(1);
				}
				if (FullMiddleColumn.GetCell(6).GetValue() == digit || FullMiddleColumn.GetCell(7).GetValue() == digit
					|| FullMiddleColumn.GetCell(8).GetValue() == digit)
				{
					rowAbsence.erase(2);
				}
			}
			if (!FullRightColumn.isValuePresent(digit))
			{ 
				columnDigitAbsent = 3 * i + 2; 
				absences++; 
			}
			else{ //erase Column in which the digit is present from the set rowAbsence
				if (FullRightColumn.GetCell(0).GetValue() == digit || FullRightColumn.GetCell(1).GetValue() == digit
					|| FullRightColumn.GetCell(2).GetValue() == digit)
				{
					rowAbsence.erase(0);
				}
				if (FullRightColumn.GetCell(3).GetValue() == digit || FullRightColumn.GetCell(4).GetValue() == digit
					|| FullRightColumn.GetCell(5).GetValue() == digit)
				{
					rowAbsence.erase(1);
				}
				if (FullRightColumn.GetCell(6).GetValue() == digit || FullRightColumn.GetCell(7).GetValue() == digit
					|| FullRightColumn.GetCell(8).GetValue() == digit)
				{
					rowAbsence.erase(2);
				}
			}

			if (absences == 1 && rowAbsence.size() == 1) //we've been twice in the else, rowAbsence has one element exactly
			{
				//the digit is absent of exactly column row out of three
				//it is absent of column columnDigitAbsent
				//there is exactly 1 element in the set rowAbsence: 0, 1 or 2
				//Get 3 nineholder (row) on the 3 corresponding row (3rowRegIndex, .., 3rowRegIndex+2)
				set<unsigned char>::iterator iter = rowAbsence.begin();
				int rowRegIndex = *iter;
				//We could have a loop here but I think it is more readable this way.
				NineHolder nh1 = ioGrid.GetRow(3 * rowRegIndex);
				NineHolder nh2 = ioGrid.GetRow(3 * rowRegIndex + 1);
				NineHolder nh3 = ioGrid.GetRow(3 * rowRegIndex + 2);

				set<unsigned char> possiblePlaces;
				possiblePlaces.insert(0);
				possiblePlaces.insert(1);
				possiblePlaces.insert(2);
				RegionHolder regHolder = ioGrid.GetRegion(rowRegIndex, columnDigitAbsent / 3);

				if (!regHolder.GetCell(0, columnDigitAbsent % 3).IsEmpty()
					|| nh1.isValuePresent(digit))
				{
					possiblePlaces.erase(0);
				}
				if (!regHolder.GetCell(1, columnDigitAbsent % 3).IsEmpty()
					|| nh2.isValuePresent(digit))
				{
					possiblePlaces.erase(1);
				}
				if (!regHolder.GetCell(2, columnDigitAbsent % 3).IsEmpty()
					|| nh3.isValuePresent(digit))
				{
					possiblePlaces.erase(2);
				}

				//If it is, set value of corresponding cell to digit	
				if (possiblePlaces.size() == 1)
				{
					set<unsigned char>::iterator iter3 = possiblePlaces.begin();
					int place = *iter3;
					regHolder.GetCell(place, columnDigitAbsent % 3) = digit;
					visited = true;
				}
			}
		}
	}

	return visited;
}

