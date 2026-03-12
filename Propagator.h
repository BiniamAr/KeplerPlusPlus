//Note for next time:
//the satellite class will be storing the position and velocity of the satellite so it will have two vectors the pos and vel where it it takes in const pos and vel and and intiliz the satellite :position(pos), velocity(vel){} ir returns satellie satelite
//propagator will calculate teh simulation loop by creating a static method and taking in satelie and double dt then calles accelration the sat.velcoity and sat.posion .. similar to main
//
#ifndef PROPAGATOR_H
#define PROPAGATOR_H
#include "Satellite.h"
#include "Vector3.h"
class Propagator {
	public:
		//simple forward euler integrator 
		//innacuurate for orbital mechanics but useful for testing
		static Satellite computeEuler(const Satellite &sat, double dt);
		//Runge-kutta integrator: more accurate and stable than Euler. 
		//samples he drivative four times to approximate the curvature. 
		static Satellite computeRK4(const Satellite &sat, double dt); 
	private:
		struct Deriv {
			Vector3 dr; //derivative of position
			Vector3 dv; //derivative of velocity
		}; 
		//computes the time-derivatives of the satellite 
		static Deriv derivatives(const Satellite &sat);
};
#endif 
