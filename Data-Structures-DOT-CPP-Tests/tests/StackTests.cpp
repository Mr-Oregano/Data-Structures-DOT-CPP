
#include "CppUnitTest.h"

#include <Stack.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DataStructuresDOTCPPTests
{
	TEST_CLASS(StackTests)
	{
	public:

		TEST_METHOD(TestStackInit)
		{
			Stack<int> stack;

			Assert::IsTrue(stack.is_empty());
			Assert::AreEqual((std::size_t) 0, stack.count());
		}

		TEST_METHOD(TestStackPush)
		{
			Stack<int> stack;

			stack.push(1);

			Assert::IsFalse(stack.is_empty());
			Assert::AreEqual((std::size_t) 1, stack.count());
		}

		TEST_METHOD(TestStackPop)
		{
			Stack<int> stack;

			stack.push(1);

			Assert::IsFalse(stack.is_empty());
			Assert::AreEqual((std::size_t) 1, stack.count());

			stack.pop();

			Assert::IsTrue(stack.is_empty());
			Assert::AreEqual((std::size_t) 0, stack.count());
		}

		TEST_METHOD(TestStackPeek)
		{
			Stack<int> stack;

			stack.push(1);

			Assert::AreEqual(1, stack.peek());

			const auto &stack_const = stack;
			Assert::AreEqual(1, stack_const.peek()); // test const peek
		}
	};
}
