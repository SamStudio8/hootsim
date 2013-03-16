#include "PositionMessage.h"

PositionMessage::PositionMessage(sf::Vector2f deltaPosition){
    this->deltaPosition = deltaPosition;
}

PositionMessage::~PositionMessage(){}

std::string PositionMessage::getMessageType(){
    return "DPOS";
}

sf::Vector2f PositionMessage::getDeltaPosition(){
    return this->deltaPosition;
}