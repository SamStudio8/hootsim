#include "Stage.h"

#include "SimulatableEntity.h"

Stage::Stage(){}

Stage::~Stage(){
    this->clear();
}

void Stage::tick(){
    for(long index=0; index<(long)this->entities.size(); ++index){
        this->entities.at(index)->tick();
    }
}

void Stage::addSimulatableEntity(SimulatableEntity* entity){
    this->entities.push_back(entity);
}

void Stage::draw(sf::RenderWindow* window){
    for(int entityIndex=0; entityIndex < this->entities.size(); entityIndex++){
        std::vector<sf::Drawable*> *drawables = this->entities.at(entityIndex)->render();
        for(int drawableIndex=0; drawableIndex < drawables->size(); drawableIndex++){
            window->draw(*drawables->at(drawableIndex));
        }
    }
}

int Stage::size(){
    return this->entities.size();
}

void Stage::clear(){
    for(int index=0; index < this->entities.size(); index++){
        delete(this->entities.at(index));
    }
    this->entities.clear();
}