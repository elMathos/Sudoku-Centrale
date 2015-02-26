#include "stdafx.h"
#include "CppUnitTest.h"
#include "Cell.h"
#include "Region.h"
#include "Grid.h"
#include "RegionHolder.h"
#include "LastCellFinder.h"
#include "OnlyOneChoiceInRowVisitor.h"
#include "OnlyOneChoiceInColumnVisitor.h"
#include "OnlyOneChoiceInRegionVisitor.h"
#include "OnlySquareVisitor.h"

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
			Assert::AreEqual(3, myRegion1.GetCell(0, 2).GetValue());
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
			bool filled = last.fill();
			Assert::IsTrue(filled);
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
			TripleHolder topRow1 = TripleHolder(grid1.GetRegion(0, 0).GetCell(0, 0), grid1.GetRegion(0, 0).GetCell(0, 1), grid1.GetRegion(0, 0).GetCell(0, 2));
			TripleHolder middleRow1 = TripleHolder(grid1.GetRegion(0, 0).GetCell(1, 0), grid1.GetRegion(0, 0).GetCell(1, 1), grid1.GetRegion(0, 0).GetCell(1, 2));
			TripleHolder bottomRow1 = TripleHolder(grid1.GetRegion(0, 0).GetCell(2, 0), grid1.GetRegion(0, 0).GetCell(2, 1), grid1.GetRegion(0, 0).GetCell(2, 2));

			LastCellFinder lastCF = LastCellFinder(topRow1, middleRow1, bottomRow1);
			Assert::AreEqual(-1, grid1.GetRegion(0, 0).GetCell(1, 1).GetValue());
			bool filled = lastCF.fill();
			Assert::IsTrue(filled);
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
			Rows : -23456789
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

		TEST_METHOD(OnlyOneChoiceColumn)
		{
			vector<string> stringInput = vector<string>(9);
			/*grid:
			Columns : -23456789
			First row should be filled with ones
			*/
			stringInput[0] = "---222333";
			stringInput[1] = "---222333";
			stringInput[2] = "---222333";
			stringInput[3] = "444555666";
			stringInput[4] = "444555666";
			stringInput[5] = "444555666";
			stringInput[6] = "777888999";
			stringInput[7] = "777888999";
			stringInput[8] = "777888999";

			OnlyOneChoiceInColumnVisitor visitor;
			Grid grid = Grid(stringInput);
			Assert::AreEqual(-1, grid.GetRegion(0, 0).GetCell(0, 0).GetValue());
			Assert::AreEqual(-1, grid.GetRegion(0, 0).GetCell(0, 1).GetValue());
			Assert::AreEqual(-1, grid.GetRegion(0, 0).GetCell(0, 2).GetValue());
			Assert::AreEqual(-1, grid.GetRegion(0, 1).GetCell(0, 0).GetValue());
			Assert::AreEqual(-1, grid.GetRegion(0, 1).GetCell(0, 1).GetValue());
			Assert::AreEqual(-1, grid.GetRegion(0, 1).GetCell(0, 2).GetValue());
			Assert::AreEqual(-1, grid.GetRegion(0, 2).GetCell(0, 0).GetValue());
			Assert::AreEqual(-1, grid.GetRegion(0, 2).GetCell(0, 1).GetValue());
			Assert::AreEqual(-1, grid.GetRegion(0, 2).GetCell(0, 2).GetValue());
			bool filled = grid.Accept(visitor);
			Assert::IsTrue(filled);

			//First column of grid should have been filled with 1s
			Assert::AreEqual(1, grid.GetRegion(0, 0).GetCell(0, 0).GetValue());
			Assert::AreEqual(1, grid.GetRegion(0, 0).GetCell(0, 1).GetValue());
			Assert::AreEqual(1, grid.GetRegion(0, 0).GetCell(0, 2).GetValue());
			Assert::AreEqual(1, grid.GetRegion(0, 1).GetCell(0, 0).GetValue());
			Assert::AreEqual(1, grid.GetRegion(0, 1).GetCell(0, 1).GetValue());
			Assert::AreEqual(1, grid.GetRegion(0, 1).GetCell(0, 2).GetValue());
			Assert::AreEqual(1, grid.GetRegion(0, 2).GetCell(0, 0).GetValue());
			Assert::AreEqual(1, grid.GetRegion(0, 2).GetCell(0, 1).GetValue());
			Assert::AreEqual(1, grid.GetRegion(0, 2).GetCell(0, 2).GetValue());
		}

		TEST_METHOD(OnlyOneChoiceRegion)
		{
			vector<string> stringInput = vector<string>(9);
			/*grid:
			Regions : 123456-89
			7th cell should be filled with 7s
			*/
			for (int i = 0; i < 9; i++)
			{
				stringInput[i] = "123456-89";
			}

			OnlyOneChoiceInRegionVisitor visitor;
			Grid grid = Grid(stringInput);
			Assert::AreEqual(-1, grid.GetRegion(0, 0).GetCell(2, 0).GetValue());
			Assert::AreEqual(-1, grid.GetRegion(0, 1).GetCell(2, 0).GetValue());
			Assert::AreEqual(-1, grid.GetRegion(0, 2).GetCell(2, 0).GetValue());
			Assert::AreEqual(-1, grid.GetRegion(1, 0).GetCell(2, 0).GetValue());
			Assert::AreEqual(-1, grid.GetRegion(1, 1).GetCell(2, 0).GetValue());
			Assert::AreEqual(-1, grid.GetRegion(1, 2).GetCell(2, 0).GetValue());
			Assert::AreEqual(-1, grid.GetRegion(2, 0).GetCell(2, 0).GetValue());
			Assert::AreEqual(-1, grid.GetRegion(2, 1).GetCell(2, 0).GetValue());
			Assert::AreEqual(-1, grid.GetRegion(2, 2).GetCell(2, 0).GetValue());
			bool filled = grid.Accept(visitor);
			Assert::IsTrue(filled);

			//Cells should have been filled with 7s
			Assert::AreEqual(7, grid.GetRegion(0, 0).GetCell(2, 0).GetValue());
			Assert::AreEqual(7, grid.GetRegion(0, 1).GetCell(2, 0).GetValue());
			Assert::AreEqual(7, grid.GetRegion(0, 2).GetCell(2, 0).GetValue());
			Assert::AreEqual(7, grid.GetRegion(1, 0).GetCell(2, 0).GetValue());
			Assert::AreEqual(7, grid.GetRegion(1, 1).GetCell(2, 0).GetValue());
			Assert::AreEqual(7, grid.GetRegion(1, 2).GetCell(2, 0).GetValue());
			Assert::AreEqual(7, grid.GetRegion(2, 0).GetCell(2, 0).GetValue());
			Assert::AreEqual(7, grid.GetRegion(2, 1).GetCell(2, 0).GetValue());
			Assert::AreEqual(7, grid.GetRegion(2, 2).GetCell(2, 0).GetValue());
		}

		TEST_METHOD(NineHolderForGrid)
		{
			vector<string> stringInput = vector<string>(9);
			/*grid:
			Regions: 123456789
			*/

			stringInput[0] = "123123123";
			stringInput[1] = "456456456";
			stringInput[2] = "789789789";
			for (int i = 3; i < 9; i++)
			{
				stringInput[i] = "123456789";
			}
			Grid grid = Grid(stringInput);
			NineHolder nh = grid.GetRow(0);
			for (int i = 0; i < 9; i++){
				Assert::AreEqual(i + 1, nh.GetCell(i).GetValue());
			}
		}

		TEST_METHOD(NineHolderIsValuePresent)
		{
			vector<string> stringInput = vector<string>(9);
			/*grid:
			First row: 157------
			*/

			stringInput[0] = "157123123";
			stringInput[1] = "---456456";
			stringInput[2] = "---789789";
			for (int i = 3; i < 9; i++)
			{
				stringInput[i] = "123456789";
			}
			Grid grid = Grid(stringInput);
			NineHolder nh = grid.GetRow(0);
			Assert::IsTrue(nh.isValuePresent(1));
			Assert::IsTrue(nh.isValuePresent(5));
			Assert::IsTrue(nh.isValuePresent(7));
			Assert::IsFalse(nh.isValuePresent(2));
			Assert::IsFalse(nh.isValuePresent(3));
			Assert::IsFalse(nh.isValuePresent(4));
			Assert::IsFalse(nh.isValuePresent(6));
			Assert::IsFalse(nh.isValuePresent(8));
			Assert::IsFalse(nh.isValuePresent(9));
		}

		TEST_METHOD(OnlySquareOnRowNoRegion)
		{
			vector<string> stringInput = vector<string>(9);
			// grid taken from SudokuDragon tutorial for OnlySquare
			stringInput[0] = "2619-87--";
			stringInput[1] = "495176832";
			stringInput[2] = "873-45--6";
			stringInput[3] = "12638-4--";
			stringInput[4] = "987654321";
			stringInput[5] = "--4-27689";
			stringInput[6] = "5--69-873";
			stringInput[7] = "763518249";
			stringInput[8] = "--87-2561";

			Grid grid = Grid(stringInput);
			OnlySquareVisitor visitor;
			Assert::AreEqual(-1, grid.GetRegion(0, 0).GetCell(1, 1).GetValue());
			Assert::AreEqual(-1, grid.GetRegion(0, 2).GetCell(1, 0).GetValue());
			bool filled = grid.Accept(visitor);
			Assert::IsTrue(filled);
			Assert::AreEqual(3, grid.GetRegion(0, 0).GetCell(1, 1).GetValue());
			Assert::AreEqual(2, grid.GetRegion(0, 2).GetCell(1, 0).GetValue());
		}

		TEST_METHOD(OnlySquareOnColumnNoRegion)
		{
			vector<string> stringInput = vector<string>(9);
			// grid is the precendent one transposed
			stringInput[0] = "2976--18-";
			stringInput[1] = "13428-6--";
			stringInput[2] = "568-97--3";
			stringInput[3] = "418973562";
			stringInput[4] = "963852741";
			stringInput[5] = "752614389";
			stringInput[6] = "8--74-356";
			stringInput[7] = "--6-28479";
			stringInput[8] = "-75--6821";

			Grid grid = Grid(stringInput);
			OnlySquareVisitor visitor;
			Assert::AreEqual(-1, grid.GetRegion(0, 0).GetCell(1, 1).GetValue());
			Assert::AreEqual(-1, grid.GetRegion(2, 0).GetCell(0, 1).GetValue());
			bool filled = grid.Accept(visitor);
			Assert::IsTrue(filled);
			Assert::AreEqual(3, grid.GetRegion(0, 0).GetCell(1, 1).GetValue());
			Assert::AreEqual(2, grid.GetRegion(2, 0).GetCell(0, 1).GetValue());
		}

		TEST_METHOD(OnlySquareRegion)
		{
			vector<string> stringInput = vector<string>(9);
			// grid taken from SudokuDragon tutorial for OnlySquare
			stringInput[0] = "2619-87--";
			stringInput[1] = "495176832";
			stringInput[2] = "873-45--6";
			stringInput[3] = "1-638-4-7";
			stringInput[4] = "987654321";
			stringInput[5] = "--4-27689";
			stringInput[6] = "5--69-873";
			stringInput[7] = "763518249";
			stringInput[8] = "--87-2561";

			Grid grid = Grid(stringInput);
			OnlySquareVisitor visitor;
			Assert::AreEqual(-1, grid.GetRegion(0, 0).GetCell(1, 1).GetValue());
			Assert::AreEqual(-1, grid.GetRegion(0, 2).GetCell(1, 0).GetValue());
			bool filled = grid.Accept(visitor);
			Assert::IsTrue(filled);
			Assert::AreEqual(3, grid.GetRegion(0, 0).GetCell(1, 1).GetValue());
			Assert::AreEqual(2, grid.GetRegion(0, 2).GetCell(1, 0).GetValue());
		}

	};
}