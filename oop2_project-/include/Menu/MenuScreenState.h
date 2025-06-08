#pragma once

#include <SFML/Graphics.hpp>
class MenuManager;

class MenuScreenState {
public:
	MenuScreenState();
	virtual ~MenuScreenState() = default;

	virtual void render(sf::RenderWindow& window) = 0;
	virtual void handelInput(sf::Event& event, sf::RenderWindow& window) = 0;
	virtual void onEnter(MenuManager* manager) = 0;
	virtual void onExit() = 0;
}