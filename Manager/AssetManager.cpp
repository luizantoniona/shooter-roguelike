#include "AssetManager.h"

#include <string>

#include <jsoncpp/json/json.h>

using namespace Json;

BEGIN_MANAGER_NAMESPACE

AssetManager& AssetManager::instance() {
    static AssetManager instance;
    return instance;
}

const sf::Font& AssetManager::font( FontType fontType ) {
    auto& fonts = instance()._fonts;

    auto it = fonts.find( fontType );
    if ( it != fonts.end() ) {
        return it->second;
    }

    sf::Font font;
    if ( !font.loadFromFile( fontPath( fontType ) ) ) {
        throw std::runtime_error( "Failed to load font" );
    }

    fonts[ fontType ] = std::move( font );
    return fonts[ fontType ];
}

std::string AssetManager::fontPath( FontType fontType ) {
    std::string fontPath = "";
    switch ( fontType ) {
    case FontType::Arial: {
        fontPath = "../Asset/Fonts/Arial.ttf";
        break;
    }
    default: {
        break;
    }
    }

    return fontPath;
}

END_MANAGER_NAMESPACE
