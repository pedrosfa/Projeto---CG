#include "shearing.h"

//Returns a shearing matrix on the XZ plane in X direction

Matriz shearingXZtoX(float gamma)
{
    Matriz shear;
    shear << 1, tan(gamma), 0, 0,
        0, 1, 0, 0,
        0, 0, 1, 0,
        0, 0, 0, 1;

    return shear;
}

//Returns a shearing matrix on the XZ plane in Y direction

Matriz sheringXZtoY(float gamma)
{
    Matriz shear;
    shear << 1, 0, 0, 0,
        tan(gamma), 1, 0, 0,
        0, 0, 1, 0,
        0, 0, 0, 1;

    return shear;
}

//Returns a shearing matrix on the XZ plane in Z direction

Matriz shearingXZtoZ(float gamma)
{
    Matriz shear;
    shear << 1, 0, 0, 0,
        0, 1, 0, 0,
        0, tan(gamma), 1, 0,
        0, 0, 0, 1;

    return shear;
}

Matriz shearing(float gamma)
{
    Matriz shear;
    shear << 1, 0, 0, 0,
        0, 1, tan(gamma), 0,
        0, 0, 1, 0,
        0, 0, 0, 1;
    
    return shear;
}