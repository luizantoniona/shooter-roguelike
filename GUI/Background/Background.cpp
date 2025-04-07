#include "Background.h"
#include "BackgroundShape.h"

#include <cstdlib>

BEGIN_GUI_NAMESPACE

Background::Background() {
    generateShapes( 200 );
}

void Background::generateShapes( std::size_t count ) {
    sf::Vector2u screenSize = { sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height };

    for ( std::size_t i = 0; i < count; ++i ) {
        auto shape = std::make_unique<BackgroundShape>();

        // Tipo aleatório
        BackgroundShape::Type type = static_cast<BackgroundShape::Type>( rand() % 3 );
        shape->setType( type );

        // Posição aleatória
        float x = static_cast<float>( rand() % screenSize.x );
        float y = static_cast<float>( rand() % screenSize.y );
        shape->setPosition( { x, y } );

        // Cor aleatória com alpha semi-transparente
        sf::Color color(
            static_cast<sf::Uint8>( 100 + rand() % 155 ),
            static_cast<sf::Uint8>( 100 + rand() % 155 ),
            static_cast<sf::Uint8>( 100 + rand() % 155 ),
            static_cast<sf::Uint8>( 80 + rand() % 100 ) );
        shape->setColor( color );

        // Velocidade de movimento aleatória
        float speed = 5.f + static_cast<float>( rand() % 30 ); // entre 5 e 35
        shape->setSpeed( speed );

        // Velocidade de rotação aleatória
        float rotation = static_cast<float>( ( rand() % 40 ) - 20 ); // entre -20 e +20
        shape->setRotationSpeed( rotation );

        _shapes.emplace_back( std::move( shape ) );
    }
}

void Background::update( const sf::Time& deltaTime ) {

    float windowHeight = sf::VideoMode::getDesktopMode().height;

    for ( auto& shape : _shapes ) {
        shape->update( deltaTime, windowHeight );
    }
}

void Background::render( sf::RenderWindow& window ) {
    for ( auto& shape : _shapes ) {
        shape->render( window );
    }
}

END_GUI_NAMESPACE