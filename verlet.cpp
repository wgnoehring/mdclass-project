//
// Created by wnoehring on 4/27/21.
//
//
/* Verlet integration */

#include "types.h"

void verlet_step1(Positions_t &positions, Velocities_t &velocities, const Forces_t &forces, double timestep, Masses_t masses) {
    for (int i = 0; i < velocities.rows(); ++i) {
        velocities.row(i) += forces.row(i) * 0.5 * timestep / masses.transpose();
    }
    for (int i = 0; i < positions.rows(); ++i) {
        positions.row(i) += velocities.row(i) * timestep;
    }
}

void verlet_step2(Velocities_t &velocities, const Forces_t &forces, double timestep, Masses_t masses) {
    for (int i = 0; i < velocities.rows(); ++i) {
        velocities.row(i) += forces.row(i) * 0.5 * timestep / masses.transpose();
    }
}
