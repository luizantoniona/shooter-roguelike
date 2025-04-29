#pragma once

#include "ComponentsGlobals.h"

#include <string>

#include <SFML/Graphics.hpp>

BEGIN_COMPONENTS_NAMESPACE

class Component {
public:
    Component( std::string componentName );
    virtual ~Component() = default;

    virtual void update( const sf::Time& deltaTime ) = 0;
    virtual void render( sf::RenderWindow& window ) = 0;

    std::string getComponentName() const;

private:
    std::string _componentName;
};

END_COMPONENTS_NAMESPACE
