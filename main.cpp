#include <iostream>
#include "verlet.h"

int main() {
    double x{0.0}, y{0.0}, z{0.0};
    double vx{0.0}, vy{0.0}, vz{0.0};
    double fx{0.0}, fy{0.0}, fz{0.0};
    double timestep = 0.01;
    double mass = 1.0;
    int nb_steps = 1000;
    for (int i = 0; i < nb_steps; ++i) {
        verlet_step1(x, y, z, vx, vy, vz, fx, fy, fz, timestep, mass);
        // recompute force
        verlet_step2(vx, vy, vz, fx, fy, fz, timestep, mass);
    }
    return 0;
}
