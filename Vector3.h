#ifndef VECTOR3_H
#define VECTOR3_H
class Vector3 
{
	public:
	double x_val; 
	double y_val; 
	double z_val;  
	Vector3(double x, double y, double z); 
	Vector3 add(const Vector3 &other) const;
	Vector3 multiply(double scalar) const; 
	double magnitude() const;  
	
};
#endif 
