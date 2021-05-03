//
// Created by wnoehring on 4/27/21.
//

#include "types.h"

void verlet_step1(Positions_t &positions, Velocities_t &velocities, const Forces_t &forces, double timestep, double mass) {
    double dtm = 0.5 * timestep / mass;
    velocities += forces * dtm;
    positions += velocities * timestep;
}

void verlet_step2(Velocities_t &velocities, const Forces_t &forces, double timestep, double mass) {
    double dtm = 0.5 * timestep / mass;
    velocities += forces * dtm;
}