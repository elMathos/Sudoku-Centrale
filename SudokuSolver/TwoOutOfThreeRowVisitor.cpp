#include "TwoOutOfThreeRowVisitor.h"
#include "NineHolder.h"
#include "ValueEliminator.h"
//#include "RegionHolder.h"

TwoOutOfThreeRowVisitor::TwoOutOfThreeRowVisitor()
{
}


TwoOutOfThreeRowVisitor::~TwoOutOfThreeRowVisitor()
{
}

bool TwoOutOfThreeRowVisitor::Visit(Grid& ioGrid) const
{
	//visit first Three Cell
	bool success = false;
	for (unsigned char i = 0; i < 3; i++)
	{
		NineHolder FullTopLine = ioGrid.GetRow(3*i);
		NineHolder FullMiddleLine = ioGrid.GetRow(3*i + 1);
		NineHolder FullBottomLine = ioGrid.GetRow(3*i + 2);

		//TODO this does not compile because ValueELim(NineHolder&) is not implemented)
		ValueEliminator veTop = ValueEliminator();
		ValueEliminator veMid = ValueEliminator();
		ValueEliminator veBot = ValueEliminator();
		//set flags for these three VE

		for (unsigned char digit = 1; digit < 10; digit++)
		{
			unsigned char rowDigitAbsent = 0;
			unsigned char absences = 0;
			//create set of unsigned char AA
			//TODO NineHolder::IsValuePresent() is not implemented
			if (!FullTopLine.isValuePresent(digit)){ rowDigitAbsent = 3 * i; absences++; }
			else{ //add Column in which the digit in present to the set AA
			}
			if (!FullMiddleLine.isValuePresent(digit)){ rowDigitAbsent = 3 * i + 1; absences++; }
			else{ //add Column in which the digit in present
			}
			if (!FullBottomLine.isValuePresent(digit)){ rowDigitAbsent = 3 * i + 2; absences++; }
			else{ //add Column in which the digit in present
			}

			if (absences == 1) 
			{
				//the digit is Absent of exactly one row out of three
				//it is absent of row rowDigitAbsent
				//there are two elements in the set AA (0, 1) or (0,2) or (1,2)
				//find the missing one, i
				//Get 3 nineholder (column) on the 3 corresponding columns (3i, .., 3i+2)
				//See if digit is present in 2 of them (when present, store there indices)
				//If it is, set value of Cell (pb: how to acces it to digit)			
			}
		}
	}

	return success;
}
