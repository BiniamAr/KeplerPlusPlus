# KeplerPlusPlus
High‑performance C++ re‑implementation of my satellite orbit propagator. Simulates Earth‑satellite motion using Newtonian gravity with a modular design for future features like drag, J2, and full N‑body dynamics. 
## Overview 
KeplerPlusPlus is a clean, modern rewrite of the original Python orbit simulator. 

## Cuurent Modules 

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

Main: runs the program:
- creates a position and velocity vector 
- computes gravitational acceleration 
- performs one Euler integration step 
- prints the updated state 

## Planned Modules
These are coming next as the project grows:

Satellite: 
Stores state vectors (position, velocity) and metadata

Propagator:
runs the simulation loop and integrates motion over time

Force Models:
- atmospheric drag 
- J2 
- solar radiation pressure 
- Third-body gravity  (moon, sun)
- Full N-body dynamics

## Build & Run 
compile with g++
g++ main.cpp Vector3.cpp Physics.cpp -o kepler
./kelpler

