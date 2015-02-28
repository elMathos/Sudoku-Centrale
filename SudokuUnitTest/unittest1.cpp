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
#include "TwoOutOfThreeRowVisitor.h"
#include "TwoOutOfThreeColumnVisitor.h"
#include "OnlyOneChoiceGlobalVisitor.h"

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
			3 first rows: 123456789
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

		TEST_METHOD(TwoOutOfThreeRows)
		{
			vector<string> stringInput = vector<string>(9);
			
			stringInput[0] = "----6-9--";
			stringInput[1] = "17----4-8";
			stringInput[2] = "---81---2";
			stringInput[3] = "--1------";
			stringInput[4] = "---------";
			stringInput[5] = "---------";
			stringInput[6] = "---------";
			stringInput[7] = "---------";
			stringInput[8] = "---------";

			Grid grid = Grid(stringInput);
			TwoOutOfThreeRowVisitor visitor;
			Assert::AreEqual(-1, grid.GetRegion(0, 0).GetCell(2, 1).GetValue());
			bool visited = grid.Accept(visitor);
			Assert::IsTrue(visited);
			Assert::AreEqual(1, grid.GetRegion(0, 0).GetCell(2, 1).GetValue());
		}

		TEST_METHOD(TwoOutOfThreeColumns)
		{
			vector<string> stringInput = vector<string>(9);
			/*Grid:
			4--------
			---5-----
			---Y-----    Y must be filled with a 4
			----4----
			---------
			---------
			---------
			-----4---
			---------
			*/
			stringInput[0] = "4--------";
			stringInput[1] = "---5-----";
			stringInput[2] = "---------";
			stringInput[3] = "---------";
			stringInput[4] = "-4-------";
			stringInput[5] = "---------";
			stringInput[6] = "---------";
			stringInput[7] = "-----4---";
			stringInput[8] = "---------";

			Grid grid = Grid(stringInput);
			TwoOutOfThreeColumnVisitor visitor;
			Assert::AreEqual(-1, grid.GetRegion(0, 1).GetCell(2, 0).GetValue());
			bool visited = grid.Accept(visitor);
			Assert::IsTrue(visited);
			Assert::AreEqual(4, grid.GetRegion(0, 1).GetCell(2, 0).GetValue());
		}

		TEST_METHOD(NineHolderRowConsistent)
		{
			vector<string> stringInput = vector<string>(9);
			/*grid:
			3 first rows: 123456789
			Then, not consistent
			*/

			stringInput[0] = "123123123";
			stringInput[1] = "456456456";
			stringInput[2] = "789789789";
			for (int i = 3; i < 9; i++)
			{
				stringInput[i] = "123456789";
			}
			Grid grid = Grid(stringInput);
			NineHolder firstRow = grid.GetRow(0);
			NineHolder secondRow = grid.GetRow(3); //TODO 2nd is not 3 if 1st is 0
			Assert::IsTrue(firstRow.isConsistent());
			Assert::IsFalse(secondRow.isConsistent());
		}

		TEST_METHOD(RegionHolderConsistent)
		{
			vector<string> stringInput = vector<string>(9);
			/*grid:
			3 first regions not consistent
			Then, 123456789
			*/

			stringInput[0] = "123123123";
			stringInput[1] = "456456456";
			stringInput[2] = "789789789";
			for (int i = 3; i < 9; i++)
			{
				stringInput[i] = "123456789";
			}
			Grid grid = Grid(stringInput);
			RegionHolder firstReg = grid.GetRegion(0, 0);
			RegionHolder secondReg = grid.GetRegion(1, 2);
			Assert::IsFalse(firstReg.isConsistent());
			Assert::IsTrue(secondReg.isConsistent());
		}

		TEST_METHOD(GridNotConsistent)
		{
			vector<string> stringInput = vector<string>(9);
			/*grid:
			3 first regions not consistent
			Then, 123456789
			*/

			stringInput[0] = "123123123";
			stringInput[1] = "456456456";
			stringInput[2] = "789789789";
			for (int i = 3; i < 9; i++)
			{
				stringInput[i] = "123456789";
			}
			Grid grid = Grid(stringInput);
			Assert::IsFalse(grid.isConsistent());
		}

		TEST_METHOD(FullGridConsistent)
		{
			vector<string> stringInput = vector<string>(9);
			// grid correctly filled

			stringInput[0] = "418526379";
			stringInput[1] = "592347681";
			stringInput[2] = "673981452";
			stringInput[3] = "782963154";
			stringInput[4] = "416725938";
			stringInput[5] = "395148726";
			stringInput[6] = "247891635";
			stringInput[7] = "153264879";
			stringInput[8] = "869537214";

			Grid grid = Grid(stringInput);
			Assert::IsTrue(grid.isConsistent());
		}

		TEST_METHOD(FullGridNotConsistent)
		{
			vector<string> stringInput = vector<string>(9);
			// grid not correctly filled (two 4s in region 6)

			stringInput[0] = "418526379";
			stringInput[1] = "592347681";
			stringInput[2] = "673981452";
			stringInput[3] = "782963154";
			stringInput[4] = "416725938";
			stringInput[5] = "395148726";
			stringInput[6] = "247894635";
			stringInput[7] = "153264879";
			stringInput[8] = "869537214";

			Grid grid = Grid(stringInput);
			Assert::IsFalse(grid.isConsistent());
		}

		TEST_METHOD(HolderConsistentWithEmptyCells)
		{
			vector<string> stringInput = vector<string>(9);

			stringInput[0] = "41-5263-9";
			stringInput[1] = "592347681";
			stringInput[2] = "673981452";
			stringInput[3] = "78296-154";
			stringInput[4] = "416725938";
			stringInput[5] = "39-148726";
			stringInput[6] = "247891635";
			stringInput[7] = "15--64879";
			stringInput[8] = "-6953-14-";

			Grid grid = Grid(stringInput);
			NineHolder fullRow = grid.GetRow(0);
			RegionHolder fullReg = grid.GetRegion(2, 1);
			Assert::IsTrue(fullRow.isConsistent());
			Assert::IsTrue(fullReg.isConsistent());
		}

		TEST_METHOD(GridConsistentWithEmptyCells)
		{
			vector<string> stringInput = vector<string>(9);

			stringInput[0] = "41-526379";
			stringInput[1] = "59-347681";
			stringInput[2] = "67-981452";
			stringInput[3] = "7829--154";
			stringInput[4] = "416-25938";
			stringInput[5] = "395148726";
			stringInput[6] = "247-91635";
			stringInput[7] = "15326--79";
			stringInput[8] = "86953721-";

			Grid grid = Grid(stringInput);
			Assert::IsTrue(grid.isConsistent());
		}

		TEST_METHOD(GridIsFull1)
		{
			vector<string> stringInput = vector<string>(9);
			// grid fully filled

			stringInput[0] = "418526379";
			stringInput[1] = "592347681";
			stringInput[2] = "673981452";
			stringInput[3] = "782963154";
			stringInput[4] = "416725938";
			stringInput[5] = "395148726";
			stringInput[6] = "247891635";
			stringInput[7] = "153264879";
			stringInput[8] = "869537214";

			Grid grid = Grid(stringInput);
			Assert::IsTrue(grid.isFull());
		}

		TEST_METHOD(GridIsFull2)
		{
			vector<string> stringInput = vector<string>(9);
			// grid not fully filled

			stringInput[0] = "418526379";
			stringInput[1] = "592347681";
			stringInput[2] = "673981452";
			stringInput[3] = "782963154";
			stringInput[4] = "416725938";
			stringInput[5] = "395148726";
			stringInput[6] = "247891635";
			stringInput[7] = "153264879";
			stringInput[8] = "86953721-";

			Grid grid = Grid(stringInput);
			Assert::IsFalse(grid.isFull());
		}

		TEST_METHOD(OnlyOneChoiceGlobal)
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

			OnlyOneChoiceGlobalVisitor visitor;
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

		TEST_METHOD(SolveEasyGrid1)
		{
			vector<string> stringInput = vector<string>(9);
			// one empty cell per region

			stringInput[0] = "418-26379";
			stringInput[1] = "59234-681";
			stringInput[2] = "-73981452";
			stringInput[3] = "-82963154";
			stringInput[4] = "41672593-";
			stringInput[5] = "39514-726";
			stringInput[6] = "24-891635";
			stringInput[7] = "1532-4879";
			stringInput[8] = "86953721-";

			Grid grid = Grid(stringInput);
			grid.Solve();
			Assert::AreEqual(5, grid.GetRegion(0, 0).GetCell(1, 0).GetValue());
			Assert::AreEqual(7, grid.GetRegion(0, 1).GetCell(1, 2).GetValue());
			Assert::AreEqual(6, grid.GetRegion(0, 2).GetCell(0, 0).GetValue());
			Assert::AreEqual(7, grid.GetRegion(1, 0).GetCell(0, 0).GetValue());
			Assert::AreEqual(8, grid.GetRegion(1, 1).GetCell(2, 2).GetValue());
			Assert::AreEqual(8, grid.GetRegion(1, 2).GetCell(1, 2).GetValue());
			Assert::AreEqual(7, grid.GetRegion(2, 0).GetCell(0, 2).GetValue());
			Assert::AreEqual(6, grid.GetRegion(2, 1).GetCell(1, 1).GetValue());
			Assert::AreEqual(4, grid.GetRegion(2, 2).GetCell(2, 2).GetValue());
		}

		TEST_METHOD(SolveEasyGrid2)
		{
			vector<string> stringInput = vector<string>(9);

			stringInput[0] = "418-26379";
			stringInput[1] = "59-34-681";
			stringInput[2] = "-73981452";
			stringInput[3] = "-82963154";
			stringInput[4] = "4167259--";
			stringInput[5] = "39514-726";
			stringInput[6] = "24-891635";
			stringInput[7] = "1532-4879";
			stringInput[8] = "-6953721-";

			Grid grid = Grid(stringInput);
			grid.Solve();
			Assert::AreEqual(5, grid.GetRegion(0, 0).GetCell(1, 0).GetValue());
			Assert::AreEqual(2, grid.GetRegion(0, 1).GetCell(0, 2).GetValue());
			Assert::AreEqual(7, grid.GetRegion(0, 1).GetCell(1, 2).GetValue());
			Assert::AreEqual(6, grid.GetRegion(0, 2).GetCell(0, 0).GetValue());
			Assert::AreEqual(7, grid.GetRegion(1, 0).GetCell(0, 0).GetValue());
			Assert::AreEqual(8, grid.GetRegion(1, 1).GetCell(2, 2).GetValue());
			Assert::AreEqual(3, grid.GetRegion(1, 1).GetCell(2, 1).GetValue());
			Assert::AreEqual(8, grid.GetRegion(1, 2).GetCell(1, 2).GetValue());
			Assert::AreEqual(7, grid.GetRegion(2, 0).GetCell(0, 2).GetValue());
			Assert::AreEqual(6, grid.GetRegion(2, 1).GetCell(1, 1).GetValue());
			Assert::AreEqual(4, grid.GetRegion(2, 2).GetCell(2, 2).GetValue());
			Assert::AreEqual(8, grid.GetRegion(2, 2).GetCell(0, 0).GetValue());
		}


		TEST_METHOD(SolveHardGridPart3)
		{
			vector<string> stringInput = vector<string>(9);
			// grid taken from SudokuDragon tutorial for OnlySquare
			stringInput[0] = "-----6--9";
			stringInput[1] = "--23----1";
			stringInput[2] = "6-3--1-52";
			stringInput[3] = "782----5-";
			stringInput[4] = "---------";
			stringInput[5] = "-9----726";
			stringInput[6] = "24-8--6-5";
			stringInput[7] = "1----48--";
			stringInput[8] = "8--5-----";

			Grid grid = Grid(stringInput);
			/*grid.Solve();
			Assert::AreEqual(4, grid.GetRegion(0, 0).GetCell(0, 0).GetValue());
			Assert::AreEqual(1, grid.GetRegion(0, 0).GetCell(0, 1).GetValue());
			Assert::AreEqual(8, grid.GetRegion(0, 0).GetCell(0, 2).GetValue());
			Assert::AreEqual(5, grid.GetRegion(0, 0).GetCell(1, 0).GetValue());
			Assert::AreEqual(2, grid.GetRegion(0, 0).GetCell(1, 1).GetValue());
			Assert::AreEqual(6, grid.GetRegion(0, 0).GetCell(1, 2).GetValue());
			Assert::AreEqual(3, grid.GetRegion(0, 0).GetCell(2, 0).GetValue());
			Assert::AreEqual(7, grid.GetRegion(0, 0).GetCell(2, 1).GetValue());
			Assert::AreEqual(9, grid.GetRegion(0, 0).GetCell(2, 2).GetValue());
			Assert::AreEqual(5, grid.GetRegion(0, 1).GetCell(0, 0).GetValue());
			Assert::AreEqual(8, grid.GetRegion(0, 1).GetCell(2, 1).GetValue());
			Assert::AreEqual(9, grid.GetRegion(0, 2).GetCell(1, 0).GetValue());
			Assert::AreEqual(4, grid.GetRegion(0, 2).GetCell(2, 0).GetValue());
			Assert::AreEqual(9, grid.GetRegion(1, 0).GetCell(1, 0).GetValue());
			Assert::AreEqual(1, grid.GetRegion(1, 0).GetCell(2, 0).GetValue());
			Assert::AreEqual(4, grid.GetRegion(1, 1).GetCell(0, 0).GetValue());
			Assert::AreEqual(1, grid.GetRegion(1, 1).GetCell(0, 1).GetValue());
			Assert::AreEqual(6, grid.GetRegion(1, 1).GetCell(0, 2).GetValue());
			Assert::AreEqual(7, grid.GetRegion(1, 1).GetCell(1, 0).GetValue());
			Assert::AreEqual(2, grid.GetRegion(1, 1).GetCell(1, 1).GetValue());
			Assert::AreEqual(5, grid.GetRegion(1, 1).GetCell(1, 2).GetValue());
			Assert::AreEqual(9, grid.GetRegion(1, 1).GetCell(2, 0).GetValue());
			Assert::AreEqual(3, grid.GetRegion(1, 1).GetCell(2, 1).GetValue());
			Assert::AreEqual(8, grid.GetRegion(1, 1).GetCell(2, 2).GetValue());
			Assert::AreEqual(3, grid.GetRegion(1, 2).GetCell(0, 0).GetValue());
			Assert::AreEqual(4, grid.GetRegion(1, 1).GetCell(0, 0).GetValue());
			Assert::AreEqual(7, grid.GetRegion(2, 0).GetCell(2, 0).GetValue());
			Assert::AreEqual(3, grid.GetRegion(2, 0).GetCell(2, 1).GetValue());
			Assert::AreEqual(5, grid.GetRegion(2, 1).GetCell(0, 2).GetValue());
			Assert::AreEqual(9, grid.GetRegion(2, 1).GetCell(2, 2).GetValue());
			Assert::AreEqual(9, grid.GetRegion(2, 2).GetCell(0, 2).GetValue());
			Assert::AreEqual(3, grid.GetRegion(2, 2).GetCell(1, 1).GetValue());
			Assert::AreEqual(7, grid.GetRegion(2, 2).GetCell(1, 2).GetValue());
			Assert::AreEqual(2, grid.GetRegion(2, 2).GetCell(2, 0).GetValue());
			Assert::AreEqual(1, grid.GetRegion(2, 2).GetCell(2, 1).GetValue());
			Assert::AreEqual(4, grid.GetRegion(2, 2).GetCell(2, 2).GetValue());*/
		}

	};
}