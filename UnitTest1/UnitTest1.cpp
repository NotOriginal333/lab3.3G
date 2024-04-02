#include "pch.h"
#include "CppUnitTest.h"
#include "../lab3.3G/Date.h"
#include "../lab3.3G/Date.cpp"
#include "../lab3.3G/Goods.h"
#include "../lab3.3G/Goods.cpp"
#include "../lab3.3G/Object.h"
#include "../lab3.3G/Object.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			Date today(2024, 3, 1);
			Date dateOfBirth("2000.12.31");
			int test = today.getYear();
			Assert::AreEqual(2024, test);
			test = dateOfBirth.getDay();
			Assert::AreEqual(31, test);
		}
	};
}
