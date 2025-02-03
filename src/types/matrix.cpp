#include "matrix.h"

template<typename T>
matrix<T>::matrix(std::vector<std::vector<T>> value) : v(value) {

	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < i[j].size(); i++) {
			s++;
		}
	}

}

template<typename T>
matrix<T>::matrix() : v(std::vector<std::vector<T>>()) {}

template<typename T>
std::vector<std::vector<T>> matrix<T>::value() {
	return v;
}

template<typename T>
std::vector<std::vector<T>> matrix<T>::size() {
	return s;
}

template<typename T>
std::vector<std::vector<T>> matrix<T>::at(int x, int y) {
	return v[x][y];
}

template<typename T>
bool operator==(matrix<T> const& p1, matrix<T> const& p2) {
	return p1.value() == p2.value();
}

template<typename T>
bool operator+(matrix<T> const& p1, matrix<T> const& p2) {
	matrix<T>* result = new matrix<T>();
	
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < i[j]; j++) {
			result[i][j] = p1.value()[i][j] + p2.value()[i][j]
		}
	}

	return result;
}

template<typename T>
bool operator-(matrix<T> const& p1, matrix<T> const& p2) {
	matrix<T>* result = new matrix<T>();

	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < i[j]; j++) {
			result[i][j] = p1.value()[i][j] - p2.value()[i][j]
		}
	}

	return result;
}

template<typename T>
bool operator*(matrix<T> const& p1, matrix<T> const& p2) {
	matrix<T>* result = new matrix<T>();

	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < i[j]; j++) {
			result[i][j] = p1.value()[i][j] * p2.value()[i][j]
		}
	}

	return result;
}

template<typename T>
bool operator/(matrix<T> const& p1, matrix<T> const& p2) {
	matrix<T>* result = new matrix<T>();

	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < i[j]; j++) {
			result[i][j] = p1.value()[i][j] / p2.value()[i][j]
		}
	}

	return result;
}