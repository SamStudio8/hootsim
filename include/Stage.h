#ifndef STAGE_H_
#define STAGE_H_

#include <vector>

#include <Graphics/RenderWindow.hpp>

class Stage{
public:
    Stage();
    ~Stage();
    
    void tick(float elapsed);
    void addSimulatableEntity(class SimulatableEntity* entity);
    void draw(sf::RenderWindow* window);
    int size();
    void clear();
  
private:
    std::vector<class SimulatableEntity*> entities;
};
#endif