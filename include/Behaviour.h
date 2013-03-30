#ifndef BEHAVIOUR_H_
#define BEHAVIOUR_H_

#include <System/Time.hpp>

class Behaviour {
public:
    virtual ~Behaviour();
    
    virtual void behave(float elapsed) = 0;
    virtual void attachParent(class SimulatableEntity* parent);
    
protected:
    class SimulatableEntity *parent;
};
#endif