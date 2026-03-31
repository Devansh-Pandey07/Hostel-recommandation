#include <stdio.h>

float calculateChance(int beds, float cgpa)
{
    float base;

    if (beds > 200)
        base = 0.9;
    else if (beds > 100)
        base = 0.75;
    else if (beds > 50)
        base = 0.6;
    else
        base = 0.4;

    return base * (cgpa / 10.0);
}