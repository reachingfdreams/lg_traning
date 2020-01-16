#include "unit03.h"

#include <math.h>
#include <memory>
#include <vector>

namespace unit03 {

/////////////////////////////////////////////////////////////////////////
////////////////////////////////// Shape ////////////////////////////////
/////////////////////////////////////////////////////////////////////////

void Shape::DisplayInfo() const {
	if (IsValid()) {
		std::cout << "Shape Name: " << GetName() << std::endl;
		std::cout << "- The perimeter is " << GetSum() << std::endl;
		std::cout << "- The area is " << GetArea() << std::endl;
	} else {
		std::cout << "Invalid " << GetName() << std::endl;
	}
	std::cout << std::endl;
}

/////////////////////////////////////////////////////////////////////////
/////////////////////////////// Triangle ////////////////////////////////
/////////////////////////////////////////////////////////////////////////

// static
const char* Triangle::kName = "Triangle";

Triangle::Triangle() {}

Triangle::Triangle(float line1, float line2, float line3)
	: line1_(line1), line2_(line2), line3_(line3) {
}

Triangle::~Triangle() {
}

std::string Triangle::GetName() const {
	return Triangle::kName;
}

float Triangle::GetArea() const {
	if (!IsValid())
		return 0;
	float p = GetSum() / 2;
	return sqrt(p * (p - line1_) * (p - line2_) * (p - line3_));
}

float Triangle::GetSum() const {
	if (IsValid())
		return line1_ + line2_ + line3_;
	return 0;
}

bool Triangle::IsValid() const {
	return line1_ + line2_ > line3_&&
		line1_ + line3_ > line2_ &&
		line2_ + line3_ > line1_;
}

/////////////////////////////////////////////////////////////////////////
///////////////////////// SquareTriangle ////////////////////////////////
/////////////////////////////////////////////////////////////////////////

// static
const char* SquareTriangle::kName = "Square Triangle";

SquareTriangle::SquareTriangle(float sq_line1, float sq_line2)
	: sq_line1_(sq_line1), sq_line2_(sq_line2) {
}

SquareTriangle::~SquareTriangle() {
}

std::string SquareTriangle::GetName() const {
	return SquareTriangle::kName;
}

float SquareTriangle::GetArea() const {
	if (!IsValid())
		return 0;
	return (sq_line1_ * sq_line2_) / 2;
}

float SquareTriangle::GetSum() const {
	if (IsValid())
		return 2 * (sq_line1_ + sq_line2_);
	return 0;
}

bool SquareTriangle::IsValid() const {
	return sq_line1_ != 0 && sq_line2_ != 0;
}

/////////////////////////////////////////////////////////////////////////
//////////////////////////////// Helper /////////////////////////////////
/////////////////////////////////////////////////////////////////////////

void RunAssignmentOfUnit03() {
	std::vector<std::unique_ptr<Shape>> shapes;
	shapes.push_back(std::make_unique<Triangle>(3, 4, 5));
	shapes.push_back(std::make_unique<Triangle>(3, 10, 5));
	shapes.push_back(std::make_unique<SquareTriangle>(8, 4));
	for (const auto& shape : shapes)
		shape->DisplayInfo();
}

}	// namespace unit03