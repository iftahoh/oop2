#include <Menu/MainMenuScreenState.h>
#include <Menu/MenuManager.h>
#include <iostream>
#include <stdexcept>

//------------------------------------------------------------------
// ��� �� ������ �-sf::Vector2f
void MainMenuScreenState::setupText(sf::Text& text, const std::wstring& str, const sf::Vector2f& position, unsigned int size, const sf::Color& color) {
	text.setFont(font);
	text.setString(str);
	text.setCharacterSize(size);
	text.setFillColor(color);
	text.setPosition(position);
}

//------------------------------------------------------------------
MainMenuScreenState::MainMenuScreenState() : menuManagerRef(nullptr) {
	// ����� ������: �� ����� ������ �� ���� ����� �� ����.
	// �-try-catch ���� ����� ���� �����, ���� ����� �� ��������.
	if (!font.loadFromFile("assets/fonts/arial.ttf")) {
		// ����� �� ����� �-git ��������
		throw std::runtime_error("MainMenuScreenState Error: Failed to load font from assets/fonts/arial.ttf");
	}

	if (!backgroundTexture.loadFromFile("assets/images/background.png")) {
		// ���� ����� ����� �� ���� �����, �� �� ������ ����� �� ��� ���������.
		std::cerr << "MainMenuScreenState Warning: Failed to load background texture. Continuing without it." << std::endl;
	}
	else {
		// ��� ��: ����� �-backgroundSprite (����� ��� ����� ���� �-h)
		backgroundSprite.setTexture(backgroundTexture);
	}

	// ������ �� ������ ��� ��� ������ ������� ������
	setupText(titleText, L"Main Menu", { 0, 0 }, 48, sf::Color::White); // ����� ������ ����
	sf::FloatRect titleBounds = titleText.getLocalBounds();
	// ��� �� ������ �-titleBounds
	titleText.setOrigin(titleBounds.left + titleBounds.width / 2.f, titleBounds.top + titleBounds.height / 2.f);
	titleText.setPosition(400.f, 100.f); // ����� ������ ����� ���� ����� �-origin

	// ... button setup ...
}