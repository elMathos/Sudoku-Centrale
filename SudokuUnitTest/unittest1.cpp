#include "stdafx.h"
#include "CppUnitTest.h"
#include "Cell.h"

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

	};
}