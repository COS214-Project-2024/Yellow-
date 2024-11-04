#ifndef EXPANDCITY_H
#define EXPANDCITY_H

#include "Strategy.h"

class ExpandCity : public Strategy {

    public:
        Policies* implementPolicy(string stateType, string prevStateColour, string currStateColour) override;

};

#endif
