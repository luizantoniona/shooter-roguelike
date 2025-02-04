#pragma once

#include <string>

#include <SFML/Graphics/Color.hpp>

#include <Helper/HelperGlobals.h>

BEGIN_HELPER_NAMESPACE

class ColorHelper {
public:
    static sf::Color colorFromString( std::string color );
};

END_HELPER_NAMESPACE