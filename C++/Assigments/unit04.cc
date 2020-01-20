#include "unit04.h"

#include <algorithm>
#include <memory>

namespace unit04 {

Matrix::Matrix(Matrix&& other) noexcept : size_(other.size_), data_(std::move(other.data_)) {
}

Matrix::Matrix(const Size& size, int default_value) : size_(size) {
	// TODO: Check for the |size| <= 0
	// Also we can move the init of |data_| into the initialization list.
	data_ = std::vector<std::vector<int>>(size.row_size, std::vector<int>(size.column_size, default_value));
}

Matrix::Matrix(const std::vector<std::vector<int>>& data) {
	// TODO: check whether the |data_| is a matrix or not.
	data_ = data;
	size_.row_size = data.size();
	size_.column_size = data[0].size();
}

Matrix::~Matrix() {
}

Matrix& Matrix::operator++() {
	for (size_t r = 0; r < data_.size(); r++) {
		for (size_t c = 0; c < data_[r].size(); c++) {
			++data_[r][c];
		}
	}
	return *this;
}


Matrix Matrix::operator++(int) {
	Matrix tmp(*this);
	++(*this);
	return tmp;
}

Matrix Matrix::operator--(int) {
	Matrix tmp(*this);
	--(*this);
	return tmp;
}

Matrix& Matrix::operator--() {
	for (size_t r = 0; r < data_.size(); r++) {
		for (size_t c = 0; c < data_[r].size(); c++) {
			--data_[r][c];
		}
	}
	return *this;
}

Matrix Matrix::operator+(const Matrix& other) {
	Matrix tmp(*this);
	for (size_t r = 0; r < std::min(data_.size(), other.data_.size()); r++) {
		for (size_t c = 0; c < std::min(data_[r].size(), other.data_[r].size()); c++) {
			tmp.data_[r][c] += other.data_[r][c];
		}
	}
	return tmp;  // auto moved, no need to use std::move
}

Matrix Matrix::operator-(const Matrix& other) {
	Matrix tmp(*this);
	for (size_t r = 0; r < std::min(data_.size(), other.data_.size()); r++) {
		for (size_t c = 0; c < std::min(data_[r].size(), other.data_[r].size()); c++) {
			tmp.data_[r][c] -= other.data_[r][c];
		}
	}
	return tmp;  // auto moved, no need to use std::move
}

Matrix Matrix::operator*(const Matrix& other) {
	Matrix tmp(*this);
	for (size_t r = 0; r < std::min(data_.size(), other.data_.size()); r++) {
		for (size_t c = 0; c < std::min(data_[r].size(), other.data_[r].size()); c++) {
			tmp.data_[r][c] *= other.data_[r][c];
		}
	}
	return tmp;  // auto moved, no need to use std::move
}

Matrix Matrix::operator/(const Matrix& other) {
	Matrix tmp(*this);
	for (size_t r = 0; r < std::min(data_.size(), other.data_.size()); r++) {
		for (size_t c = 0; c < std::min(data_[r].size(), other.data_[r].size()); c++) {
			// TODO: Need to handle the case of deviding by zero.
			tmp.data_[r][c] /= other.data_[r][c];
		}
	}
	return tmp;  // auto moved, no need to use std::move
}

std::istream& operator>>(std::istream& is, Matrix& matrix) {
	std::cout << "Enter matrix size: " << std::endl;
	std::cout << "   Row size: ";
	// TODO: Handle the case of wrong input by user.
	is >> matrix.size_.row_size;
	std::cout << "   Column size: ";
	is >> matrix.size_.column_size;
	
	std::cout << std::endl;

	// Temporary variable.
	std::vector<std::vector<int>> data(matrix.size_.row_size, std::vector<int>(matrix.size_.column_size, 0));
	for (size_t i = 0; i < data.size(); ++i) {
		std::cout << "Input row " << i + 1 << ": ";
		for (size_t j = 0; j < data[i].size(); ++j) {
			is >> data[i][j];
		}
	}
	
	matrix.data_ = std::move(data);

	return is;
}

std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
	os << "Matrix Info" << std::endl;
	os << "The matrix size is: " << matrix.data_.size() << "x" << matrix.data_[0].size() << std::endl;
	for (size_t r = 0; r < matrix.data_.size(); r++) {
		os << "The row " << r + 1 << ": ";
		for (int c = 0; c < matrix.data_[r].size(); c++) {
			os << matrix.data_[r][c] << " ";
		}
		os << std::endl;
	}
	return os;
}

void RunAssignmentOfUnit04() {
	Matrix matrix;
	std::cin >> matrix;
	std::cout << std::endl;
	std::cout << matrix;

	// Increased by prefix. 
	++matrix;
	std::cout << std::endl;
	std::cout << "Increased by prefix." << std::endl;
	std::cout << matrix;
}

}	// namespace unit04