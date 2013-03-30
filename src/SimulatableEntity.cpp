#include "SimulatableEntity.h"

#include "VisibleComponent.h"
#include "Behaviour.h"
#include "Message.h"

SimulatableEntity::SimulatableEntity(){}

SimulatableEntity::~SimulatableEntity(){
    for(size_t i=0; i < this->components.size(); i++){
        delete(this->components.at(i));
    }
    this->components.clear();
    
    for(size_t j=0; j < this->behaviours.size(); j++){
        delete(this->behaviours.at(j));
    }
    this->behaviours.clear();
}

void SimulatableEntity::tick(float elapsed){
    for(size_t i=0; i < this->behaviours.size(); i++){
        this->behaviours.at(i)->behave(elapsed);
    }
}

std::vector< sf::Drawable* >* SimulatableEntity::render(){
    //TODO Check for VisibleComponents
    return dynamic_cast<VisibleComponent*>(this->components.at(0))->getSprites();
}

void SimulatableEntity::attachComponent(Component* c){
    c->attachParent(this);
    this->components.push_back(c);
    //TODO Broadcast
}

void SimulatableEntity::attachBehaviour(Behaviour* b){
    b->attachParent(this);
    this->behaviours.push_back(b);
    //TODO Broadcast
}

void SimulatableEntity::broadcast(Message* m){
    for(size_t i=0; i < this->components.size(); i++){
        this->components.at(i)->receive(m);
    }
    delete(m);
}