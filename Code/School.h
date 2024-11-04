/**
 * @file School.h
 * @author Amadeus Fidos
 * @brief 
 * @version 0.1
 * @date 2024-10-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef SCHOOL_H
#define SCHOOL_H
class Service;
class School : public Service {
    public:
        School();
        Cell* clone();
};

#endif