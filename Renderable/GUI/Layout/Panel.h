#pragma once

#include <vector>

#include <SFML/Graphics.hpp>

#include <GUI/GUIGlobals.h>

#include <GUI/Component.h>

BEGIN_GUI_NAMESPACE

class Panel : public Component {
public:
    Panel();

    void setSize( float width, float height );
    void addComponent( Component* component, const sf::Vector2f& localPosition );
    void setPosition( float x, float y );
    void setBackgroundColor( sf::Color color );

    void update( const sf::Time& deltaTime ) override;
    void render( sf::RenderWindow& window ) override;

private:
    sf::RectangleShape _background;
    sf::Vector2f _position;
    std::vector<std::pair<Component*, sf::Vector2f>> _components;
};

END_GUI_NAMESPACE