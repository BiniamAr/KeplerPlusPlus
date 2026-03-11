#include "Physics.h"
#include "Propagator.h"
#include "Vector3.h"
//This function takes in a satellite and dt to computes euler and returns the new satellite with new pos and vel
Satellite Propagator::computeEuler(const Satellite &sat, double dt)
{
	Vector3 grav = Physics::computeGravity(sat.Position); 
	Vector3 newVel = sat.Velocity.add(grav.multiply(dt)); 
	Vector3 newPos = sat.Position.add(newVel.multiply(dt));
	return Satellite(newVel, newPos); 

}
