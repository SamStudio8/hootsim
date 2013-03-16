#ifndef BEHAVIOUR_H_
#define BEHAVIOUR_H_

class Behaviour {
public:
    virtual ~Behaviour();
    
    virtual void behave() = 0;
    virtual void attachParent(class SimulatableEntity* parent);
    
protected:
    class SimulatableEntity *parent;
};
#endif