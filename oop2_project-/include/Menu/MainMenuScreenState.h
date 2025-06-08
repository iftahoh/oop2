#pragma once

#include <Menu/MenuScreenState.h>
#include <Menu/Button.h>

class MainMenuScreenState : public MenuScreenState {
public:
	MainMenuScreenState();
	
	void render(sf::RenderWindow& window) override;
	void handelInput(sf::Event& event, sf::RenderWindow& window) override;
	void onEnter(MenuManager* manager) override;
	void onExit() override;
private:
	sf::Font font;
	sf::Text titleText;
	sf::Texture backgroundTexture;
	sf::Sprite background;

	Button startGameButton;
	Button settingsButton;
	Button infoButton;
	Button exitGameButton;

	void setupText(sf::Text& text, const std::wstring& str, const sf::Vector2f& position, unsigned int size, const sf::Color& color);
}