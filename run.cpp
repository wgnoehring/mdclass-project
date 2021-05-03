//
// Created by wnoehring on 5/3/21.
//
#include <iostream>
#include <iomanip>
#include "types.h"
#include "verlet.h"
#include "gravity.h"

void run(Positions_t &positions, Velocities_t &velocities){
    double timestep = 0.001;
    double mass = 1.0;
    int nb_steps = 1000;
    Forces_t forces(3, positions.cols());
    Masses_t masses(positions.cols());
    masses = mass;

    //std::cout << std::setw(20) << x <<  std::setw(20) << y << std::setw(20) << z << std::endl;
    std::cout << positions << std::endl;
    for (int i = 0; i < nb_steps; ++i) {
        gravitation_on_particles(forces, masses);
        verlet_step1(positions, velocities, forces, timestep, mass);
        gravitation_on_particles(forces, masses);
        verlet_step2(velocities, forces, timestep, mass);
    }
    std::cout << positions << std::endl;
}

