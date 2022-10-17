
#include "CppUnitTest.h"

#include <Queue.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DataStructuresDOTCPPTests
{
	TEST_CLASS(QueueTests)
	{
	public:

		TEST_METHOD(TestQueueInit)
		{
			Queue<int> queue;

			Assert::IsTrue(queue.is_empty());
			Assert::AreEqual((std::size_t) 0, queue.count());
		}

		TEST_METHOD(TestQueueEnqueue)
		{
			Queue<int> queue;

			queue.enqueue(1);

			Assert::IsFalse(queue.is_empty());
			Assert::AreEqual((std::size_t) 1, queue.count());
		}

		TEST_METHOD(TestQueueDequeue)
		{
			Queue<int> queue;

			queue.enqueue(1);

			Assert::IsFalse(queue.is_empty());
			Assert::AreEqual((std::size_t) 1, queue.count());

			queue.dequeue();

			Assert::IsTrue(queue.is_empty());
			Assert::AreEqual((std::size_t) 0, queue.count());
		}

		TEST_METHOD(TestQueueFront)
		{
			Queue<int> queue;

			queue.enqueue(1);
			queue.enqueue(2);
			queue.enqueue(3);

			Assert::AreEqual(1, queue.front());

			const auto &queue_const = queue;
			Assert::AreEqual(1, queue_const.front()); // test const front
		}

		TEST_METHOD(TestQueueBack)
		{
			Queue<int> queue;

			queue.enqueue(1);
			queue.enqueue(2);
			queue.enqueue(3);

			Assert::AreEqual(3, queue.back());

			const auto &queue_const = queue;
			Assert::AreEqual(3, queue_const.back()); // test const back
		}
	};
}
