#include <iostream>
#include <iomanip>
#include <cmath>
#include "types.h"
#include "run.h"

int main() {
    constexpr int nb_atoms = 3;
    Positions_t positions(3, nb_atoms);
    Velocities_t velocities(3, nb_atoms);
    double vx{0.0}, vy{0.0}, vz{0.0};
    double angle = 45.0 / 180.0 * M_PI;
    double initial_velocity = 1.0;
    vx = initial_velocity * cos(angle);
    vz = initial_velocity * sin(angle);
    velocities(0, 0) = vx;
    velocities(2, 0) = vz;
    run(positions, velocities);
    return 0;
}
