#pragma once

#include <string>

#include <SFML/Graphics.hpp>

#include <GUI/GUIGlobals.h>

BEGIN_GUI_NAMESPACE

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

END_GUI_NAMESPACE