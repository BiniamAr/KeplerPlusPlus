//This Class will be responsible for holidng the current satellite state, running it and also printing the satellite positon
//
#ifndef SIMULATION_H
#define SIMULATION_H
#include "Satellite.h"
#include <vector>
#include "State.h"
#include <string>
class Simulation {
	Satellite sat;  
	double t; 
	double total_t; 
	std::vector<State> history; 
	public:
	Simulation(const Satellite &sat, double time, double t_t); 
	void run();
	const std::vector<State>& getHistory() const; 
	void printState();
	void exportHistory(const std::string& filename) const;
};
#endif 
