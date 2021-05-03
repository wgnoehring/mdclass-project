//
// Created by wnoehring on 4/27/21.
//

#ifndef YAMD_GRAVITY_H
#define YAMD_GRAVITY_H

#include "types.h"

constexpr double gravitational_acceleration = 9.81;
inline double gravitation(const double mass){return -mass * gravitational_acceleration;};
void gravitation_on_particles(Forces_t &forces, const Masses_t &masses);

#endif //YAMD_GRAVITY_H
