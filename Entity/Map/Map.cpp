#include "Map.h"

BEGIN_ENTITY_NAMESPACE

Map::Map( int width, int height ) :
    _width( width ),
    _height( height ) {

    _border.setSize( sf::Vector2f( _width, _height ) );
    _border.setFillColor( sf::Color::Transparent );
    _border.setOutlineColor( sf::Color::White );
    _border.setOutlineThickness( 5.0f );
    _border.setPosition( 0, 0 );

    initializeStars();
    std::srand( static_cast<unsigned>( std::time( nullptr ) ) );
}

Map::~Map() {
}

void Map::initializeStars() {
    for ( int i = 0; i < 50; ++i ) {
        sf::CircleShape star( 2.0f );
        star.setFillColor( sf::Color::Yellow );
        star.setPosition( std::rand() % _width, std::rand() % _height );
        _stars.push_back( star );
    }
}

void Map::update( sf::Time& deltaTime ) {
    updateStars( deltaTime );
}

void Map::updateStars( sf::Time& deltaTime ) {
    for ( auto& star : _stars ) {
        sf::Vector2f offset( ( std::rand() % 3 - 1 ) * 10 * deltaTime.asSeconds(),
                             ( std::rand() % 3 - 1 ) * 10 * deltaTime.asSeconds() );
        sf::Vector2f newPosition = star.getPosition() + offset;

        if ( newPosition.x < 0 ) {
            newPosition.x = 0;
        }
        if ( newPosition.y < 0 ) {
            newPosition.y = 0;
        }
        if ( newPosition.x > _width ) {
            newPosition.x = _width;
        }
        if ( newPosition.y > _height ) {
            newPosition.y = _height;
        }

        star.setPosition( newPosition );
    }
}

void Map::render( sf::RenderWindow& window ) {
    window.draw( _border );
    for ( const auto& star : _stars ) {
        window.draw( star );
    }
}

bool Map::isInsideBounds( const sf::Vector2f& position ) const {
    return position.x >= 0 && position.x <= _width && position.y >= 0 && position.y <= _height;
}

int Map::getWidth() const {
    return _width;
}

int Map::getHeight() const {
    return _height;
}

END_ENTITY_NAMESPACE