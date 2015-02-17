#include "Grid.h"
#include <vector>
#include <string>
using namespace std;

void main()
{
	vector<vector<string>> values = vector<vector<string>>(3);
	for (int i = 0; i < 3; i++)
	{
		values[i] = vector<string>(3);

		for (int j = 0; j < 3; j++)
		{
			values[i][j] = "123456789";
		}
	}

	Grid grid(values);

	Cell c = 3;
}