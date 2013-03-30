#include "Stage.h"

#include "SimulatableEntity.h"

Stage::Stage(){}

Stage::~Stage(){
    this->clear();
}

void Stage::tick(float elapsed){
    for(size_t index=0; index< this->entities.size(); ++index){
        this->entities.at(index)->tick(elapsed);
    }
}

void Stage::addSimulatableEntity(SimulatableEntity* entity){
    this->entities.push_back(entity);
}

void Stage::draw(sf::RenderWindow* window){
    for(size_t entityIndex=0; entityIndex < this->entities.size(); entityIndex++){
        std::vector<sf::Drawable*> *drawables = this->entities.at(entityIndex)->render();
        for(size_t drawableIndex=0; drawableIndex < drawables->size(); drawableIndex++){
            window->draw(*drawables->at(drawableIndex));
        }
    }
}

int Stage::size(){
    return this->entities.size();
}

void Stage::clear(){
    for(size_t index=0; index < this->entities.size(); index++){
        delete(this->entities.at(index));
    }
    this->entities.clear();
}