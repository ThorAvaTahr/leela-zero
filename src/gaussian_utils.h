#pragma once
#include <cmath>
#define SQRT2 1.41421356237
#define PI 3.1415926538

// approximation of inverse erf 
float erfinv(float x) {
    float tt1, tt2, lnx, sgn;
    sgn = (x < 0) ? -1.0f : 1.0f;

    x = (1 - x)*(1 + x);        // x = 1 - x*x;
    lnx = std::logf(x);

    tt1 = 2 / (PI*0.147) + 0.5f * lnx;
    tt2 = 1 / (0.147) * lnx;

    return(sgn*std::sqrtf(-tt1 + std::sqrtf(tt1*tt1 - tt2)));
}


// calculate value of p given a normal distribution with parameters mean and variance (= square of std-dev)
float N_to_p(float value, float mean, float var)
{
    return 0.5f + std::erff((value - mean) / (std::sqrtf(var)*SQRT2)) / 2;
}

