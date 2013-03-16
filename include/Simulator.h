#ifndef SIMULATOR_H_
#define SIMULATOR_H_

#include <Graphics/RenderWindow.hpp>

#include "Stage.h"

class Simulator {
public:
    Simulator();
    ~Simulator();
    
    void screenshot();
    void sim();
    
private:
    sf::RenderWindow window;
    Stage stage;
    
    long ticktime;
    int height;
    int width;
};
#endif