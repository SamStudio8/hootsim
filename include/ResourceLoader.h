#ifndef RESOURCE_LOADER_H_
#define RESOURCE_LOADER_H_

#include <string>

#include "HootResource.h"

template<class T> class ResourceLoader{};

template<> class ResourceLoader<HootTexture>{
public:
    static HootTexture* load(const std::string& name){
        HootTexture *t = new HootTexture();
        if(t->loadFromFile(name)){
            return t;
        }
        else{
            return t;
            //TODO Error Handler
        }
    };
};

template<> class ResourceLoader<HootFont>{
public:
    static HootFont* load(const std::string& name){
        HootFont *f = new HootFont();
        if (f->loadFromFile(name)){
            return f;
        }
        else{
            return f;
            //TODO Error Handler
        }
    };
};
#endif