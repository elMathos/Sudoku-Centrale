#include "stdafx.h"
#include "CppUnitTest.h"
#include "Cell.h"
#include "Region.h"
#include "Grid.h"
#include "RegionHolder.h"
#include "LastCellFinder.h"
#include "OnlyOneChoiceInRowVisitor.h"

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

			Assert::AreEqual(1, myRegion1.GetCell(0, 0).GetValue());
			Assert::AreEqual(-1, myRegion1.GetCell(0, 1).GetValue());
			Assert::AreEqual(3, myRegion1.GetCell(0, 1).GetValue());
			Assert::AreEqual(4, myRegion1.GetCell(1, 0).GetValue());
			Assert::AreEqual(5, myRegion1.GetCell(1, 1).GetValue());
			Assert::AreEqual(6, myRegion1.GetCell(1, 2).GetValue());
			Assert::AreEqual(7, myRegion1.GetCell(2, 0).GetValue());
			Assert::AreEqual(8, myRegion1.GetCell(2, 1).GetValue());
			Assert::AreEqual(9, myRegion1.GetCell(2, 2).GetValue());
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

			RegionHolder regHold = RegionHolder(grid1.GetRegion(0, 0));

			RowHolder topRow1 = regHold.TopRow();
			RowHolder middleRow1 = regHold.MiddleRow();
			RowHolder bottomRow1 = regHold.BottomRow();

			LastCellFinder last = LastCellFinder(topRow1, middleRow1, bottomRow1);
			Assert::AreEqual(-1 , grid1.GetRegion(0, 0).GetCell(1, 1).GetValue());
			last.fill();
			Assert::AreEqual(5, grid1.GetRegion(0, 0).GetCell(1, 1).GetValue());
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
			TripleHolder topRow1 = TripleHolder(grid1.GetRegion(0, 0).GetCell(0, 0), grid1.GetRegion(0, 0).GetCell(0, 1), grid1.GetRegion(0, 0).GetCell(0, 1));
			TripleHolder middleRow1 = TripleHolder(grid1.GetRegion(0, 0).GetCell(1, 0), grid1.GetRegion(0, 0).GetCell(1, 1), grid1.GetRegion(0, 0).GetCell(1, 2));
			TripleHolder bottomRow1 = TripleHolder(grid1.GetRegion(0, 0).GetCell(2, 0), grid1.GetRegion(0, 0).GetCell(2, 1), grid1.GetRegion(0, 0).GetCell(2, 2));

			LastCellFinder lastCF = LastCellFinder(topRow1, middleRow1, bottomRow1);
			Assert::AreEqual(-1, grid1.GetRegion(0, 0).GetCell(1, 1).GetValue());
			lastCF.fill();
			Assert::AreEqual(5, grid1.GetRegion(0, 0).GetCell(1, 1).GetValue());
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
			Assert::AreEqual(-1, grid.GetRegion(0, 0).GetCell(0, 0).GetValue());
			bool filled = grid.Accept(visitor);
			//First cell of grid should have been filled with a 1
			Assert::IsTrue(filled);
			Assert::AreEqual(1, grid.GetRegion(0, 0).GetCell(0, 0).GetValue());
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
			Assert::AreEqual(-1, grid.GetRegion(0, 0).GetCell(0, 0).GetValue());
			Assert::AreEqual(-1, grid.GetRegion(0, 0).GetCell(1, 0).GetValue());
			Assert::AreEqual(-1, grid.GetRegion(0, 0).GetCell(2, 0).GetValue());
			Assert::AreEqual(-1, grid.GetRegion(1, 0).GetCell(0, 0).GetValue());
			Assert::AreEqual(-1, grid.GetRegion(1, 0).GetCell(1, 0).GetValue());
			Assert::AreEqual(-1, grid.GetRegion(1, 0).GetCell(2, 0).GetValue());
			Assert::AreEqual(-1, grid.GetRegion(2, 0).GetCell(0, 0).GetValue());
			Assert::AreEqual(-1, grid.GetRegion(2, 0).GetCell(1, 0).GetValue());
			Assert::AreEqual(-1, grid.GetRegion(2, 0).GetCell(2, 0).GetValue());
			bool filled = grid.Accept(visitor);
			Assert::IsTrue(filled);

			//First column of grid should have been filled with 1s
			Assert::AreEqual(1, grid.GetRegion(0, 0).GetCell(0, 0).GetValue());
			Assert::AreEqual(1, grid.GetRegion(0, 0).GetCell(1, 0).GetValue());
			Assert::AreEqual(1, grid.GetRegion(0, 0).GetCell(2, 0).GetValue());
			Assert::AreEqual(1, grid.GetRegion(1, 0).GetCell(0, 0).GetValue());
			Assert::AreEqual(1, grid.GetRegion(1, 0).GetCell(1, 0).GetValue());
			Assert::AreEqual(1, grid.GetRegion(1, 0).GetCell(2, 0).GetValue());
			Assert::AreEqual(1, grid.GetRegion(2, 0).GetCell(0, 0).GetValue());
			Assert::AreEqual(1, grid.GetRegion(2, 0).GetCell(1, 0).GetValue());
			Assert::AreEqual(1, grid.GetRegion(2, 0).GetCell(2, 0).GetValue());

		}

	};
}