//
// Created by wnoehring on 5/3/21.
//
#include "types.h"
#include "gravity.h"

void gravitation_on_particles(Forces_t &forces, const Masses_t &masses){
    for (int i = 0; i < forces.cols(); ++i) {
        forces(2, i) = gravitation(masses(i));
    }
}
