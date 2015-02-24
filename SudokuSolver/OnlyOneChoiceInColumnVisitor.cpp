#include "OnlyOneChoiceInColumnVisitor.h"
#include "RegionHolder.h"
#include "LastCellFinder.h"

OnlyOneChoiceInColumnVisitor::OnlyOneChoiceInColumnVisitor()
{
}


OnlyOneChoiceInColumnVisitor::~OnlyOneChoiceInColumnVisitor()
{
}

bool OnlyOneChoiceInColumnVisitor::Visit(Grid& ioGrid) const
{
	bool success = false;

	LastCellFinder lcf1(RegionHolder(ioGrid.Get_rNW()).LeftColumn(),
		RegionHolder(ioGrid.Get_rW()).LeftColumn(), RegionHolder(ioGrid.Get_rSW()).LeftColumn());
	success |= lcf1.fill();

	LastCellFinder lcf2(RegionHolder(ioGrid.Get_rNW()).MiddleColumn(),
		RegionHolder(ioGrid.Get_rW()).MiddleColumn(), RegionHolder(ioGrid.Get_rSW()).MiddleColumn());
	success |= lcf2.fill();

	LastCellFinder lcf3(RegionHolder(ioGrid.Get_rNW()).RightColumn(),
		RegionHolder(ioGrid.Get_rW()).RightColumn(), RegionHolder(ioGrid.Get_rSW()).RightColumn());
	success |= lcf3.fill();

	LastCellFinder lcf4(RegionHolder(ioGrid.Get_rN()).LeftColumn(),
		RegionHolder(ioGrid.Get_rC()).LeftColumn(), RegionHolder(ioGrid.Get_rS()).LeftColumn());
	success |= lcf4.fill();

	LastCellFinder lcf5(RegionHolder(ioGrid.Get_rN()).MiddleColumn(),
		RegionHolder(ioGrid.Get_rC()).MiddleColumn(), RegionHolder(ioGrid.Get_rS()).MiddleColumn());
	success |= lcf5.fill();

	LastCellFinder lcf6(RegionHolder(ioGrid.Get_rN()).RightColumn(),
		RegionHolder(ioGrid.Get_rC()).RightColumn(), RegionHolder(ioGrid.Get_rS()).RightColumn());
	success |= lcf6.fill();

	LastCellFinder lcf7(RegionHolder(ioGrid.Get_rNE()).LeftColumn(),
		RegionHolder(ioGrid.Get_rE()).LeftColumn(), RegionHolder(ioGrid.Get_rSE()).LeftColumn());
	success |= lcf7.fill();

	LastCellFinder lcf8(RegionHolder(ioGrid.Get_rNE()).MiddleColumn(),
		RegionHolder(ioGrid.Get_rE()).MiddleColumn(), RegionHolder(ioGrid.Get_rSE()).MiddleColumn());
	success |= lcf8.fill();

	LastCellFinder lcf9(RegionHolder(ioGrid.Get_rNE()).RightColumn(),
		RegionHolder(ioGrid.Get_rE()).RightColumn(), RegionHolder(ioGrid.Get_rSE()).RightColumn());
	success |= lcf9.fill();

	return success;
}
