#include "scaling.h"

//Returns a scaling matrix

Matriz scaling(float sx, float sy, float sz) {
    Matriz scale;
    scale << sx, 0, 0, 0,
        0, sy, 0, 0,
        0, 0, sz, 0,
        0, 0, 0, 1;
    return scale;
}