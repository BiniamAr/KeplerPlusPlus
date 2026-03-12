#include "Physics.h"
#include "Propagator.h"
#include "Vector3.h"
//This function takes in a satellite and dt to computes euler and returns the new satellite with new pos and vel
Propagator::Deriv Propagator::derivatives(const Satellite &sat)
{
	//compute gravitational acceleration at current pos
	Vector3 a = Physics::computeGravity(sat.Position); 
	return {sat.Velocity, a}; 
}
Satellite Propagator::computeEuler(const Satellite &sat, double dt)
{
	// acceleration due to gravity
	Vector3 grav = Physics::computeGravity(sat.Position); 
	//update velocity 
	Vector3 newVel = sat.Velocity.add(grav.multiply(dt)); 
	//update position
	Vector3 newPos = sat.Position.add(newVel.multiply(dt));
	return Satellite(newVel, newPos); 

}
Satellite Propagator::computeRK4(const Satellite &sat, double dt)
{
	// k1: derivative at the beginning of the interval
	Deriv k1 = derivatives(sat); 
	// k2: derivative at midpoint using k1 estimate
	Satellite s2(sat.Velocity.add(k1.dv.multiply(dt * 0.5)),
			sat.Position.add(k1.dr.multiply(dt * 0.5))
			); 
	Deriv k2 = derivatives(s2); 
	
	// k3: another derivative at midpoint using k2 
	Satellite s3(sat.Velocity.add(k2.dv.multiply(dt * 0.5)),
			sat.Position.add(k2.dr.multiply(dt * 0.5))
			); 
	Deriv k3 = derivatives(s3);

	//k4: derivative at the end of the interval using k3
	Satellite s4(sat.Velocity.add(k3.dv.multiply(dt)),
			sat.Position.add(k3.dr.multiply(dt))
			); 
	Deriv k4 = derivatives(s4); 

	//combine weighted derivativees to compute final velocity 
	Vector3 newVel = sat.Velocity.add(k1.dv.multiply(dt / 6.0)
			.add(k2.dv.multiply(dt / 3.0))
			.add(k3.dv.multiply(dt / 3.0))
			.add(k4.dv.multiply(dt / 6.0))
			); 
	//combine weighted derivatives to compute fina position
	Vector3 newPos = sat.Position.add(k1.dr.multiply(dt / 6.0)
			.add(k2.dr.multiply(dt / 3.0))
			.add(k3.dr.multiply(dt / 3.0))
			.add(k4.dr.multiply(dt / 6.0))
			); 
	return Satellite(newVel, newPos); 
}

