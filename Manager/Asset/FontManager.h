#pragma once

#include <map>

#include <jsoncpp/json/json.h>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include <Asset/FontType.h>
#include <Manager/ManagerGlobals.h>

BEGIN_MANAGER_NAMESPACE

class FontManager {
public:
    static FontManager& instance();

    const sf::Font& font( FontType fontType );

private:
    FontManager() = default;
    FontManager( const FontManager& ) = delete;
    FontManager& operator=( const FontManager& ) = delete;

    std::string fontPath( FontType fontType );

    std::map<FontType, sf::Font> _fonts;
};

END_MANAGER_NAMESPACE
