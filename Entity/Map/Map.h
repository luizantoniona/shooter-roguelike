#pragma once

#include <vector>

#include <SFML/Graphics.hpp>

#include <Entity/EntityGlobals.h>

BEGIN_ENTITY_NAMESPACE

class Map {
public:
    Map( int width, int height );
    ~Map();

    void update( sf::Time& deltaTime );
    void render( sf::RenderWindow& window );

    bool isInsideBounds( const sf::Vector2f& position ) const;

    int getWidth() const;
    int getHeight() const;

private:
    int _width;
    int _height;
    sf::RectangleShape _border;
    std::vector<sf::CircleShape> _stars;

    void initializeStars();
    void updateStars( sf::Time& deltaTime );
};

END_ENTITY_NAMESPACE