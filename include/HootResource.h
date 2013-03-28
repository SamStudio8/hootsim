#ifndef HOOT_RESOURCE_H_
#define HOOT_RESOURCE_H_

#include <Graphics/Texture.hpp>
#include <Graphics/Font.hpp>

class HootResource{
public:
    virtual ~HootResource(){};
};

class HootTexture: public HootResource, public sf::Texture {
public:
    virtual ~HootTexture(){};
};

class HootFont: public HootResource, public sf::Font {
public:
    virtual ~HootFont(){};
};
#endif