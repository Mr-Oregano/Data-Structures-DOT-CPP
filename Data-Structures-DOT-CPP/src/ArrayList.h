#pragma once

#include <cstddef>
#include <cstring>

#include "Common.h"

// TODO:
//	- Implement copy and move assignment/construction
//	- Create iterator class wrapper rather than using pointers (for extended functionality and checks)
//	- Override constructor for range creation and pre-initialization
//	- Implement emplace addition for move construction

template <typename T>
class ArrayList
{
public:
	ArrayList(std::size_t initial_capacity = 1)
		: _data(new T[initial_capacity]), _count(0), _capacity(initial_capacity)
	{}

	~ArrayList()
	{
		delete [] _data;
	}

	ArrayList(const ArrayList&) = delete;
	ArrayList(ArrayList&&) = delete;
	ArrayList& operator=(const ArrayList&) = delete;
	ArrayList& operator=(ArrayList&&) = delete;

	// Throws std::bad_alloc if failed to allocate memory for array
	void add(const T& element) noexcept(false)
	{
		insert_at(_count, element);
	}

	// Throws std::bad_alloc if failed to allocate memory for array
	void insert_at(std::size_t index, const T &element) noexcept(false)
	{
		if (_count == _capacity)
			reserve(_capacity * 2);

		for (std::size_t i = _count; i > index; --i)
			_data[i] = _data[i - 1];

		_data[index] = element;
		++_count;
	}

	// Throws std::bad_alloc if failed to allocate memory for array
	// Undefined behaviour if 'amount' is smaller than current capacity
	void reserve(std::size_t amount) noexcept(false)
	{
		ASSERT(amount >= _capacity);

		auto prev_ptr = _data;
		_data = new T[amount];
		_capacity = amount;
		std::memcpy(_data, prev_ptr, _count * sizeof(T));
		delete[] prev_ptr;
	}

	// Undefined behaviour if 'index' is outside the range of the array
	T* remove_at(std::size_t index) noexcept
	{
		ASSERT(!is_empty() && index < _count);

		for (std::size_t i = index; i < _count - 1; ++i)
			_data[i] = _data[i + 1];

		--_count;
		return begin() + index;
	}

	// Undefined behaviour if 'it' is outside the range of the array
	void remove(const T* it) noexcept
	{
		ASSERT(!is_empty() && begin() <= it && it < end());
		remove_at(it - begin());
	}

	void clear() noexcept
	{
		_count = 0;
	}

	[[nodiscard]] T* begin() noexcept
	{
		return &_data[0];
	}

	[[nodiscard]] T *end() noexcept
	{
		return begin() + _count;
	}

	// Undefined behaviour if 'index' is outside the range of the array
	[[nodiscard]] T& operator[] (const std::size_t index) noexcept
	{
		ASSERT(index < _count);

		return _data[index];
	}

	// Undefined behaviour if 'index' is outside the range of the array
	[[nodiscard]] const T& operator[] (const std::size_t index) const noexcept
	{
		ASSERT(index < _count);

		return _data[index];
	}

	[[nodiscard]] bool is_empty() noexcept
	{
		return _count == 0;
	}

	[[nodiscard]] std::size_t count() const noexcept
	{
		return _count;
	}

	[[nodiscard]] std::size_t capacity() const noexcept
	{
		return _capacity;
	}

private:
	T *_data;
	std::size_t _count;
	std::size_t _capacity;
};