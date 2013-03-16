#include "PositionComponent.h"

#include "SimulatableEntity.h"
#include "MoveMessage.h"
#include "PositionMessage.h"

PositionComponent::PositionComponent(){
    this->position.x = 0;
    this->position.y = 0;
}

PositionComponent::~PositionComponent(){}

void PositionComponent::setPosition(sf::Vector2f newPosition){
    sf::Vector2f deltaPosition;
    deltaPosition.x = newPosition.x - this->position.x;
    deltaPosition.y = newPosition.y - this->position.y;
    
    this->position.x = newPosition.x;
    this->position.y = newPosition.y;
    
    MoveMessage *mm = new MoveMessage(this->position,
                                      deltaPosition);
    this->parent->broadcast(mm);
}

void PositionComponent::movePosition(sf::Vector2f deltaPosition){
    this->position.x += deltaPosition.x;
    this->position.y += deltaPosition.y;

    MoveMessage *mm = new MoveMessage(this->position,
                                      deltaPosition);
    this->parent->broadcast(mm);
}

void PositionComponent::receive(Message* m){
    if(m->getMessageType().compare(POSITION_MESSAGE) == 0){
        PositionMessage *pm = dynamic_cast<PositionMessage*>(m);
        this->movePosition(pm->getDeltaPosition());
    }   
}