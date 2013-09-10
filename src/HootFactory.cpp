#include "HootFactory.h"

#include "Component.h"

#include <Graphics/Text.hpp>
#include <Graphics/Sprite.hpp>

#include "VisibleComponent.h"
#include "PositionComponent.h"
#include "RandomMovementBehaviour.h"
#include "SimulatableEntity.h"
#include "ResourceManager.h"
#include "HootResource.h"

class SimulatableEntity* HootFactory::construct(ResourceManager &resman, sf::Vector2f initialPosition){
    
    sf::Sprite *owl = new sf::Sprite();
    
    int selection = std::rand() % 2;
    std::string name;
    if(selection == 0){
        owl->setTexture(*resman.getResource<HootTexture>("../res/owl.png"));
        owl->setScale(0.5, 0.5);
        name = "Hooty";
    }
    else{
        owl->setTexture(*resman.getResource<HootTexture>("../res/owl2.png"));
        owl->setScale(0.15, 0.15);
        name = "Hootle";
    }
    owl->setOrigin(owl->getLocalBounds().width/2, owl->getLocalBounds().height/2);

    sf::Text *sv = new sf::Text(name, *resman.getResource<HootFont>("../res/font/DroidSans.ttf"), 12);
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