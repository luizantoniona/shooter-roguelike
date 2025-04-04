#pragma once

#include <SFML/Graphics.hpp>

#include <Runner/RunnerGlobals.h>

#include <GUI/Button/Button.h>
#include <Runner/Runner.h>

using GUI::Button;

BEGIN_RUNNER_NAMESPACE

class MainMenuRunner : public Runner {
public:
    MainMenuRunner();
    ~MainMenuRunner();

    void handleInput( const sf::Event& event, const sf::Time& deltaTime ) override;
    void update( sf::RenderWindow& window, const sf::Time& deltaTime ) override;
    void render( sf::RenderWindow& window ) override;

private:
    void initMenu();
    bool isMouseOverOption( const sf::Text& option, const sf::Vector2f& mousePos );

    Runners::RunnerType _selectedOption;
    sf::Font _font;
    sf::Text _title;
    std::vector<Button> _buttons;
};

END_RUNNER_NAMESPACE