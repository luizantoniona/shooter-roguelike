#pragma once

#include <SFML/Graphics.hpp>

#include <Runner/RunnerGlobals.h>

#include <GUI/Background/Background.h>
#include <GUI/Button/Button.h>
#include <GUI/Label/Label.h>
#include <Runner/Runner.h>

BEGIN_RUNNER_NAMESPACE

class MainMenuRunner : public Runner {
public:
    MainMenuRunner();
    ~MainMenuRunner();

    void handleInput( sf::RenderWindow& window, const sf::Event& event, const sf::Time& deltaTime ) override;
    void update( sf::RenderWindow& window, const sf::Time& deltaTime ) override;
    void render( sf::RenderWindow& window ) override;

private:
    void initMenu();

    sf::Font _font;
    GUI::Background _background;
    GUI::Label _labelTitle;
    std::vector<GUI::Button> _buttons;

    Runners::RunnerType _selectedOption;
};

END_RUNNER_NAMESPACE