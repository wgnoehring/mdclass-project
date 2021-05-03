#include <iostream>
#include <iomanip>
#include <cmath>
#include "run.h"

int main() {
    double  x{0.0},  y{0.0},  z{0.0};
    double vx{0.0}, vy{0.0}, vz{0.0};
    double angle = 45.0 / 180.0 * M_PI;
    double initial_velocity = 1.0;
    vx = initial_velocity * cos(angle);
    vz = initial_velocity * sin(angle);
    run(x, y, z, vx, vy, vz);
    return 0;
}
