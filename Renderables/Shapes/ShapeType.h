#pragma once

#include <Renderables/Shapes/ShapesGlobals.h>

BEGIN_SHAPES_NAMESPACE

enum class ShapeType {
    Circle,
    Rectangle,
    Regular
};

std::unique_ptr<Shape> createShape( ShapeType type );

END_SHAPES_NAMESPACE
