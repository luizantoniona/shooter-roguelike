#pragma once

#include <SFML/Graphics.hpp>

#include <GUI/GUIGlobals.h>

BEGIN_GUI_NAMESPACE

class Button {
public:
    Button( const sf::String& text, const sf::Font& font, unsigned int characterSize, sf::Color color = sf::Color::White, sf::Color fillColor = sf::Color::Transparent );

    void setPosition( float x, float y );
    void setFillColor( const sf::Color& textColor, const sf::Color& rectangleColor = sf::Color::Transparent );
    void setText( const sf::String& text );

    bool isMouseOver( const sf::Vector2f& mousePos ) const;
    void render( sf::RenderWindow& window ) const;

private:
    sf::Text _text;
    sf::RectangleShape _shape;
};

END_GUI_NAMESPACE