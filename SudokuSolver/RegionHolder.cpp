#include "RegionHolder.h"


RegionHolder::RegionHolder()
{
}


RegionHolder::RegionHolder(Region& reg)
{
	_cells = vector<vector<Cell>>(L);

	for (int i = 0; i < L; i++)
	{
		_cells[i] = vector<Cell>(L);
		for (int j = 0; j < L; j++)
		{
			_cells[i][j] = reg.cells[i][j];
		}
	}
}

Cell RegionHolder::AccessCell(int i, int j)
{
	return _cells[i][j];
}

RowHolder RegionHolder::TopRow()
{
	return RowHolder(AccessCell(0, 0), AccessCell(0, 1), AccessCell(0, 2));
}

RegionHolder::~RegionHolder()
{
}


