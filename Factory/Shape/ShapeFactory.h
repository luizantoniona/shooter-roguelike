#pragma once

#include <memory>

#include <Factory/FactoryGlobals.h>

#include <Renderables/Shapes/Shape.h>
#include <Renderables/Shapes/ShapeType.h>

BEGIN_FACTORY_NAMESPACE

class ShapeFactory {
public:
    static std::unique_ptr<Shapes::Shape> createShape( const Shapes::ShapeType& shapeType );
};

END_FACTORY_NAMESPACE
