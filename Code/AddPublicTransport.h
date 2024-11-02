#ifndef CODE_ADDPUBLICTRANSPORT_H
#define CODE_ADDPUBLICTRANSPORT_H

#include "Strategy.h"

class AddPublicTransport : public Strategy{
public:
    Policies* implementPolicy(string stateType, string prevStateColour, string currStateColour) override;


};


#endif //CODE_ADDPUBLICTRANSPORT_H
