#include "manager.hpp"
#include "helpers/functions.hpp"
#include "helpers/values.hpp"

#include <exception>
#include <iostream>

namespace Manager
{
    EntityID create(const std::string& png)
    {
        EntityID id = Component::maxIndexes;

        addComponent<Component::Base>(id, BE_NULL::FALSE);
        addComponent<Component::Type>(id, BE_NULL::FALSE);
        addComponent<Component::Animation>(id, BE_NULL::TRUE);
        addComponent<Component::UpdateFunction>(id, BE_NULL::TRUE);
        addComponent<Component::Movement>(id, BE_NULL::TRUE);
        addComponent<Component::Physics>(id, BE_NULL::TRUE);
        addComponent<Component::Global>(id, BE_NULL::TRUE);

        if(not Component::bases[id] ->texture.loadFromFile(png)) {
            throw std::runtime_error( std::string("Failed to load " + png ));
        }

        Component::bases[id] ->sprite.setTexture(Component::bases[id] ->texture);

        Component::maxIndexes++;

        #ifdef ENABLE_DEBUG_MODE
        std::cerr << "ID:" << id << " Created! - " << png << std::endl;
        #endif
        
        return id;
    }

    bool canAccess(EntityID id) noexcept
    {
        // Bases is a must for all of the components
        // if it doesn't have any value, the other 
        // components will not respond well.
        if(Component::bases[id].has_value()) {
            return true;
        }
        
        #ifdef ENABLE_DEBUG_MODE
        std::cerr << "ID:" << id << " Cannot be accessed! " << std::endl;
        #endif

        return false;
    }

    void remove(EntityID id) noexcept 
    {
        if(Manager::canAccess(id))
        {
            Component::bases.erase(id);
            Component::types.erase(id);
            Component::animations.erase(id);
            Component::movements.erase(id);
            Component::physics.erase(id);
            Component::updates.erase(id);

            #ifdef ENABLE_DEBUG_MODE
            std::cerr << "ID:" << id << "Removed!" << std::endl;
            #endif
        } 
        #ifdef ENABLE_DEBUG_MODE
        else {
            std::cerr << "ID:" << id << " Cannot be removed!" << std::endl;
        }   
        #endif

    }
} // namespace Manager