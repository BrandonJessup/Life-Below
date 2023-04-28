#ifndef GLOBALS_H
#define GLOBALS_H

namespace global
{
    const int EDGE_PAN_REGION_THICKNESS = 4;
    const int EDGE_PAN_SPEED = 600; // In pixels per second.
    const int WINDOW_NATIVE_RESOLUTION_X = 400;
    const int WINDOW_NATIVE_RESOLUTION_Y = 300;
    // const int WINDOW_SCALE = 2; // NOTE: Make constant (and change to constant case) once we settle on a scale to use.
    const int WINDOW_SCALING_MIN = 1; // TEMP: Remove once we settle on a scale to use.
    const int WINDOW_SCALING_MAX = 5; // TEMP: Remove once we settle on a scale to use.
}

#endif // GLOBALS_H