#pragma once

#include "ArrayList.h"

template <typename T>
class Queue
{
public:
	void enqueue(const T &element) noexcept(false)
	{
		_data.add(element);
	}

	void dequeue() noexcept
	{
		ASSERT(!_data.is_empty());

		_data.remove(_data.begin());
	}

	[[nodiscard]] T &front() noexcept
	{
		ASSERT(!_data.is_empty());

		return *_data.begin();
	}

	[[nodiscard]] const T &front() const noexcept
	{
		ASSERT(!_data.is_empty());

		return *_data.begin();
	}

	[[nodiscard]] T &back() noexcept
	{
		ASSERT(!_data.is_empty());

		return *(_data.end() - 1);
	}

	[[nodiscard]] const T &back() const noexcept
	{
		ASSERT(!_data.is_empty());

		return *(_data.end() - 1);
	}

	[[nodiscard]] std::size_t count() const noexcept
	{
		return _data.count();
	}

	[[nodiscard]] bool is_empty() const noexcept
	{
		return _data.is_empty();
	}

private:
	ArrayList<T> _data;
};