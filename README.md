# KeplerPlusPlus
High‑performance C++ re‑implementation of my satellite orbit propagator. Simulates Earth‑satellite motion using Newtonian gravity with a modular design for future features like drag, J2, and full N‑body dynamics. 
## Overview 
KeplerPlusPlus is a modern, modular rewrite of my original Python orbit simulator.
It provides: 
- A clean physics engine
- A reusable satellite state model
- A dedicated propagator for numerical integration
- A simulation controller that logs results
- A Python visualization tool (orbit.py) that renders a 3D orbit from CSV output

This structure mirrors real aerospace simulation pipelines.

## Current Modules 

Vector3: A lightweight 3d vector class supporting:
- addition 
- scalar multiplication 
- magnitude 
- basic vector math used throughout the physics engine 

Physics: Contains physics formulas for the simulation. 
currently implements:
- Gravitational acceleration using
$$a = \frac{-GMr}{r^3}$$

Constants: compile-time physical constants:
- Earth GM
- Earth radius
- simulation timestep

Satellite: Encapsulates the satellite’s dynamic state:
- Position vector
- Velocity vector
- Optional add later metadata (name, mass, etc.)

Propagator: Runs the numerical integration:
- Applies physics models
- Performs Euler integration (RK4 planned)
- Updates satellite state each timestep

Simulation: High‑level controller that:
- Owns the Propagator
- Runs the simulation loop
- Stores each timestep in a History struct
- Exports results to orbit.csv

orbit.py: Python visualization script that:
- Reads the CSV output
- Plots a 3D orbit around Earth
- Helps validate and visualize the simulation

Main: runs the program:
- creates a position and velocity vector 
- Runs the program and exports the csv output 

## Planned Modules
These are coming next as the project grows:
Force Models:
- atmospheric drag 
- J2 
- solar radiation pressure 
- Third-body gravity  (moon, sun)
- Full N-body dynamics

Integrator Upgrades
- Runge–Kutta 4 (RK4)
- Adaptive timestep integrators

## Build & Run 
compile with:
g++ main.cpp Vector3.cpp Physics.cpp Satellite.cpp Propagator.cpp Simulation.cpp Force.cpp -o kepler

Run:
./kelpler

Visualize:
python orbit.py

## Project Structure:

KeplerPlusPlus/
|
|-- Vector3.h / Vector3.cpp
|-- Physics.h / Physics.cpp
|-- Constants.h
|-- Satellite.h / Satellite.cpp
|-- Propagator.h / Propagator.cpp
|-- Simulation.h / Simulation.cpp
|-- Force.h / Force.cpp
|-- State.h
|-- main.cpp
|
|-- orbit.csv
|__ orbit.py

