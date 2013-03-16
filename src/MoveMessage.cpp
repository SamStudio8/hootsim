#include "MoveMessage.h"

MoveMessage::MoveMessage(sf::Vector2f newPosition, sf::Vector2f deltaPosition){
    this->newPosition = newPosition;
    this->deltaPosition = deltaPosition;
}

MoveMessage::~MoveMessage(){}

std::string MoveMessage::getMessageType(){
    return "MOVE";
}

sf::Vector2f MoveMessage::getNewPosition(){
    return this->newPosition;
}

sf::Vector2f MoveMessage::getDeltaPosition(){
    return this->deltaPosition;
}