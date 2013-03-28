#ifndef RESOURCE_MANAGER_H_
#define RESOURCE_MANAGER_H_

#include <map>

#include "HootResource.h"
#include "ResourceLoader.h"

class ResourceManager{
public:
    ResourceManager();
    ~ResourceManager();
    
    template<class resourceT> 
    resourceT* getResource(const std::string& name) {
        auto it = resources.find(name);
        if(it != resources.end()){
            return static_cast<resourceT*>(it->second);
        }
        else{
            auto resource = ResourceLoader<resourceT>::load(name);
            this->resources[name] = resource;
            return resource;
        }
    }
protected:
    std::map<std::string, HootResource*> resources;
};
#endif