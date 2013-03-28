#ifndef HOOT_FACTORY_H_
#define HOOT_FACTORY_H_

#include <Graphics/Texture.hpp>

#include "ResourceManager.h"

class HootFactory{
public:
    static class SimulatableEntity* construct(ResourceManager &resman, sf::Vector2f initialPosition);
};
#endif