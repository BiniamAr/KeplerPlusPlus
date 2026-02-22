#include "Physics.h"
#include "Constants.h"
#include <cmath>
Vector3 Physics::computeGravity(const Vector3 &position){
	double r  = position.magnitude(); 
	double dist = r * r * r;
	double factor = -Constants::GM/dist; 
	return position.multiply(factor); 


}
