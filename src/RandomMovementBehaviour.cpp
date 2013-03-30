#include "RandomMovementBehaviour.h"

#include "PositionMessage.h"
#include "SimulatableEntity.h"

RandomMovementBehaviour::RandomMovementBehaviour(){}

RandomMovementBehaviour::~RandomMovementBehaviour(){}

void RandomMovementBehaviour::behave(float elapsed){
    int direction = (rand() % 4) + 1;
    float distance = (rand() % 5) + 1;

    int newX = 0, newY = 0;
    if(direction == 1)
        newY = distance;
    if(direction == 2)
        newX = distance;
    if(direction == 3)
        newY = -(distance);
    if(direction == 4)
        newX = -(distance);
    
    distance *= elapsed;
    PositionMessage *pm = new PositionMessage(sf::Vector2f(newX, newY));
    this->parent->broadcast(pm);
}