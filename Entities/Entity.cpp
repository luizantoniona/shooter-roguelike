#include "Entity.h"

BEGIN_ENTITIES_NAMESPACE

Entity::Entity( const Entity& other ) {
    _shapes.reserve( other._shapes.size() );

    for ( const auto& shapes : other._shapes ) {
        if ( shapes ) {
            _shapes.emplace_back( shapes->clone() );
        }
    }
}

void Entity::render( sf::RenderWindow& window ) {
    for ( const auto& shape : _shapes ) {
        if ( shape ) {
            shape->render( window );
        }
    }
}

std::vector<std::unique_ptr<Shapes::Shape> >& Entity::getShapes() {
    return _shapes;
}

void Entity::setShapes( std::vector<std::unique_ptr<Shapes::Shape> > shapes ) {
    _shapes = std::move( shapes );
}

void Entity::clearShapes() {
    _shapes.clear();
}

Shapes::Shape& Entity::getShape( std::size_t index ) {
    return *_shapes[index];
}

void Entity::addShape( std::unique_ptr<Shapes::Shape> shape ) {
    _shapes.emplace_back( std::move( shape ) );
}

void Entity::removeShape( std::size_t index ) {
    if ( index < _shapes.size() ) {
        _shapes.erase( _shapes.begin() + static_cast<std::ptrdiff_t>( index ) );
    }
}

END_ENTITIES_NAMESPACE
