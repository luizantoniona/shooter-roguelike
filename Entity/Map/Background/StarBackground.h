#pragma once

#include <vector>

#include <SFML/Graphics.hpp>

#include <Entity/EntityGlobals.h>

#include <Map/Background/Background.h>

BEGIN_ENTITY_NAMESPACE

class StarBackground : public Background {
public:
    StarBackground();
    ~StarBackground();

    void update( sf::Time& deltaTime ) override;
    void render( sf::RenderWindow& window ) override;

    void setWidht( const int width );
    void setHeight( const int height );

private:
    int _width;
    int _height;
    std::vector<sf::CircleShape> _stars;

    void initializeStars();
    void updateStars( sf::Time& deltaTime );
};

END_ENTITY_NAMESPACE