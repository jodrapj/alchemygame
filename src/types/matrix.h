#pragma once

#include <vector>

template<typename T> 
struct matrix {
	std::vector<std::vector<T>> v; // value
	size_t s; // size
public:
	matrix(std::vector<std::vector<T>> value);
	matrix();
	std::vector<std::vector<T>> value();
	std::vector<std::vector<T>> size();
	std::vector<std::vector<T>> at(int x, int y);
	friend bool operator==(matrix const& p1, matrix const& p2);
};