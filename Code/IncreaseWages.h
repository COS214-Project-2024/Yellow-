#ifndef CODE_INCREASEWAGES_H
#define CODE_INCREASEWAGES_H

#include "Strategy.h"

class IncreaseWages : public Strategy {

    public:
        Policies* implementPolicy(string stateType, string prevStateColour, string currStateColour) override;

};


#endif //CODE_INCREASEWAGES_H
