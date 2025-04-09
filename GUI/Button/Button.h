#pragma once

#include <SFML/Graphics.hpp>

#include <GUI/GUIGlobals.h>

#include <GUI/Component.h>

BEGIN_GUI_NAMESPACE

class Button : public Component {
public:
    Button();

    void setText( const std::string& text );
    void setFont( const sf::Font& font );
    void setCharacterSize( unsigned int size );
    void setSize( float width, float height );
    void setPosition( float x, float y );
    void setColors( sf::Color textColor, sf::Color backgroundColor, sf::Color hoverColor );
    void setCallback( std::function<void()> callback );

    void update( const sf::Time& deltaTime ) override;
    void render( sf::RenderWindow& window ) override;
    void handleEvent( const sf::Event& event, const sf::Vector2f& mousePosition );

private:
    sf::RectangleShape _background;
    sf::Text _text;
    sf::Color _defaultColor;
    sf::Color _hoverColor;
    std::function<void()> _callback;
    bool _hovered;
};

END_GUI_NAMESPACE