#pragma once

#include <queue>
#include <string>

#include <SFML/Graphics.hpp>

#include <Renderables/Entities/EntitiesGlobals.h>
#include <Renderables/Entities/Map/Wave/Wave.h>

BEGIN_ENTITIES_NAMESPACE

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

    sf::RectangleShape& getShape();

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
};

END_ENTITIES_NAMESPACE
