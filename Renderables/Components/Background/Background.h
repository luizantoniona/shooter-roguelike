#pragma once

#include <memory>
#include <vector>

#include <SFML/Graphics.hpp>

#include <Renderables/Components/ComponentsGlobals.h>

#include <Renderables/Components/Background/BackgroundShape.h>

BEGIN_COMPONENTS_NAMESPACE

class Background {
public:
    Background();

    void update( const sf::Time& deltaTime );
    void render( sf::RenderWindow& window );

private:
    void generateShapes( std::size_t count );

    std::vector<std::unique_ptr<BackgroundShape>> _shapes;
};

END_COMPONENTS_NAMESPACE