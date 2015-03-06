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
		NineHolder FullTopLine = ioGrid.getRow(3*i);
		NineHolder FullMiddleLine = ioGrid.getRow(3*i + 1);
		NineHolder FullBottomLine = ioGrid.getRow(3*i + 2);

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
			else{ //delete Column in which the digit is present from the set columnAbsence
				if (FullTopLine.getCell(0).getValue() == digit || FullTopLine.getCell(1).getValue() == digit
					|| FullTopLine.getCell(2).getValue() == digit)
				{
					columnAbsence.erase(0);
				}
				if (FullTopLine.getCell(3).getValue() == digit || FullTopLine.getCell(4).getValue() == digit
					|| FullTopLine.getCell(5).getValue() == digit)
				{
					columnAbsence.erase(1);
				}
				if (FullTopLine.getCell(6).getValue() == digit || FullTopLine.getCell(7).getValue() == digit
					|| FullTopLine.getCell(8).getValue() == digit)
				{
					columnAbsence.erase(2);
				}
				
			}
			if (!FullMiddleLine.isValuePresent(digit))
			{ 
				rowDigitAbsent = 3 * i + 1; 
				absences++;
			}
			else{ //add Column in which the digit is present to the set columnAbsence
				if (FullMiddleLine.getCell(0).getValue() == digit || FullMiddleLine.getCell(1).getValue() == digit
					|| FullMiddleLine.getCell(2).getValue() == digit)
				{
					columnAbsence.erase(0);
				}
				if (FullMiddleLine.getCell(3).getValue() == digit || FullMiddleLine.getCell(4).getValue() == digit
					|| FullMiddleLine.getCell(5).getValue() == digit)
				{
					columnAbsence.erase(1);
				}
				if (FullMiddleLine.getCell(6).getValue() == digit || FullMiddleLine.getCell(7).getValue() == digit
					|| FullMiddleLine.getCell(8).getValue() == digit)
				{
					columnAbsence.erase(2);
				}
			}
			if (!FullBottomLine.isValuePresent(digit))
			{ 
				rowDigitAbsent = 3 * i + 2; 
				absences++; 
			}
			else{ //erase Column in which the digit is present from the set columnAbsence
				if (FullBottomLine.getCell(0).getValue() == digit || FullBottomLine.getCell(1).getValue() == digit
					|| FullBottomLine.getCell(2).getValue() == digit)
				{
					columnAbsence.erase(0);
				}
				if (FullBottomLine.getCell(3).getValue() == digit || FullBottomLine.getCell(4).getValue() == digit
					|| FullBottomLine.getCell(5).getValue() == digit)
				{
					columnAbsence.erase(1);
				}
				if (FullBottomLine.getCell(6).getValue() == digit || FullBottomLine.getCell(7).getValue() == digit
					|| FullBottomLine.getCell(8).getValue() == digit)
				{
					columnAbsence.erase(2);
				}
			}

			if (absences == 1 && columnAbsence.size() == 1) //we've been twice in the else, columnAbsence has one element exactly
			{
				//the digit is absent of exactly one row out of three
				//it is absent of row rowDigitAbsent
				//there is exactly 1 element in the set columnAbsence: 0, 1 or 2
				//Get 3 nineholder (column) on the 3 corresponding columns (3colRegIndex, .., 3colRegIndex+2)
				set<unsigned char>::iterator iter = columnAbsence.begin();
				int colRegIndex = *iter;
				//We could have a loop here but I think it is more readable this way.
				NineHolder nh1 = ioGrid.getColumn(3 * colRegIndex);
				NineHolder nh2 = ioGrid.getColumn(3 * colRegIndex + 1);
				NineHolder nh3 = ioGrid.getColumn(3 * colRegIndex + 2);
				
				set<unsigned char> possiblePlaces;
				possiblePlaces.insert(0);
				possiblePlaces.insert(1);
				possiblePlaces.insert(2);
				RegionHolder regHolder = ioGrid.getRegion(rowDigitAbsent / 3, colRegIndex);

				if (!regHolder.getCell(rowDigitAbsent % 3, 0).IsEmpty()
					|| nh1.isValuePresent(digit) )
				{
					possiblePlaces.erase(0);
				}
				if (!regHolder.getCell(rowDigitAbsent % 3, 1).IsEmpty()
					|| nh2.isValuePresent(digit))
				{
					possiblePlaces.erase(1);
				}
				if (!regHolder.getCell(rowDigitAbsent % 3, 2).IsEmpty()
					|| nh3.isValuePresent(digit))
				{
					possiblePlaces.erase(2);
				}

				//If it is, set value of corresponding cell to digit	
				if (possiblePlaces.size() == 1)
				{
					set<unsigned char>::iterator iter3 = possiblePlaces.begin();
					int place = *iter3;
					regHolder.getCell(rowDigitAbsent % 3, place) = digit;
					visited = true;
				}
			}
		}
	}

	return visited;
}
