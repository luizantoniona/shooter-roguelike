#pragma once

#include <SFML/Graphics.hpp>

#include <GUI/GUIGlobals.h>

BEGIN_GUI_NAMESPACE

class Component {
public:
    virtual ~Component() = default;

    virtual void update( sf::Time& deltaTime ) = 0;
    virtual void render( sf::RenderWindow& window ) = 0;

protected:
    sf::Vector2f _position;
};

END_GUI_NAMESPACE