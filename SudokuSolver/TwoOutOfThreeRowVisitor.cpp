#include "TwoOutOfThreeRowVisitor.h"
#include "NineHolder.h"
#include "ValueEliminator.h"
#include <set>

using namespace std;

TwoOutOfThreeRowVisitor::TwoOutOfThreeRowVisitor()
{
}


TwoOutOfThreeRowVisitor::~TwoOutOfThreeRowVisitor()
{
}


//This method is quite similar to TwoOutOfThreeColumnVisitor::Visit(). Make sure to change both when editting.
bool TwoOutOfThreeRowVisitor::Visit(Grid& ioGrid) const
{
	bool visited = false;
	for (unsigned char i = 0; i < 3; i++)
	{
		NineHolder FullTopLine = ioGrid.GetRow(3*i);
		NineHolder FullMiddleLine = ioGrid.GetRow(3*i + 1);
		NineHolder FullBottomLine = ioGrid.GetRow(3*i + 2);

		for (unsigned char digit = 1; digit < 10; digit++)
		{
			unsigned char rowDigitAbsent = 0;
			unsigned char absences = 0;
			set<unsigned char> columnAbsence;
			columnAbsence.insert(0);
			columnAbsence.insert(1);
			columnAbsence.insert(2);
			if (!FullTopLine.isValuePresent(digit))
			{ 
				rowDigitAbsent = 3 * i; 
				absences++; 
			}
			else{ //delete Column in which the digit in present from the set columnAbsence
				if (FullTopLine.GetCell(0).GetValue() == digit || FullTopLine.GetCell(1).GetValue() == digit
					|| FullTopLine.GetCell(2).GetValue() == digit)
				{
					columnAbsence.erase(0);
				}
				if (FullTopLine.GetCell(3).GetValue() == digit || FullTopLine.GetCell(4).GetValue() == digit
					|| FullTopLine.GetCell(5).GetValue() == digit)
				{
					columnAbsence.erase(1);
				}
				if (FullTopLine.GetCell(6).GetValue() == digit || FullTopLine.GetCell(7).GetValue() == digit
					|| FullTopLine.GetCell(8).GetValue() == digit)
				{
					columnAbsence.erase(2);
				}
				
			}
			if (!FullMiddleLine.isValuePresent(digit))
			{ 
				rowDigitAbsent = 3 * i + 1; 
				absences++;
			}
			else{ //add Column in which the digit in present to the set columnAbsence
				if (FullMiddleLine.GetCell(0).GetValue() == digit || FullMiddleLine.GetCell(1).GetValue() == digit
					|| FullMiddleLine.GetCell(2).GetValue() == digit)
				{
					columnAbsence.erase(0);
				}
				if (FullMiddleLine.GetCell(3).GetValue() == digit || FullMiddleLine.GetCell(4).GetValue() == digit
					|| FullMiddleLine.GetCell(5).GetValue() == digit)
				{
					columnAbsence.erase(1);
				}
				if (FullMiddleLine.GetCell(6).GetValue() == digit || FullMiddleLine.GetCell(7).GetValue() == digit
					|| FullMiddleLine.GetCell(8).GetValue() == digit)
				{
					columnAbsence.erase(2);
				}
			}
			if (!FullBottomLine.isValuePresent(digit))
			{ 
				rowDigitAbsent = 3 * i + 2; 
				absences++; 
			}
			else{ //erase Column in which the digit in present from the set columnAbsence
				if (FullBottomLine.GetCell(0).GetValue() == digit || FullBottomLine.GetCell(1).GetValue() == digit
					|| FullBottomLine.GetCell(2).GetValue() == digit)
				{
					columnAbsence.erase(0);
				}
				if (FullBottomLine.GetCell(3).GetValue() == digit || FullBottomLine.GetCell(4).GetValue() == digit
					|| FullBottomLine.GetCell(5).GetValue() == digit)
				{
					columnAbsence.erase(1);
				}
				if (FullBottomLine.GetCell(6).GetValue() == digit || FullBottomLine.GetCell(7).GetValue() == digit
					|| FullBottomLine.GetCell(8).GetValue() == digit)
				{
					columnAbsence.erase(2);
				}
			}

			if (absences == 1) //we've been twice in the else, rowAbsence has one element exactly
			{
				//the digit is absent of exactly one row out of three
				//it is absent of row rowDigitAbsent
				//there is exactly 1 element in the set columnAbsence: 0, 1 or 2
				//Get 3 nineholder (column) on the 3 corresponding columns (3colRegIndex, .., 3colRegIndex+2)
				set<unsigned char>::iterator iter = columnAbsence.begin();
				int colRegIndex = *iter;
				//We could have a loop here but I think it is more readable this way.
				NineHolder nh1 = ioGrid.GetColumn(3 * colRegIndex);
				NineHolder nh2 = ioGrid.GetColumn(3 * colRegIndex + 1);
				NineHolder nh3 = ioGrid.GetColumn(3 * colRegIndex + 2);
				
				set<unsigned char> possiblePlaces;
				possiblePlaces.insert(0);
				possiblePlaces.insert(1);
				possiblePlaces.insert(2);
				RegionHolder regHolder = ioGrid.GetRegion(rowDigitAbsent / 3, colRegIndex);

				if (!regHolder.GetCell(rowDigitAbsent % 3, 0).IsEmpty()
					|| nh1.isValuePresent(digit) )
				{
					possiblePlaces.erase(0);
				}
				if (!regHolder.GetCell(rowDigitAbsent % 3, 1).IsEmpty()
					|| nh2.isValuePresent(digit))
				{
					possiblePlaces.erase(1);
				}
				if (!regHolder.GetCell(rowDigitAbsent % 3, 2).IsEmpty()
					|| nh3.isValuePresent(digit))
				{
					possiblePlaces.erase(2);
				}

				//If it is, set value of corresponding cell to digit	
				if (possiblePlaces.size() == 1)
				{
					set<unsigned char>::iterator iter3 = possiblePlaces.begin();
					int place = *iter3;
					regHolder.GetCell(rowDigitAbsent % 3, place) = digit;
					visited = true;
				}
			}
		}
	}

	return visited;
}
