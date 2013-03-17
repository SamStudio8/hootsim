#include "VisibleComponent.h"

#include <Graphics/Font.hpp>
#include <Graphics/Text.hpp>

#include "MoveMessage.h"

VisibleComponent::VisibleComponent(){}

VisibleComponent::~VisibleComponent(){
    for(size_t i=0; i < this->sprites.size(); i++){
        delete(this->sprites.at(i));
    }
}

void VisibleComponent::addSprite(sf::Drawable* s){
    this->sprites.push_back(s);
}

std::vector<sf::Drawable*>* VisibleComponent::getSprites(){
    return &(this->sprites);
}

void VisibleComponent::receive(Message* m){
    if(m->getMessageType().compare(MOVE_MESSAGE) == 0){
        MoveMessage *mm = dynamic_cast<MoveMessage*>(m);
        
        std::vector<sf::Drawable*> *drawables = &(this->sprites);
        for (size_t index=0; index < drawables->size(); index++){
            //TODO(samn) Create some sort of sf::Transformable, sf::Drawable superclass
            (dynamic_cast<sf::Transformable*>(drawables->at(index)))->move(mm->getDeltaPosition());
        }
    }
}