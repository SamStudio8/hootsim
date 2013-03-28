#ifndef MOVE_MESSAGE_H_
#define MOVE_MESSAGE_H_

#include <string>
#include <System/Vector2.hpp>

#include "Message.h"

class MoveMessage: public Message {
public:
    MoveMessage(sf::Vector2f newPosition, sf::Vector2f deltaPosition);
    virtual ~MoveMessage();
    
    std::string getMessageType();
    sf::Vector2f getNewPosition();
    sf::Vector2f getDeltaPosition();
    
private:
    sf::Vector2f newPosition;
    sf::Vector2f deltaPosition;
};

#define MOVE_MESSAGE "MOVE"
#endif