#include "ShapeFactory.h"

#include <Helper/Color/ColorHelper.h>
#include <Renderables/Shapes/CircleShape.h>
#include <Renderables/Shapes/RegularShape.h>

BEGIN_FACTORY_NAMESPACE

std::unique_ptr<Shapes::Shape> ShapeFactory::createCharacterShape( Json::Value& shapeJson ) {

    int sides = shapeJson[ "sides" ].asInt();
    float size = shapeJson[ "size" ].asFloat();
    std::string colorStr = shapeJson[ "color" ].asString();

    std::unique_ptr<Shapes::RegularShape> shape = std::make_unique<Shapes::RegularShape>();

    shape->setSides( sides );
    shape->setSize( size );
    shape->setFillColor( Helper::ColorHelper::colorFromString( colorStr ) );
    shape->build();

    return std::unique_ptr<Shapes::Shape>( std::move( shape ) );
}

std::unique_ptr<Shapes::Shape> ShapeFactory::createBulletShape( const float bulletSize ) {

    std::unique_ptr<Shapes::CircleShape> shape = std::make_unique<Shapes::CircleShape>();

    shape->setRadius( bulletSize );
    shape->setFillColor( sf::Color::White );
    shape->build();

    return std::unique_ptr<Shapes::Shape>( std::move( shape ) );
}

END_FACTORY_NAMESPACE
