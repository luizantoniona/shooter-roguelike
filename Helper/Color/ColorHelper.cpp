#include "ColorHelper.h"

#include <map>

BEGIN_HELPER_NAMESPACE

sf::Color ColorHelper::colorFromString( std::string color ) {
    std::map<std::string, sf::Color> colorMap = {
        { "black", sf::Color::Black },
        { "white", sf::Color::White },
        { "red", sf::Color::Red },
        { "green", sf::Color::Green },
        { "blue", sf::Color::Blue },
        { "yellow", sf::Color::Yellow },
        { "magenta", sf::Color::Magenta },
        { "cyan", sf::Color::Cyan },
        { "transparent", sf::Color::Transparent },
    };

    return colorMap[ color ];
}

END_HELPER_NAMESPACE