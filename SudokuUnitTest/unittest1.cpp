#include "stdafx.h"
#include "CppUnitTest.h"
#include "Cell.h"
#include "Region.h"
#include "Grid.h"
#include "RegionHolder.h"
#include "LastCellFinder.h"
#include "OnlyOneChoiceInRowVisitor.h"
#include "OnlyOneChoiceInColumnVisitor.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SudokuUnitTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		//TODO rename tests explicitly
		TEST_METHOD(CellValue1)
		{
			Cell cell = Cell(2);
			Assert::AreEqual(cell.GetValue(), 2);
		}
		TEST_METHOD(EmptyCell)
		{
			Cell cell = Cell();
			Assert::AreEqual(cell.GetValue(), -1);
		}

		TEST_METHOD(RegionStringConstructor)
		{
			Region myRegion1 = Region("1-3456789");

			Assert::AreEqual(1, myRegion1.Get_cNW().GetValue());
			Assert::AreEqual(-1, myRegion1.Get_cN().GetValue());
			Assert::AreEqual(3, myRegion1.Get_cNE().GetValue());
			Assert::AreEqual(4, myRegion1.Get_cW().GetValue());
			Assert::AreEqual(5, myRegion1.Get_cC().GetValue());
			Assert::AreEqual(6, myRegion1.Get_cE().GetValue());
			Assert::AreEqual(7, myRegion1.Get_cSW().GetValue());
			Assert::AreEqual(8, myRegion1.Get_cS().GetValue());
			Assert::AreEqual(9, myRegion1.Get_cSE().GetValue());
		}

		TEST_METHOD(LastCellFinderWithHolderAccessors)
		{
			vector<string> stringInput = vector<string>(9);
			stringInput[0] = "1234-6789";
			for (int i = 1; i < 9; i++)
			{
				stringInput[i] = "123456789";
			}

			Grid grid1 = Grid(stringInput);

			RegionHolder regHold = RegionHolder(grid1.Get_rNW());

			RowHolder topRow1 = regHold.TopRow();
			RowHolder middleRow1 = regHold.MiddleRow();
			RowHolder bottomRow1 = regHold.BottomRow();

			LastCellFinder last = LastCellFinder(topRow1, middleRow1, bottomRow1);
			Assert::AreEqual(-1 , grid1.Get_rNW().Get_cC().GetValue());
			last.fill();
			Assert::AreEqual(5, grid1.Get_rNW().Get_cC().GetValue());
		}

		TEST_METHOD(LastCellFinderWithHolderCells)
		{


			vector<string> stringInput = vector<string>(9);
			stringInput[0] = "1234-6789";
			for (int i = 1; i < 9; i++)
			{
				stringInput[i] = "123456789";
			}

			Grid grid1 = Grid(stringInput);
			//Here's the different part
			TripleHolder topRow1 = TripleHolder(grid1.Get_rNW().Get_cNW(), grid1.Get_rNW().Get_cN(), grid1.Get_rNW().Get_cNE());
			TripleHolder middleRow1 = TripleHolder(grid1.Get_rNW().Get_cW(), grid1.Get_rNW().Get_cC(), grid1.Get_rNW().Get_cE());
			TripleHolder bottomRow1 = TripleHolder(grid1.Get_rNW().Get_cSW(), grid1.Get_rNW().Get_cS(), grid1.Get_rNW().Get_cSE());

			LastCellFinder lastCF = LastCellFinder(topRow1, middleRow1, bottomRow1);
			Assert::AreEqual(-1, grid1.Get_rNW().Get_cC().GetValue());
			lastCF.fill();
			Assert::AreEqual(5, grid1.Get_rNW().Get_cC().GetValue());
		}

		TEST_METHOD(OnlyOneChoiceRow1)
		{
			vector<string> stringInput = vector<string>(9);
		    /*grid:
			-23456789
			123456789
			etc
			First row should be filled
			*/

			stringInput[0] = "-23123123";
			stringInput[1] = "456456456";
			stringInput[2] = "789789789";
			for (int i = 3; i < 9; i++)
			{
				stringInput[i] = "123456789";
			}

			OnlyOneChoiceInRowVisitor visitor = OnlyOneChoiceInRowVisitor();
			Grid grid = Grid(stringInput);
			Assert::AreEqual(-1, grid.Get_rNW().Get_cNW().GetValue());
			bool filled = grid.Accept(visitor);
			//First cell of grid should have been filled with a 1
			Assert::IsTrue(filled);
			Assert::AreEqual(1, grid.Get_rNW().Get_cNW().GetValue());
		}

		TEST_METHOD(OnlyOneChoiceRow2)
		{
			vector<string> stringInput = vector<string>(9);
			/*grid:
			-23456789
			-23456789
			etc
			First column should be filled with ones
			*/

			for (int i = 0; i < 3; i++)
			{
				stringInput[0+3*i] = "-23-23-23";
				stringInput[1+3*i] = "456456456";
				stringInput[2+3*i] = "789789789";
			}

			OnlyOneChoiceInRowVisitor visitor = OnlyOneChoiceInRowVisitor();
			Grid grid = Grid(stringInput);
			Assert::AreEqual(-1, grid.Get_rNW().Get_cNW().GetValue());
			Assert::AreEqual(-1, grid.Get_rNW().Get_cW().GetValue());
			Assert::AreEqual(-1, grid.Get_rNW().Get_cSW().GetValue());
			Assert::AreEqual(-1, grid.Get_rW().Get_cNW().GetValue());
			Assert::AreEqual(-1, grid.Get_rW().Get_cW().GetValue());
			Assert::AreEqual(-1, grid.Get_rW().Get_cSW().GetValue());
			Assert::AreEqual(-1, grid.Get_rSW().Get_cNW().GetValue());
			Assert::AreEqual(-1, grid.Get_rSW().Get_cW().GetValue());
			Assert::AreEqual(-1, grid.Get_rSW().Get_cSW().GetValue());
			bool filled = grid.Accept(visitor);
			Assert::IsTrue(filled);

			//First column of grid should have been filled with 1s
			Assert::AreEqual(1, grid.Get_rNW().Get_cNW().GetValue());
			Assert::AreEqual(1, grid.Get_rNW().Get_cW().GetValue());
			Assert::AreEqual(1, grid.Get_rNW().Get_cSW().GetValue());
			Assert::AreEqual(1, grid.Get_rW().Get_cNW().GetValue());
			Assert::AreEqual(1, grid.Get_rW().Get_cW().GetValue());
			Assert::AreEqual(1, grid.Get_rW().Get_cSW().GetValue());
			Assert::AreEqual(1, grid.Get_rSW().Get_cNW().GetValue());
			Assert::AreEqual(1, grid.Get_rSW().Get_cW().GetValue());
			Assert::AreEqual(1, grid.Get_rSW().Get_cSW().GetValue());
		}

		TEST_METHOD(OnlyOneChoiceColumn1)
		{
			vector<string> stringInput = vector<string>(9);
			/*grid:
			-11111111
			222222222
			333333333
			etc
			999999999
			First row should be filled
			*/

			stringInput[0] = "-11222333";
			stringInput[1] = "111222333";
			stringInput[2] = "111222333";

			for (int i = 3; i < 6; i++)
			{
				stringInput[i] = "444555666";
				stringInput[i + 3] = "777888999";
			}

			Assert::AreEqual(1, 1);
			//Here we vist the grid column by column
			OnlyOneChoiceInColumnVisitor visitor = OnlyOneChoiceInColumnVisitor();
			Grid grid = Grid(stringInput);


			Assert::AreEqual(-1, grid.Get_rNW().Get_cNW().GetValue());
			bool filled = grid.Accept(visitor);
			//First cell of grid should have been filled with a 1
			Assert::IsTrue(filled);
			Assert::AreEqual(1, grid.Get_rNW().Get_cNW().GetValue());
		}

		TEST_METHOD(OnlyOneChoiceColumn2)
		{
			vector<string> stringInput = vector<string>(9);
			/*grid:
			---------
			888888888
			777777777
			etc
			...
			111111111
			First row should be filled
			*/

			for (int i = 3; i < 9; i++)
			{
				stringInput[3*i] = "---888777";
				stringInput[3 * i+1] = "666555444";
				stringInput[3 * i + 1] = "333222111";
			}

			OnlyOneChoiceInColumnVisitor visitor = OnlyOneChoiceInColumnVisitor();
			Grid grid = Grid(stringInput);
			Assert::AreEqual(-1, grid.Get_rNW().Get_cNW().GetValue());
			Assert::AreEqual(-1, grid.Get_rNW().Get_cN().GetValue());
			Assert::AreEqual(-1, grid.Get_rNW().Get_cNE().GetValue());		
			Assert::AreEqual(-1, grid.Get_rN().Get_cNW().GetValue());
			Assert::AreEqual(-1, grid.Get_rN().Get_cN().GetValue());
			Assert::AreEqual(-1, grid.Get_rN().Get_cNE().GetValue());			
			Assert::AreEqual(-1, grid.Get_rNE().Get_cNW().GetValue());
			Assert::AreEqual(-1, grid.Get_rNE().Get_cN().GetValue());
			Assert::AreEqual(-1, grid.Get_rNE().Get_cNE().GetValue());


			bool filled = grid.Accept(visitor);
			//First row of grid should have been filled with 9
			Assert::IsTrue(filled);
			Assert::AreEqual(9, grid.Get_rNW().Get_cNW().GetValue());
			Assert::AreEqual(9, grid.Get_rNW().Get_cN().GetValue());
			Assert::AreEqual(9, grid.Get_rNW().Get_cNE().GetValue());
			Assert::AreEqual(9, grid.Get_rN().Get_cNW().GetValue());
			Assert::AreEqual(9, grid.Get_rN().Get_cN().GetValue());
			Assert::AreEqual(9, grid.Get_rN().Get_cNE().GetValue());
			Assert::AreEqual(9, grid.Get_rNE().Get_cNW().GetValue());
			Assert::AreEqual(9, grid.Get_rNE().Get_cN().GetValue());
			Assert::AreEqual(9, grid.Get_rNE().Get_cNE().GetValue());
		}

	};
}