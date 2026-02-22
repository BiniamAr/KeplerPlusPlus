#include "Vector3.h"
#include <cmath>
Vector3::Vector3(double x, double y, double z){
	x_val = x;
	y_val = y;
	z_val = z; 
}
Vector3 Vector3::add(const Vector3 &other) const{
	return Vector3(x_val + other.x_val,
			y_val + other.y_val, 
			z_val + other.z_val);
}
Vector3 Vector3::multiply(double scalar) const {
	return Vector3(x_val * scalar,
			y_val * scalar, 
			z_val * scalar);
}
double Vector3::magnitude() const {
	return std::sqrt((x_val * x_val) + (y_val * y_val) + (z_val * z_val)); 

}
