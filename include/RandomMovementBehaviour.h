#ifndef RANDOM_MOVEMENT_BEHAVIOUR_H_
#define RANDOM_MOVEMENT_BEHAVIOUR_H_

#include "Behaviour.h"

class RandomMovementBehaviour: public Behaviour {
public:
    RandomMovementBehaviour();
    ~RandomMovementBehaviour();    
    
    void behave(float elapsed);
};
#endif