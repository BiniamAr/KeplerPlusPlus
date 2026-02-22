//Note for next time:
//the satellite class will be storing the position and velocity of the satellite so it will have two vectors the pos and vel where it it takes in const pos and vel and and intiliz the satellite :position(pos), velocity(vel){} ir returns satellie satelite
//propagator will calculate teh simulation loop by creating a static method and taking in satelie and double dt then calles accelration the sat.velcoity and sat.posion .. similar to main
//
#ifndef PROPAGATOR_H
#define PROPAGATOR_H
#include "Satellite.h"
class Propagator {
	public:
		static Satellite computeEuler(const Satellite &sat, double dt);

};
#endif 
