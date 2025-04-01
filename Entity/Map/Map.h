#pragma once

#include <queue>

#include <SFML/Graphics.hpp>

#include <Entity/EntityGlobals.h>

#include <Map/Background/Background.h>
#include <Map/Wave/Wave.h>
#include <string>

BEGIN_ENTITY_NAMESPACE

class Map {
public:
    Map();
    ~Map();

    int getWidth() const;
    void setWidth( const int width );

    int getHeight() const;
    void setHeight( const int height );

    std::string getWorldName() const;
    void setWorldName( const std::string& worldName );

    std::string getStageName() const;
    void setStageName( const std::string& stageName );

    Background getBackground();
    void setBackground( const Background& background );

    std::queue<Wave> getWaves();
    void setWaves( const std::queue<Wave>& wave );
    void addWaves( const Wave& wave );
    void popWave();

    void build();

    bool isInsideBounds( const sf::Vector2f& position ) const;

private:
    int _width;
    int _height;
    std::string _worldName;
    std::string _stageName;
    std::queue<Wave> _waves;
    sf::RectangleShape _shape;
    Background _background;
};

END_ENTITY_NAMESPACE