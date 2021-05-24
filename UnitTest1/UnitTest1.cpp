#include "pch.h"
#include "CppUnitTest.h"
#include "../Complex.cpp"
#include "../MyDerivedException.cpp"
#include "../MyException.cpp"
#include "../Complex.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Complex A(4, -1);
			Complex B(6, -3);

			Complex C = A + B;
			Assert::AreEqual(C.GetRe(), 10.0);
		}
	};
}
