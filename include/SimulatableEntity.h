#ifndef SIMULATABLE_ENTITY_H_
#define SIMULATABLE_ENTITY_H_

#include <vector>

#include <Graphics/Drawable.hpp>
#include <System/Time.hpp>

class SimulatableEntity {
public:
    SimulatableEntity();
    ~SimulatableEntity();
    
    void attachComponent(class Component* c);
    void attachBehaviour(class Behaviour* b);
    
    void broadcast(class Message* m);
    
    void tick(float elapsed);
    std::vector<sf::Drawable*>* render();
    
private:    
    std::vector<class Component*> components;
    std::vector<class Behaviour*> behaviours;
};
#endif