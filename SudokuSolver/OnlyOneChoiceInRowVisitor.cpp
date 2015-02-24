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

	LastCellFinder l_0(RegionHolder(ioGrid.Get_rNW()).TopRow(), 
		RegionHolder(ioGrid.Get_rN()).TopRow(), RegionHolder(ioGrid.Get_rNE()).TopRow());
	success |= l_0.fill();

	LastCellFinder l_0(RegionHolder(ioGrid.Get_rNW()).MiddleRow(),
		RegionHolder(ioGrid.Get_rN()).MiddleRow(), RegionHolder(ioGrid.Get_rNE()).MiddleRow());
	success |= l_0.fill();

	LastCellFinder l_0(RegionHolder(ioGrid.Get_rNW()).BottomRow(),
		RegionHolder(ioGrid.Get_rN()).BottomRow(), RegionHolder(ioGrid.Get_rNE()).BottomRow());
	success |= l_0.fill();

	LastCellFinder l_0(RegionHolder(ioGrid.Get_rW()).TopRow(),
		RegionHolder(ioGrid.Get_rC()).TopRow(), RegionHolder(ioGrid.Get_rE()).TopRow());
	success |= l_0.fill();

	LastCellFinder l_0(RegionHolder(ioGrid.Get_rW()).MiddleRow(),
		RegionHolder(ioGrid.Get_rC()).MiddleRow(), RegionHolder(ioGrid.Get_rE()).MiddleRow());
	success |= l_0.fill();

	LastCellFinder l_0(RegionHolder(ioGrid.Get_rW()).BottomRow(),
		RegionHolder(ioGrid.Get_rC()).BottomRow(), RegionHolder(ioGrid.Get_rE()).BottomRow());
	success |= l_0.fill();

	LastCellFinder l_0(RegionHolder(ioGrid.Get_rSW()).TopRow(),
		RegionHolder(ioGrid.Get_rS()).TopRow(), RegionHolder(ioGrid.Get_rSE()).TopRow());
	success |= l_0.fill();

	LastCellFinder l_0(RegionHolder(ioGrid.Get_rSW()).MiddleRow(),
		RegionHolder(ioGrid.Get_rS()).MiddleRow(), RegionHolder(ioGrid.Get_rSE()).MiddleRow());
	success |= l_0.fill();

	LastCellFinder l_0(RegionHolder(ioGrid.Get_rSW()).BottomRow(),
		RegionHolder(ioGrid.Get_rS()).BottomRow(), RegionHolder(ioGrid.Get_rSE()).BottomRow());
	success |= l_0.fill();

	return success;
}
