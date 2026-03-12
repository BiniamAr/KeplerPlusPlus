#include "Physics.h"
#include "Propagator.h"
#include "Vector3.h"
//This function takes in a satellite and dt to computes euler and returns the new satellite with new pos and vel
Propagator::Deriv Propagator::derivatives(const Satellite &sat)
{
	Vector3 a = Physics::computeGravity(sat.Position); 
	return {sat.Velocity, a}; 
}
Satellite Propagator::computeEuler(const Satellite &sat, double dt)
{
	Vector3 grav = Physics::computeGravity(sat.Position); 
	Vector3 newVel = sat.Velocity.add(grav.multiply(dt)); 
	Vector3 newPos = sat.Position.add(newVel.multiply(dt));
	return Satellite(newVel, newPos); 

}
Satellite Propagator::computeRK4(const Satellite &sat, double dt)
{
	Deriv k1 = derivatives(sat); 
	Satellite s2(sat.Velocity.add(k1.dv.multiply(dt * 0.5)),
			sat.Position.add(k1.dr.multiply(dt * 0.5))
			); 
	
	Deriv k2 = derivatives(s2); 
	Satellite s3(sat.Velocity.add(k2.dv.multiply(dt * 0.5)),
			sat.Position.add(k2.dr.multiply(dt * 0.5))
			); 
	Deriv k3 = derivatives(s3); 
	Satellite s4(sat.Velocity.add(k3.dv.multiply(dt)),
			sat.Position.add(k3.dr.multiply(dt))
			); 
	Deriv k4 = derivatives(s4); 
	Vector3 newVel = sat.Velocity.add(k1.dv.multiply(dt / 6.0)
			.add(k2.dv.multiply(dt / 3.0))
			.add(k3.dv.multiply(dt / 3.0))
			.add(k4.dv.multiply(dt / 6.0))
			); 
	Vector3 newPos = sat.Position.add(k1.dr.multiply(dt / 6.0)
			.add(k2.dr.multiply(dt / 3.0))
			.add(k3.dr.multiply(dt / 3.0))
			.add(k4.dr.multiply(dt / 6.0))
			); 
	return Satellite(newVel, newPos); 
}

