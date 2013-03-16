#ifndef HOOT_FACTORY_H_
#define HOOT_FACTORY_H_

#include <Graphics/Texture.hpp>

class HootFactory{
public:
    static class SimulatableEntity* construct(sf::Vector2f initialPosition);
    static sf::Texture& getTexture(int selection);
};
#endif