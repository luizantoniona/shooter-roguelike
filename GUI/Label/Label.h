#pragma once

#include <string>

#include <SFML/Graphics.hpp>

#include <GUI/Component.h>

BEGIN_GUI_NAMESPACE

class Label : public Component {
public:
    enum class Alignment {
        Left,
        Center,
        Right,
    };

    Label();

    void setText( const std::string& text );
    void setFont( const sf::Font& font );
    void setCharacterSize( unsigned int size );
    void setPosition( float x, float y );
    void setColor( sf::Color color );
    void setOutline( sf::Color color, float thickness );
    void setAlignment( Alignment alignment, float containerWidth );
    void setStyle( sf::Uint32 style );
    void setFade( float alpha );

    void update( const sf::Time& deltaTime ) override;
    void render( sf::RenderWindow& window ) override;

private:
    sf::Text _text;
};

END_GUI_NAMESPACE