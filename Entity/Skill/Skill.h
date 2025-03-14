#pragma once

#include <SFML/Graphics.hpp>

#include <Entity/EntityGlobals.h>

#include <Entity/BaseEntity.h>

BEGIN_ENTITY_NAMESPACE

class Skill : public BaseEntity {
public:
    Skill();

    void update( const sf::RenderWindow& window, const sf::Time& deltaTime ) override;
    void render( sf::RenderWindow& window ) override;
};

END_ENTITY_NAMESPACE