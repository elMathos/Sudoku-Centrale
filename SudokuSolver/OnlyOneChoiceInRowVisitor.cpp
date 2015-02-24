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

	LastCellFinder lcf1(RegionHolder(ioGrid.Get_rNW()).TopRow(), 
		RegionHolder(ioGrid.Get_rN()).TopRow(), RegionHolder(ioGrid.Get_rNE()).TopRow());
	success |= lcf1.fill();

	LastCellFinder lcf2(RegionHolder(ioGrid.Get_rNW()).MiddleRow(),
		RegionHolder(ioGrid.Get_rN()).MiddleRow(), RegionHolder(ioGrid.Get_rNE()).MiddleRow());
	success |= lcf2.fill();

	LastCellFinder lcf3(RegionHolder(ioGrid.Get_rNW()).BottomRow(),
		RegionHolder(ioGrid.Get_rN()).BottomRow(), RegionHolder(ioGrid.Get_rNE()).BottomRow());
	success |= lcf3.fill();

	LastCellFinder lcf4(RegionHolder(ioGrid.Get_rW()).TopRow(),
		RegionHolder(ioGrid.Get_rC()).TopRow(), RegionHolder(ioGrid.Get_rE()).TopRow());
	success |= lcf4.fill();

	LastCellFinder lcf5(RegionHolder(ioGrid.Get_rW()).MiddleRow(),
		RegionHolder(ioGrid.Get_rC()).MiddleRow(), RegionHolder(ioGrid.Get_rE()).MiddleRow());
	success |= lcf5.fill();

	LastCellFinder lcf6(RegionHolder(ioGrid.Get_rW()).BottomRow(),
		RegionHolder(ioGrid.Get_rC()).BottomRow(), RegionHolder(ioGrid.Get_rE()).BottomRow());
	success |= lcf6.fill();

	LastCellFinder lcf7(RegionHolder(ioGrid.Get_rSW()).TopRow(),
		RegionHolder(ioGrid.Get_rS()).TopRow(), RegionHolder(ioGrid.Get_rSE()).TopRow());
	success |= lcf7.fill();

	LastCellFinder lcf8(RegionHolder(ioGrid.Get_rSW()).MiddleRow(),
		RegionHolder(ioGrid.Get_rS()).MiddleRow(), RegionHolder(ioGrid.Get_rSE()).MiddleRow());
	success |= lcf8.fill();

	LastCellFinder lcf9(RegionHolder(ioGrid.Get_rSW()).BottomRow(),
		RegionHolder(ioGrid.Get_rS()).BottomRow(), RegionHolder(ioGrid.Get_rSE()).BottomRow());
	success |= lcf9.fill();

	return success;
}
