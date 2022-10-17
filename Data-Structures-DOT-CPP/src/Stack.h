#pragma once

#include "ArrayList.h"

template <typename T>
class Stack
{
public:
	void push(const T& element) noexcept(false)
	{
		_data.add(element);
	}

	void pop() noexcept
	{
		ASSERT(!_data.is_empty());

		_data.remove(_data.end() - 1);
	}

	[[nodiscard]] T& peek() noexcept
	{
		ASSERT(!_data.is_empty());

		return *(_data.end() - 1);
	}

	[[nodiscard]] const T& peek() const noexcept
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