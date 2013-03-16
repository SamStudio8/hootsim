#include "HootFactory.h"

#include "Component.h"

#include <Graphics/Text.hpp>
#include <Graphics/Sprite.hpp>

#include "VisibleComponent.h"
#include "PositionComponent.h"
#include "RandomMovementBehaviour.h"
#include "SimulatableEntity.h"

class SimulatableEntity* HootFactory::construct(sf::Vector2f initialPosition){

    sf::Sprite *owl = new sf::Sprite();
    
    int selection = std::rand() % 2;
    std::string name;
    owl->setTexture(HootFactory::getTexture(selection));
    if(selection == 0){
        owl->setScale(0.5, 0.5);
        name = "Hooty";
    }
    else{
        owl->setScale(0.15, 0.15);
        name = "Hootle";
    }
    owl->setOrigin(owl->getLocalBounds().width/2, owl->getLocalBounds().height/2);

    sf::Text *sv = new sf::Text(name, sf::Font::getDefaultFont(), 12);
    sv->setOrigin(sv->getLocalBounds().width/2, sv->getLocalBounds().height/2);
    sv->setPosition(owl->getPosition().x, owl->getPosition().y + (owl->getGlobalBounds().height/2) + 5);
    
    VisibleComponent* v = new VisibleComponent();
    v->addSprite(owl);
    v->addSprite(sv);
    
    PositionComponent* p = new PositionComponent();
    RandomMovementBehaviour* b = new RandomMovementBehaviour();
    
    SimulatableEntity* se = new SimulatableEntity();
    se->attachComponent(v);
    se->attachComponent(p);
    se->attachBehaviour(b);
    
    p->setPosition(initialPosition);
    return se;
}

sf::Texture& HootFactory::getTexture(int selection){
    //TODO Release memory
    static sf::Texture s1_tex, s2_tex;
    static bool s1_loaded, s2_loaded = false;
    
    if(selection == 0){
        if(!s1_loaded){
            s1_tex.loadFromFile("../res/owl.png");
            s1_loaded = true;
        }
        return s1_tex;
    }
    else{
        if(!s2_loaded){
            s2_tex.loadFromFile("../res/owl2.png");
            s2_loaded = true;
        }
        return s2_tex;    
    }
}