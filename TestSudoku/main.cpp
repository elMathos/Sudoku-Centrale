#include "Region.h"
#include "Grid.h"
#include "stdio.h"
#include <stdexcept>
#include <string.h>

using namespace std;

int main(int argc, char *argv[])
{
	Cell* myCell1 = new Cell();
	printf("Expected -1, got %i\n", myCell1->GetValue());

	Cell* myCell2 = new Cell(9);
	printf("Expected 9, got %i\n", myCell2->GetValue());

	try{
		Cell* myCell3 = new Cell(-1);
	}
	catch (const invalid_argument& e){
		printf(e.what());
	}

	try{
		Cell* myCell4 = new Cell(10);
	}
	catch (const invalid_argument& e){
		printf(e.what());
	}

	try{
		Region* myRegion1 = new Region("1-3456789");
		printf("%i\n", myRegion1->cells[0][1].GetValue()); //should print -1
		printf("%i\n", myRegion1->cells[0][0].GetValue()); //should print 1
	}
	catch (const invalid_argument& e){
		printf(e.what());
	}

	try{
		Region* myRegion1 = new Region("1------a-");
	}
	catch (const invalid_argument& e){
		printf(e.what());
	}

	//vector<vector<string>> values = vector<vector<string>>(3);
	//for (int i = 0; i < 3; i++)
	//{
	//	values[i] = vector<string>(3);

	//	for (int j = 0; j < 3; j++)
	//	{
	//		values[i][j] = "123456789";
	//	}
	//}

	//Grid grid(values);

	//Cell c = 3;


	return 0;
}
