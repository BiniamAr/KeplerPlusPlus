#include "Simulation.h"
#include "Propagator.h"
#include "Constants.h"
#include "State.h"
#include <iostream>
#include <fstream>
Simulation::Simulation(const Satellite &sat, double time, double t_t) : sat(sat), t(time), total_t(t_t){} 
void Simulation::run()
{
	
	State initial = {t, sat.Position, sat.Velocity}; 
	history.push_back(initial); 
	while (t < total_t){ 
		sat = Propagator::computeEuler(sat, Constants::DT);
		t += Constants::DT; 
		State st = {t, sat.Position, sat.Velocity}; 
		history.push_back(st); 
		//printState(); 
	}
}
void Simulation::printState(){
	std::cout <<"x = " << sat.Position.x_val
		<< " y = " << sat.Position.y_val
		<< " z = " << sat.Position.z_val
		<< "\n"; 

}
const std::vector<State>& Simulation::getHistory() const{
	return history;
}
void Simulation::exportHistory(const std::string& filename) const
{
	std::ofstream outfile(filename);
	if (!outfile.is_open())
	{
		std::cerr << "can't open file";
		return;
	}
	outfile << "time,x,y,z,vx,vy,vz\n"; 

	for (const auto& st : history){
		outfile << st.time << ","
			<< st.position.x_val << "," 
			<< st.position.y_val << ","
			<< st.position.z_val << ","
			<< st.velocity.x_val << ","
			<< st.velocity.y_val << ","
			<< st.velocity.z_val << "\n";

	}
	outfile.close(); 
}
