//
// Created by wnoehring on 4/27/21.
//


void verlet_step1(double &x, double &y, double &z, double &vx, double &vy, double &vz,
                  double fx, double fy, double fz, double timestep, double mass) {
    double dtm = 0.5 * timestep / mass;
    vx += fx * dtm;
    vy += fy * dtm;
    vz += fz * dtm;
    x += vx * timestep;
    y += vy * timestep;
    z += vz * timestep;
}

void verlet_step2(double &vx, double &vy, double &vz, double fx, double fy, double fz,
                  double timestep, double mass) {
    double dtm = 0.5 * timestep / mass;
    vx += fx * dtm;
    vy += fy * dtm;
    vz += fz * dtm;
    // implement verlet step
}