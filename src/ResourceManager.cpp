#include "ResourceManager.h"

ResourceManager::ResourceManager(){}

ResourceManager::~ResourceManager(){
    for(auto iter = resources.begin(); iter != resources.end(); ++iter){
        delete(iter->second);
    }
    resources.erase(resources.begin(), resources.end());
}