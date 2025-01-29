#pragma once

#include <map>

#include <jsoncpp/json/json.h>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include <Asset/AssetType.h>
#include <Manager/ManagerGlobals.h>

BEGIN_MANAGER_NAMESPACE

class AssetManager {
public:
    static AssetManager& instance();

    const sf::Font& font( FontType fontType );

private:
    AssetManager() = default;
    AssetManager( const AssetManager& ) = delete;
    AssetManager& operator=( const AssetManager& ) = delete;

    std::string fontPath( FontType fontType );

    std::map<FontType, sf::Font> _fonts;
};

END_MANAGER_NAMESPACE
