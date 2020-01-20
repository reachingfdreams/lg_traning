#ifndef UNIT04_H_
#define UNIT04_H_

#include <iostream>
#include <vector>

namespace unit04 {


// This is very simple class of Matrix,
// Some of the logics are not optmized totally and may contains of many bugs.
class Matrix {
 public:
     // Size object.
     struct Size {
         size_t row_size = 0;
         size_t column_size = 0;
     };

     Matrix() = default;
     Matrix(Matrix&& other) noexcept;
     Matrix(const Size& size, int default_value = 0);
     Matrix(const std::vector<std::vector<int>>& data);
     Matrix(const Matrix& other) = default;
     ~Matrix();

     Matrix& operator++();
     Matrix operator++(int);
     Matrix& operator--();
     Matrix operator--(int);

     Matrix operator+(const Matrix& other);
     Matrix operator-(const Matrix& other);
     Matrix operator*(const Matrix& other);
     Matrix operator/(const Matrix& other);

     friend std::istream& operator>>(std::istream& is, Matrix& matrix);
     friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix);

 private:
     Matrix::Size size_;
     std::vector<std::vector<int>> data_;
};

// Run the whole assignment of the unit04.
void RunAssignmentOfUnit04();


}  // namespace unit04

#endif // UNIT04_H_