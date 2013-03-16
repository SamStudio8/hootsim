#ifndef COMPONENT_H_
#define COMPONENT_H_

class Component{
public:
    virtual ~Component();
    
    virtual void receive(class Message*) = 0;
    virtual void attachParent(class SimulatableEntity* parent);
    
protected:
    class SimulatableEntity *parent;
};
#endif