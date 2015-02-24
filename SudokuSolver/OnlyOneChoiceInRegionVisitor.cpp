#include "OnlyOneChoiceInRegionVisitor.h"
#include "RegionHolder.h"
#include "LastCellFinder.h"


OnlyOneChoiceInRegionVisitor::OnlyOneChoiceInRegionVisitor()
{
}


OnlyOneChoiceInRegionVisitor::~OnlyOneChoiceInRegionVisitor()
{
}

bool OnlyOneChoiceInRegionVisitor::Visit(Grid& ioGrid) const
{
	bool success = false;

	RowHolder rh1_1 = RegionHolder(ioGrid.Get_rNW()).TopRow();
	RowHolder rh1_2 = RegionHolder(ioGrid.Get_rNW()).MiddleRow();
	RowHolder rh1_3 = RegionHolder(ioGrid.Get_rNW()).BottomRow();
	LastCellFinder lcf1(rh1_1, rh1_2, rh1_3);
	success |= lcf1.fill();
	
	RowHolder rh2_1 = RegionHolder(ioGrid.Get_rN()).TopRow();
	RowHolder rh2_2 = RegionHolder(ioGrid.Get_rN()).MiddleRow();
	RowHolder rh2_3 = RegionHolder(ioGrid.Get_rN()).BottomRow();
	LastCellFinder lcf2(rh2_1, rh2_2, rh2_3);
	success |= lcf2.fill();

	RowHolder rh3_1 = RegionHolder(ioGrid.Get_rNE()).TopRow();
	RowHolder rh3_2 = RegionHolder(ioGrid.Get_rNE()).MiddleRow();
	RowHolder rh3_3 = RegionHolder(ioGrid.Get_rNE()).BottomRow();
	LastCellFinder lcf3(rh3_1, rh3_2, rh3_3);
	success |= lcf3.fill();

	RowHolder rh4_1 = RegionHolder(ioGrid.Get_rW()).TopRow();
	RowHolder rh4_2 = RegionHolder(ioGrid.Get_rW()).MiddleRow();
	RowHolder rh4_3 = RegionHolder(ioGrid.Get_rW()).BottomRow();
	LastCellFinder lcf4(rh4_1, rh4_2, rh4_3);
	success |= lcf4.fill();

	RowHolder rh5_1 = RegionHolder(ioGrid.Get_rC()).TopRow();
	RowHolder rh5_2 = RegionHolder(ioGrid.Get_rC()).MiddleRow();
	RowHolder rh5_3 = RegionHolder(ioGrid.Get_rC()).BottomRow();
	LastCellFinder lcf5(rh5_1, rh5_2, rh5_3);
	success |= lcf5.fill();

	RowHolder rh6_1 = RegionHolder(ioGrid.Get_rE()).TopRow();
	RowHolder rh6_2 = RegionHolder(ioGrid.Get_rE()).MiddleRow();
	RowHolder rh6_3 = RegionHolder(ioGrid.Get_rE()).BottomRow();
	LastCellFinder lcf6(rh6_1, rh6_2, rh6_3);
	success |= lcf6.fill();

	RowHolder rh7_1 = RegionHolder(ioGrid.Get_rSW()).TopRow();
	RowHolder rh7_2 = RegionHolder(ioGrid.Get_rSW()).MiddleRow();
	RowHolder rh7_3 = RegionHolder(ioGrid.Get_rSW()).BottomRow();
	LastCellFinder lcf7(rh7_1, rh7_2, rh7_3);
	success |= lcf7.fill();

	RowHolder rh8_1 = RegionHolder(ioGrid.Get_rS()).TopRow();
	RowHolder rh8_2 = RegionHolder(ioGrid.Get_rS()).MiddleRow();
	RowHolder rh8_3 = RegionHolder(ioGrid.Get_rS()).BottomRow();
	LastCellFinder lcf8(rh8_1, rh8_2, rh8_3);
	success |= lcf8.fill();

	RowHolder rh9_1 = RegionHolder(ioGrid.Get_rSE()).TopRow();
	RowHolder rh9_2 = RegionHolder(ioGrid.Get_rSE()).MiddleRow();
	RowHolder rh9_3 = RegionHolder(ioGrid.Get_rSE()).BottomRow();
	LastCellFinder lcf9(rh9_1, rh9_2, rh9_3);
	success |= lcf9.fill();

	return success;
}

