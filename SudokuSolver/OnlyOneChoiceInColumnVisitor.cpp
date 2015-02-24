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
	ColumnHolder ch1_1 = RegionHolder(ioGrid.Get_rNW()).LeftColumn();
	ColumnHolder ch1_2 = RegionHolder(ioGrid.Get_rW()).LeftColumn();
	ColumnHolder ch1_3 = RegionHolder(ioGrid.Get_rSW()).LeftColumn();
	LastCellFinder lcf1(ch1_1, ch1_2, ch1_3);
	success |= lcf1.fill();

	ColumnHolder ch2_1 = RegionHolder(ioGrid.Get_rNW()).MiddleColumn();
	ColumnHolder ch2_2 = RegionHolder(ioGrid.Get_rW()).MiddleColumn();
	ColumnHolder ch2_3 = RegionHolder(ioGrid.Get_rSW()).MiddleColumn();
	LastCellFinder lcf2(ch2_1, ch2_2, ch2_3);
	success |= lcf2.fill();

	ColumnHolder ch3_1 = RegionHolder(ioGrid.Get_rNW()).RightColumn();
	ColumnHolder ch3_2 = RegionHolder(ioGrid.Get_rW()).RightColumn();
	ColumnHolder ch3_3 = RegionHolder(ioGrid.Get_rSW()).RightColumn();
	LastCellFinder lcf3(ch3_1, ch3_2, ch3_3);
	success |= lcf3.fill();

	ColumnHolder ch4_1 = RegionHolder(ioGrid.Get_rN()).LeftColumn();
	ColumnHolder ch4_2 = RegionHolder(ioGrid.Get_rC()).LeftColumn();
	ColumnHolder ch4_3 = RegionHolder(ioGrid.Get_rS()).LeftColumn();
	LastCellFinder lcf4(ch4_1, ch4_2, ch4_3);
	success |= lcf4.fill();

	ColumnHolder ch5_1 = RegionHolder(ioGrid.Get_rN()).MiddleColumn();
	ColumnHolder ch5_2 = RegionHolder(ioGrid.Get_rC()).MiddleColumn();
	ColumnHolder ch5_3 = RegionHolder(ioGrid.Get_rS()).MiddleColumn();
	LastCellFinder lcf5(ch5_1, ch5_2, ch5_3);
	success |= lcf5.fill();

	ColumnHolder ch6_1 = RegionHolder(ioGrid.Get_rN()).RightColumn();
	ColumnHolder ch6_2 = RegionHolder(ioGrid.Get_rC()).RightColumn();
	ColumnHolder ch6_3 = RegionHolder(ioGrid.Get_rS()).RightColumn();
	LastCellFinder lcf6(ch6_1, ch6_2, ch6_3);
	success |= lcf6.fill();

	ColumnHolder ch7_1 = RegionHolder(ioGrid.Get_rNE()).LeftColumn();
	ColumnHolder ch7_2 = RegionHolder(ioGrid.Get_rE()).LeftColumn();
	ColumnHolder ch7_3 = RegionHolder(ioGrid.Get_rSE()).LeftColumn();
	LastCellFinder lcf7(ch7_1, ch7_2, ch7_3);
	success |= lcf7.fill();

	ColumnHolder ch8_1 = RegionHolder(ioGrid.Get_rNE()).MiddleColumn();
	ColumnHolder ch8_2 = RegionHolder(ioGrid.Get_rE()).MiddleColumn();
	ColumnHolder ch8_3 = RegionHolder(ioGrid.Get_rSE()).MiddleColumn();
	LastCellFinder lcf8(ch8_1, ch8_2, ch8_3);
	success |= lcf8.fill();

	ColumnHolder ch9_1 = RegionHolder(ioGrid.Get_rNE()).RightColumn();
	ColumnHolder ch9_2 = RegionHolder(ioGrid.Get_rE()).RightColumn();
	ColumnHolder ch9_3 = RegionHolder(ioGrid.Get_rSE()).RightColumn();
	LastCellFinder lcf9(ch9_1, ch9_2, ch9_3);
	success |= lcf9.fill();

	return success;
}
