#pragma once

#include <SFML/Graphics.hpp>

#include <GUI/GUIGlobals.h>

#include <GUI/Component.h>

BEGIN_GUI_NAMESPACE

class Bar : public Component {
public:
    Bar();

    void update( sf::Time& deltaTime ) override;
    void render( sf::RenderWindow& window ) override;
};

END_GUI_NAMESPACE