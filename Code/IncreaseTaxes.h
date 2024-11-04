#ifndef INCREASETAXES_H
#define INCREASETAXES_H

#include "Strategy.h"

class IncreaseTaxes : public Strategy {

    public:
        Policies* implementPolicy(string stateType, string prevStateColour, string currStateColour) override;

};

#endif
