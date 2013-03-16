#include "Component.h"

Component::~Component(){}

void Component::attachParent(SimulatableEntity* parent){
    this->parent = parent;
}
