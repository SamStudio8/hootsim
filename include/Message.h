#ifndef MESSAGE_H_
#define MESSAGE_H_

#include <string>

class Message{
public:
    virtual ~Message();
    virtual std::string getMessageType() = 0;    
};
#endif