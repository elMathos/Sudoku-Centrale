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
		NineHolder FullLeftColumn = ioGrid.getColumn(3 * i);
		NineHolder FullMiddleColumn = ioGrid.getColumn(3 * i + 1);
		NineHolder FullRightColumn = ioGrid.getColumn(3 * i + 2);

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
				if (FullLeftColumn.getCell(0).getValue() == digit || FullLeftColumn.getCell(1).getValue() == digit
					|| FullLeftColumn.getCell(2).getValue() == digit)
				{
					rowAbsence.erase(0);
				}
				if (FullLeftColumn.getCell(3).getValue() == digit || FullLeftColumn.getCell(4).getValue() == digit
					|| FullLeftColumn.getCell(5).getValue() == digit)
				{
					rowAbsence.erase(1);
				}
				if (FullLeftColumn.getCell(6).getValue() == digit || FullLeftColumn.getCell(7).getValue() == digit
					|| FullLeftColumn.getCell(8).getValue() == digit)
				{
					rowAbsence.erase(2);
				}

			}
			if (!FullMiddleColumn.isValuePresent(digit))
			{
				columnDigitAbsent = 3 * i + 1; absences++;
			}
			else{ //erase Row in which the digit is present from the set rowAbsence
				if (FullMiddleColumn.getCell(0).getValue() == digit || FullMiddleColumn.getCell(1).getValue() == digit
					|| FullMiddleColumn.getCell(2).getValue() == digit)
				{
					rowAbsence.erase(0);
				}
				if (FullMiddleColumn.getCell(3).getValue() == digit || FullMiddleColumn.getCell(4).getValue() == digit
					|| FullMiddleColumn.getCell(5).getValue() == digit)
				{
					rowAbsence.erase(1);
				}
				if (FullMiddleColumn.getCell(6).getValue() == digit || FullMiddleColumn.getCell(7).getValue() == digit
					|| FullMiddleColumn.getCell(8).getValue() == digit)
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
				if (FullRightColumn.getCell(0).getValue() == digit || FullRightColumn.getCell(1).getValue() == digit
					|| FullRightColumn.getCell(2).getValue() == digit)
				{
					rowAbsence.erase(0);
				}
				if (FullRightColumn.getCell(3).getValue() == digit || FullRightColumn.getCell(4).getValue() == digit
					|| FullRightColumn.getCell(5).getValue() == digit)
				{
					rowAbsence.erase(1);
				}
				if (FullRightColumn.getCell(6).getValue() == digit || FullRightColumn.getCell(7).getValue() == digit
					|| FullRightColumn.getCell(8).getValue() == digit)
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
				NineHolder nh1 = ioGrid.getRow(3 * rowRegIndex);
				NineHolder nh2 = ioGrid.getRow(3 * rowRegIndex + 1);
				NineHolder nh3 = ioGrid.getRow(3 * rowRegIndex + 2);

				set<unsigned char> possiblePlaces;
				possiblePlaces.insert(0);
				possiblePlaces.insert(1);
				possiblePlaces.insert(2);
				RegionHolder regHolder = ioGrid.getRegion(rowRegIndex, columnDigitAbsent / 3);

				if (!regHolder.getCell(0, columnDigitAbsent % 3).IsEmpty()
					|| nh1.isValuePresent(digit))
				{
					possiblePlaces.erase(0);
				}
				if (!regHolder.getCell(1, columnDigitAbsent % 3).IsEmpty()
					|| nh2.isValuePresent(digit))
				{
					possiblePlaces.erase(1);
				}
				if (!regHolder.getCell(2, columnDigitAbsent % 3).IsEmpty()
					|| nh3.isValuePresent(digit))
				{
					possiblePlaces.erase(2);
				}

				//If it is, set value of corresponding cell to digit	
				if (possiblePlaces.size() == 1)
				{
					set<unsigned char>::iterator iter3 = possiblePlaces.begin();
					int place = *iter3;
					regHolder.getCell(place, columnDigitAbsent % 3) = digit;
					visited = true;
				}
			}
		}
	}
	return visited;
}

