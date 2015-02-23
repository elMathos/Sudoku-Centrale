#include "OnlyOneChoiceInRowVisitor.h"
#include "RegionHolder.h"
#include "LastCellFinder.h"

OnlyOneChoiceInRowVisitor::OnlyOneChoiceInRowVisitor()
{
}


OnlyOneChoiceInRowVisitor::~OnlyOneChoiceInRowVisitor()
{
}

bool OnlyOneChoiceInRowVisitor::Visit(Grid& ioGrid) const
{
	bool success = false;

	//TODO : do it 9 times
	LastCellFinder l_0(RegionHolder(ioGrid.Get_Region_0_0()).TopRow(), 
		RegionHolder(ioGrid.Get_Region_0_1()).TopRow(), RegionHolder(ioGrid.Get_Region_0_2()).TopRow());
	success |= l_0.Fill();

	return success;
}
