/**
* @class RandomUtil
* @brief A  class that implements a random function
*
* The RandomUtil class is a utility class that is used to generate random numbers.
*/
#include "RandomUtil.h"

int RandomUtil::randomVal(int min, int max) {
    srand(time(NULL));

    int r = min + (rand()) * (max - min) / RAND_MAX;
    return r;
}
