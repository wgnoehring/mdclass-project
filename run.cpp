//
// Created by wnoehring on 5/3/21.
//
#include <iostream>
#include <iomanip>
#include "verlet.h"
#include "gravity.h"

void run(const double x0, const double y0, const double z0, const double vx0, const double vy0, const double vz0){
    double  x{x0},  y{y0},  z{z0};
    double vx{vx0}, vy{vy0}, vz{vz0};
    double fx{0.0}, fy{0.0}, fz{0.0};
    double timestep = 0.001;
    double mass = 1.0;
    int nb_steps = 1000;

    std::cout << std::setw(20) << x <<  std::setw(20) << y << std::setw(20) << z << std::endl;
    for (int i = 0; i < nb_steps; ++i) {
        fz = gravitation(mass);
        verlet_step1(x, y, z, vx, vy, vz, fx, fy, fz, timestep, mass);
        fz = gravitation(mass);
        verlet_step2(vx, vy, vz, fx, fy, fz, timestep, mass);
        std::cout << std::setw(20) << x <<  std::setw(20) << y << std::setw(20) << z << std::endl;
        if (z <= 0.0){
            break;
        }
    }
}

