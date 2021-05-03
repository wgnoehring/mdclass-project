//
// Created by wnoehring on 4/27/21.
//

#ifndef YAMD_GRAVITY_H
#define YAMD_GRAVITY_H
constexpr double gravitational_acceleration = 9.81;
inline double gravitation(const double mass){return -mass * gravitational_acceleration;};
#endif //YAMD_GRAVITY_H
