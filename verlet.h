//
// Created by wnoehring on 4/27/21.
//

#ifndef YAMD_VERLET_H
#define YAMD_VERLET_H


void verlet_step1(double &x, double &y, double &z, double &vx, double &vy, double &vz,
                  double fx, double fy, double fz, double timestep, double mass);
void verlet_step2(double &vx, double &vy, double &vz, double fx, double fy, double fz,
                  double timestep, double mass  );

#endif //YAMD_VERLET_H
