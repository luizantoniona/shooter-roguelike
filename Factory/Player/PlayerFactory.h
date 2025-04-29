#pragma once

#include <memory>

#include <Factory/FactoryGlobals.h>

#include <Renderables/Entities/Character/Character.h>
#include <Renderables/Entities/Map/Map.h>

BEGIN_FACTORY_NAMESPACE

class PlayerFactory {
public:
    static std::unique_ptr<Entities::Character> createPlayer( const Entities::Map& map );
};

END_FACTORY_NAMESPACE
