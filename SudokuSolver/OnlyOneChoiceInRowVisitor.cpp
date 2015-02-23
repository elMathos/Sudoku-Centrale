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
	LastCellFinder l_0(RegionHolder(ioGrid.Get_rNW()).TopRow(), 
		RegionHolder(ioGrid.Get_rN()).TopRow(), RegionHolder(ioGrid.Get_rNE()).TopRow());
	success |= l_0.fill();

	return success;
}
