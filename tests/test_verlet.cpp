//
// Created by wnoehring on 5/3/21.
//
#include <iostream>
#include <iomanip>
#include <gtest/gtest.h>
#include <cmath>
#include "../gravity.h"
#include "../verlet.h"

// Test the Verlet integrator
TEST(VerletTest, BasicAssertions) {
    constexpr double abs_error = 1e-6; // acceptable error of integrator
    const double timestep = 0.0001;
    const double mass = 1.0;
    constexpr int nb_steps = 1000;
    // initial conditions
    const double x0{0.0}, y0{0.0}, z0{0.0};
    const double angle = 45.0 / 180.0 * M_PI;
    const double initial_velocity = 1.0;
    const double vx0 = initial_velocity * cos(angle);
    const double vy0 = 0.0;
    const double vz0 = initial_velocity * sin(angle);
    // numerical solution
    double   x{x0},   y{y0},   z{z0};
    double vx{vx0}, vy{vy0}, vz{vz0};
    double fx{0.0}, fy{0.0}, fz{0.0};
    // analytical solution
    double time = 0.0;
    double   xs{x},   ys{y},   zs{z};
    double vxs{vx}, vys{vy}, vzs{vz};
    for (int i = 0; i < nb_steps; ++i) {
        std::cout << "verlet integration step " << i << std::endl;
        fz = gravitation(mass);
        verlet_step1(x, y, z, vx, vy, vz, fx, fy, fz, timestep, mass);
        // first velocity verlet step calculates
        // velocities at t + 0.5 * dt and
        // positions at t + dt
        time = (i + 0.5) * timestep;
        vxs = vx0;
        vys = 0.0;
        vzs = vz0 - gravitational_acceleration * time;
        ASSERT_NEAR(vx, vxs, abs_error);
        ASSERT_NEAR(vy, vys, abs_error);
        ASSERT_NEAR(vz, vzs, abs_error);
        time = (i + 1.0) * timestep;
        xs = x0 + vx0 * time;
        ys = y0;
        zs = z0 + vz0 * time - 0.5 * gravitational_acceleration * time * time;
        ASSERT_NEAR(x, xs, abs_error);
        ASSERT_NEAR(y, ys, abs_error);
        ASSERT_NEAR(z, zs, abs_error);
        fz = gravitation(mass);
        verlet_step2(vx, vy, vz, fx, fy, fz, timestep, mass);
        time = (i + 1.0) * timestep;
        vxs = vx0;
        vys = 0.0;
        vzs = vz0 - gravitational_acceleration * time;
        ASSERT_NEAR(vx, vxs, abs_error);
        ASSERT_NEAR(vy, vys, abs_error);
        ASSERT_NEAR(vz, vzs, abs_error);
        if (z <= 0.0){
            break;
        }
    }
}
