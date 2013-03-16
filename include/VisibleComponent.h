#ifndef VISIBLE_COMPONENT_H_
#define VISIBLE_COMPONENT_H_

#include <Graphics/Drawable.hpp>

#include "Component.h"

class VisibleComponent: public Component {
public:
    VisibleComponent();
    virtual ~VisibleComponent();
    
    void addSprite(sf::Drawable* s);
    std::vector<sf::Drawable* >* getSprites();
    
    void receive(class Message* m);
    
private:
    std::vector<sf::Drawable*> sprites;
};
#endif