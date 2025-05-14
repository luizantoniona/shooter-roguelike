#pragma once

#include <memory>

#include <jsoncpp/json/json.h>

#include <Factory/FactoryGlobals.h>

#include <Renderables/Shapes/Shape.h>

BEGIN_FACTORY_NAMESPACE

class ShapeFactory {
public:
    static std::unique_ptr<Shapes::Shape> createCharacterShape( Json::Value& shapeJson );
    static std::unique_ptr<Shapes::Shape> createBulletShape( const float bulletSize );
};

END_FACTORY_NAMESPACE
