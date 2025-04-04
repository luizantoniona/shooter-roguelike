#pragma once

#include <SFML/Graphics.hpp>

#include <GUI/GUIGlobals.h>

#include <GUI/Component.h>

BEGIN_GUI_NAMESPACE

class Bar : public Component {
public:
    Bar( std::string componentName, float width, float height, sf::Color backgroundColor, sf::Color fillColor );

    void update( const sf::Time& deltaTime ) override;
    void render( sf::RenderWindow& window ) override;

    void setValue( float value );

protected:
    float _value;
    sf::RectangleShape _background;
    sf::RectangleShape _fill;
};

END_GUI_NAMESPACE