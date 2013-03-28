#ifndef POSITION_MESSAGE_H_
#define POSITION_MESSAGE_H_

#include <System/Vector2.hpp>

#include "Message.h"

class PositionMessage: public Message {
public:
    PositionMessage(sf::Vector2f deltaPosition);
    virtual ~PositionMessage();
    
    std::string getMessageType();
    sf::Vector2f getDeltaPosition();
    
private:
    sf::Vector2f deltaPosition;
};

#define POSITION_MESSAGE "DPOS"
#endif