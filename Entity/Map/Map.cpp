#include "Map.h"

BEGIN_ENTITY_NAMESPACE

Map::Map() :
    _width( 0 ),
    _height( 0 ),
    _shape(),
    _background(),
    _waves() {
}

Map::~Map() {
}

int Map::getWidth() const {
    return _width;
}

void Map::setWidth( const int width ) {
    _width = width;
}

int Map::getHeight() const {
    return _height;
}

void Map::setHeight( const int height ) {
    _height = height;
}

std::string Map::getWorldName() const {
    return _worldName;
}

void Map::setWorldName( const std::string& worldName ) {
    _worldName = worldName;
}

std::string Map::getStageName() const {
    return _stageName;
}

void Map::setStageName( const std::string& stageName ) {
    _stageName = stageName;
}

Background Map::getBackground() {
    return _background;
}

void Map::setBackground( const Background& background ) {
    _background = background;
}

std::queue<Wave> Map::getWaves() {
    return _waves;
}

void Map::setWaves( const std::queue<Wave>& wave ) {
    _waves = wave;
}

void Map::addWaves( const Wave& wave ) {
    _waves.push( wave );
}

void Map::popWave() {
    _waves.pop();
}

void Map::build() {
    _shape.setSize( sf::Vector2f( _width, _height ) );
    _shape.setFillColor( sf::Color::Transparent );
    _shape.setOutlineColor( sf::Color::White );
    _shape.setOutlineThickness( 5.0f );
    _shape.setPosition( 0, 0 );
}

// void Map::update( const sf::Time& deltaTime ) {
//     // _background.update( deltaTime );
// }

// void Map::render( sf::RenderWindow& window ) {
//     window.draw( _shape );
// }

bool Map::isInsideBounds( const sf::Vector2f& position ) const {
    return position.x >= 0 && position.x <= _width && position.y >= 0 && position.y <= _height;
}

END_ENTITY_NAMESPACE