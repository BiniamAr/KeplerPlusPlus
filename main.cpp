#include <iostream>
#include "Vector3.h"
#include "Physics.h"
#include "Constants.h"
int main()
{
	 
	Vector3 pos(2.0, 3.0, 5.0), vel(1.0, 2.0, 3.0);
	Vector3 grav = Physics::computeGravity(pos); 
	vel = vel.add(grav.multiply(Constants::DT));
	pos = pos.add(vel.multiply(Constants::DT)); 
	std::cout << "X = " << pos.x_val << " Y = " << pos.y_val << " Z = " << pos.z_val; 
	return 0; 
}
