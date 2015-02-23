#include "RegionHolder.h"



//TODO : update i,j and move up
RegionHolder::RegionHolder(Region& reg) : _cell_1_1(reg.cells[0][0]),
{
	//TODO : update i,j
	_cell_1_1 = reg.cells[0][0];
	_cell_1_2 = reg.cells[0][0];
	_cell_1_3 = reg.cells[0][0];
	_cell_2_1 = reg.cells[0][0];
	_cell_2_2 = reg.cells[0][0];
	_cell_2_3 = reg.cells[0][0];
	_cell_3_1 = reg.cells[0][0];
	_cell_3_2 = reg.cells[0][0];
	_cell_3_3 = reg.cells[0][0];
}

//TODO : implement all accessors 


RowHolder RegionHolder::TopRow()
{
	return RowHolder(Cell_1_1(), AccessCell(0, 1), AccessCell(0, 2));
}

RowHolder RegionHolder::TopRow() const
{
	return RowHolder(Cell_1_1(), AccessCell(0, 1), AccessCell(0, 2));
}

set<unsigned char> RegionHolder::FlagValues(ValueEliminator& valueEliminator)
{
	valueEliminator.SetFlags(*this);
	return valueEliminator.AvailableValue();
}

bool RegionHolder::IsValuePresent(unsigned char iTarget)
{
	ValueEliminator valueEliminator;
	set<unsigned char> availableValues = FlagValues(valueEliminator);
	
	return availableValues.find(iTarget) != availableValues.end(); 
}

RegionHolder::~RegionHolder()
{
}


