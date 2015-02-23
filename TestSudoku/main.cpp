#include "Region.h"
#include "Grid.h"
#include "stdio.h"
#include <stdexcept>
#include <string.h>

using namespace std;

int main(int argc, char *argv[])
{
	Cell myCell1 =  Cell();
	printf("Expected -1, got %i\n", myCell1.GetValue());

	Cell myCell2 =  Cell(9);
	printf("Expected 9, got %i\n", myCell2.GetValue());

	try{
		Cell myCell3 =  Cell(-1);
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
		Region myRegion1 = Region("1-3456789");
		//TODO this does not compile
		//printf("%i\n", myRegion1.Get_cNW().GetValue()); //should print 1
		//printf("%i\n", myRegion1.Get_cNW().GetValue()); //TODO change cNW to cN
		//should print -1
	}
	catch (const invalid_argument& e){
		printf(e.what());
	}

	try{
		Region myRegion1 =  Region("1------a-");
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
