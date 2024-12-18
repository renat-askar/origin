#pragma once
#include <utility>
#include <initializer_list>
#include <vector>
#include <algorithm>
#include <iostream>

template <typename T>
class ExtArray
{
	private:
		std::vector<T> extended_array;
		size_t _size;
	public:
		ExtArray(std::initializer_list<T> l) : extended_array(l)
		{
			_size = l.size();
		}

		ExtArray(int size) : _size(size)
		{
			extended_array.resize(_size);
		}

		T& operator[](size_t index)
		{
			return extended_array[index];
		}

		size_t size()
		{
			return _size;
		}

		double mean()
		{
			if(extended_array.empty()) return 0;
			double sum = 0;
			for (size_t i = 0; i < _size; i++)
			{
				sum += extended_array[i];
			}
			return sum / _size;
		}

		double mean(size_t start, size_t end)
		{
			if (extended_array.empty()) return 0;
			if (start >= extended_array.size() || end >= extended_array.size() || start >= end || start == 0)
				throw std::invalid_argument{"invalid range"};
			double sum = 0;
			double size = 0;
			for (size_t i = start; i <= end; i++, ++size)
			{
				sum += extended_array[i - 1];
			}
			return sum / size;
		}

		double median()
		{
			if (extended_array.empty()) return 0;
			std::vector<T> temp_array;
			std::copy(extended_array.begin(), extended_array.end(), back_inserter(temp_array));
			std::sort(temp_array.begin(), temp_array.end());
			if (_size % 2 == 1)
			{
				return temp_array[_size / 2];
			}
			else
			{
				return static_cast<double>(temp_array[(_size / 2) - 1] + temp_array[_size / 2]) / 2;
			}
		}

		std::pair<T, int> mode()
		{
			if (extended_array.empty()) return {0, 0};
			T max = extended_array[0], cmax = 0, rmax = 0;
			for (int i = 0; i < _size; i++) 
			{
				if (cmax > rmax) 
				{
					rmax = cmax;
					max = extended_array[i - 1];
				}
				cmax = 0;
				for (int j = i; j < _size; j++)
				{
					if (extended_array[j] == extended_array[i])
					{
						cmax++;
					}
				}
			}
			return std::pair<T, int>(max, rmax);
		}
		
		size_t checkSum()
		{
			constexpr const char* vector_bool_typeid{"class std::_Vb_reference<struct std::_Wrap_alloc<class std::allocator<unsigned int> > >"};
			if(strcmp(typeid(extended_array[0]).name(), "int"))
			if(strcmp(typeid(extended_array[0]).name(), vector_bool_typeid))
				throw std::bad_typeid{};
			size_t count{};
			for (size_t i{}; i < extended_array.size(); ++i)
			{
				if (extended_array[i] != 0 && extended_array[i] != 1)
					throw std::logic_error{ "bad sum" };

				if (extended_array[i] == 1)
					++count;
			}
			return count;
		}
};
