#include "Menu/MenuManager.h"
#include "Menu/MenuScreenState.h" // ����� ������ �� ������ ����� ��� ��� ����� ������� �� ����

MenuManager::MenuManager() {
    // ���������� ��� ����.
    // �� ��� ������ �������, ����� ������� ���� ���.
}

MenuManager::~MenuManager() {
    // �������� ���.
    // unique_ptr ���� ����� �� ������� �� currentState ����� �������.
}

void MenuManager::setState(std::unique_ptr<IMenuScreenState> newState) {
    // 1. �� ���� ��� ���, ��� ��������� ������ ��� ��� ����� �� ����.
    if (currentState) {
        currentState->onExit();
    }

    // 2. ���� �� ������ �� ���� ���� ������ ���� ����.
    //    std::move ����� �� ������ ������� ���� ������ �� ��������.
    currentState = std::move(newState);

    // 3. �� ���� ���� ������ ����, ��� ��������� ������ ��� ��� ������ �� ����.
    if (currentState) {
        currentState->onEnter(this); // 'this' ��� ����� �-MenuManager ����, ��� ����� ���� ����� �����
    }
}

void MenuManager::handleInput(sf::Event& event, sf::RenderWindow& window) {
    // ���� �� �� ��� ����, ��� ��, ���� �� �� ���� ������
    if (currentState) {
        currentState->handleInput(event, window);
    }
}

void MenuManager::update(sf::Time deltaTime) {
    // ���� �� �� ��� ����, ��� ��, ���� ����
    if (currentState) {
        // ����� ������ �� ������ update ����� IMenuScreenState �� ���� ������ ���
        // currentState->update(deltaTime);
    }
}

void MenuManager::render(sf::RenderWindow& window) {
    // ���� �� �� ��� ����, ��� ��, ��� �� ����� �� ���� �� �����
    if (currentState) {
        currentState->render(window);
    }
}

IMenuScreenState* MenuManager::getCurrentState() {
    return currentState.get(); // .get() ����� ����� ����� �������� ����� �-unique_ptr
}