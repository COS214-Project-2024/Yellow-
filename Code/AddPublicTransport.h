/**
 * @class AddPublicTransport
 * @brief  AddPublicTransport is a concrete strategy participant of the Strategy design pattern.
 * @ingroup Strategy
 * @implements Strategy
 * @see Strategy
 * 
 * AddPublicTransport is a concrete strategy participant of the Strategy design pattern. It is used to implement a policy that adds public transport to the city.
 * 
 */
#ifndef CODE_ADDPUBLICTRANSPORT_H
#define CODE_ADDPUBLICTRANSPORT_H

#include "Strategy.h"

class AddPublicTransport : public Strategy{
public:
    Policies* implementPolicy(string stateType, string prevStateColour, string currStateColour) override;


};


#endif //CODE_ADDPUBLICTRANSPORT_H
