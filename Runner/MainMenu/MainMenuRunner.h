#pragma once

#include <SFML/Graphics.hpp>

#include <Runner/RunnerGlobals.h>

#include <Renderables/Components/Background/Background.h>
#include <Renderables/Components/Button/Button.h>
#include <Renderables/Components/Label/Label.h>
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
    Components::Background _background;
    Components::Label _labelTitle;
    std::vector<Components::Button> _buttons;

    Runners::RunnerType _selectedOption;
};

END_RUNNER_NAMESPACE