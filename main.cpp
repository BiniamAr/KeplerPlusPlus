#include <iostream>
#include "Vector3.h"
#include "Physics.h"
#include "Constants.h"
#include "Satellite.h"
#include "Propagator.h"
#include "Simulation.h"
#include <cmath>
int main()
{
	 
	double orbital_r = Constants::EARTH_RADIUS + 400000; 
	double orbit_v = std::sqrt(Constants::GM/orbital_r); 
	Vector3 pos(orbital_r, 0.0, 0.0), vel(0.0, orbit_v, 0);
	Satellite sat(vel, pos); 
	double t = 0.0; 
	double total_t = 100000.0;
	Simulation sim(sat, t, total_t); 
	sim.run(); 
	sim.exportHistory("orbit.csv");
	/*
	while (t < total_t)
	{
		sat = Propagator::computeEuler(sat, Constants::DT); 

		std::cout <<"x = " << sat.Position.x_val 
			<< " y = " << sat.Position.y_val 
			<< " z = " << sat.Position.z_val 
			<< "\n"; 
		t += Constants::DT; 
	} */	
	std::cout <<"---------------------------------------\n"; 
	//without satellite and propegator >>
	Vector3 grav = Physics::computeGravity(pos); 
	vel = vel.add(grav.multiply(Constants::DT));
	pos = pos.add(vel.multiply(Constants::DT)); 
	std::cout << "X = " << pos.x_val << " Y = " << pos.y_val << " Z = " << pos.z_val; 
	return 0; 
}
