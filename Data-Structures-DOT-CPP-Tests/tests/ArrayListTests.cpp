
#include "CppUnitTest.h"

#include <ArrayList.h>

#include <iostream>
#include <cctype>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ArrayListTests
{
	TEST_CLASS(DataStructuresDOTCPPTests)
	{
	public:
		
		TEST_METHOD(TestArrayListInit)
		{
			ArrayList<int> list;

			Assert::IsTrue(list.is_empty());
			Assert::AreEqual((std::size_t) 0, list.count());
		}

		TEST_METHOD(TestArrayListInitWithCapacity)
		{
			ArrayList<int> list(4);

			Assert::IsTrue(list.is_empty());
			Assert::AreEqual((std::size_t) 4, list.capacity());
			Assert::AreEqual((std::size_t) 0, list.count());
		}

		TEST_METHOD(TestArrayListReserve)
		{
			ArrayList<int> list;

			Assert::AreEqual((std::size_t) 1, list.capacity());
			Assert::AreEqual((std::size_t) 0, list.count());

			list.reserve(4);

			Assert::AreEqual((std::size_t) 4, list.capacity());
			Assert::AreEqual((std::size_t) 0, list.count());
		}

		TEST_METHOD(TestArrayListAdd)
		{
			ArrayList<int> list;

			list.add(9);

			Assert::IsFalse(list.is_empty());
			Assert::AreEqual((std::size_t) 1, list.count());
			Assert::AreEqual(9, list[0]);
		}

		TEST_METHOD(TestArrayListInsertAt)
		{
			ArrayList<int> list;

			list.add(9);
			Assert::AreEqual(9, list[0]);

			list.insert_at(0, 6);
			Assert::AreEqual((std::size_t) 2, list.count());
			Assert::AreEqual(6, list[0]);
			Assert::AreEqual(9, list[1]);

			list.insert_at(1, 2);
			Assert::AreEqual((std::size_t) 3, list.count());
			Assert::AreEqual(6, list[0]);
			Assert::AreEqual(2, list[1]);
			Assert::AreEqual(9, list[2]);
		}

		TEST_METHOD(TestArrayListGet)
		{
			ArrayList<int> list;

			list.add(9);
			list.add(6);

			Assert::AreEqual((std::size_t) 2, list.count());
			Assert::AreEqual(9, list[0]);
			Assert::AreEqual(6, list[1]);
		}

		TEST_METHOD(TestArrayListRemoveAt)
		{
			ArrayList<int> list;

			for (int i = 1; i <= 5; ++i)
				list.add(i);

			Assert::AreEqual((std::size_t) 5, list.count());
			Assert::AreEqual(list.begin() + 2, list.remove_at(2));

			Assert::AreEqual((std::size_t) 4, list.count());

			std::size_t index = 0;
			for (int i = 1; i <= 5; ++i)
			{
				if (i - 1 == 2)
					continue;

				Assert::AreEqual(i, list[index++]);
			}
		}

		TEST_METHOD(TestArrayListRemove)
		{
			ArrayList<int> list;

			for (int i = 1; i <= 5; ++i)
				list.add(i);

			Assert::AreEqual((std::size_t) 5, list.count());
			
			list.remove(list.begin() + 1);
			
			Assert::AreEqual((std::size_t) 4, list.count());
			
			std::size_t index = 0;
			for (int i = 1; i <= 5; ++i)
			{
				if (i == 2)
					continue;

				Assert::AreEqual(i, list[index++]);
			}
		}

		TEST_METHOD(TestArrayListClear)
		{
			ArrayList<int> list;

			for (int i = 1; i <= 5; ++i)
				list.add(i);

			Assert::AreEqual((std::size_t) 5, list.count());

			list.clear();

			Assert::IsTrue(list.is_empty());
			Assert::AreEqual((std::size_t) 0, list.count());
		}

		TEST_METHOD(TestArrayListBegin)
		{
			ArrayList<int> list;

			list.add(6);
			list.add(9);

			Assert::AreEqual(6, *list.begin());
		}

		TEST_METHOD(TestArrayListEnd)
		{
			ArrayList<int> list;

			list.add(6);
			list.add(9);

			Assert::AreEqual(9, *(list.end() - 1));
		}

		TEST_METHOD(TestArrayListIterate)
		{
			ArrayList<int> list;

			list.add(1);
			list.add(2);
			list.add(3);
			list.add(4);
			list.add(5);

			int counter = 1;
			for (int x : list)
				Assert::AreEqual(counter++, x);
		}
	};
}
