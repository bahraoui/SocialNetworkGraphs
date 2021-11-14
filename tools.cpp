#include <iostream>

bool result_probability(float probability) {
    float r = ((double) rand() / (RAND_MAX));
    if (r <= probability) 
        return true;
    return false;
}
