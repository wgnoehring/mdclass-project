//
// Created by wnoehring on 4/27/21.
//

#ifndef YAMD_VERLET_H
#define YAMD_VERLET_H

#include "types.h"

void verlet_step1(Positions_t &positions, Velocities_t &velocities, const Forces_t &forces, double timestep, double mass);

void verlet_step2(Velocities_t &velocities, const Forces_t &forces, double timestep, double mass);

#endif //YAMD_VERLET_H
