#ifndef SATELLITE_H
#define SATELLITE_H
#include "Vector3.h"
class Satellite {
	public:
		Vector3 Velocity; 
		Vector3 Position; 
		Satellite(const Vector3 &vel, const Vector3 &pos); 

};
#endif

