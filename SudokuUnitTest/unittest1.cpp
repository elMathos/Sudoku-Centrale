#include "stdafx.h"
#include "CppUnitTest.h"
#include "Cell.h"
#include "Region.h"
#include "Grid.h"
#include "RegionHolder.h"
#include "LastCellFinder.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SudokuUnitTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
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

		TEST_METHOD(GridTest)
		{
			vector<string> values1 = vector<string>(9);
			values1[0] = "1234-6789";
			for (int i = 1; i < 9; i++)
			{
				values1[i] = "123456789";
			}

			Grid grid1 = Grid(values1);

			RegionHolder regHold1 = RegionHolder(grid1.Get_rSE());

			//TODO Use Region::TopRow() and 2 other
			TripleHolder topRow1 = TripleHolder(grid1.Get_rNW().Get_cNW(), grid1.Get_rNW().Get_cN(), grid1.Get_rNW().Get_cNE());
			TripleHolder middleRow1 = TripleHolder(grid1.Get_rNW().Get_cW(), grid1.Get_rNW().Get_cC(), grid1.Get_rNW().Get_cE());
			TripleHolder bottomRow1 = TripleHolder(grid1.Get_rNW().Get_cSW(), grid1.Get_rNW().Get_cS(), grid1.Get_rNW().Get_cSE());

			LastCellFinder last1 = LastCellFinder(topRow1, middleRow1, bottomRow1);
			Assert::AreEqual(-1 , grid1.Get_rNW().Get_cC().GetValue());
			last1.fill();
			Assert::AreEqual(5, grid1.Get_rNW().Get_cC().GetValue());
		}

	};
}