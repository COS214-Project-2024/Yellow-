#include "RandomUtil.h"

int RandomUtil::randomVal(int min, int max) {
    srand(time(NULL));

    int r = min + (rand()) * (max - min) / RAND_MAX;
    return r;
}
