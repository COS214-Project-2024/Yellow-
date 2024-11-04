/**
 * @file Policies.h
 * @author Saskia Steyn
 * @brief A class used by the government to pass policies between patterns
 * @version 0.1
 * @date 2024-10-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "RandomUtil.h"

int RandomUtil::randomVal(int min, int max) {
    srand(time(NULL));

    int r = min + (rand()) * (max - min) / RAND_MAX;
    return r;
}
