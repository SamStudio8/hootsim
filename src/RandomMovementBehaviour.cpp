#include "RandomMovementBehaviour.h"

#include "PositionMessage.h"
#include "SimulatableEntity.h"

RandomMovementBehaviour::RandomMovementBehaviour(){}

RandomMovementBehaviour::~RandomMovementBehaviour(){}

void RandomMovementBehaviour::behave(){
    int direction = (rand() % 4) + 1;
    int distance = rand() % 8;

    int newX = 0, newY = 0;
    if(direction == 1)
        newY = distance;
    if(direction == 2)
        newX = distance;
    if(direction == 3)
        newY = -(distance);
    if(direction == 4)
        newX = -(distance);
    
    PositionMessage *pm = new PositionMessage(sf::Vector2f(newX, newY));
    this->parent->broadcast(pm);
}