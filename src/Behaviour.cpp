#include "Behaviour.h"

Behaviour::~Behaviour(){}

void Behaviour::attachParent(SimulatableEntity* parent){
    this->parent = parent;
}