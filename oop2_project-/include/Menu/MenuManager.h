#pragma once

#include <memory>       // ���� std::unique_ptr, ����� ��� ����� ������ ��������
#include <SFML/Graphics.hpp> // ����� �� ������� ������� �� SFML

// Forward declaration ��� ����� include �����.
// ����� ������ ��������� "��� ������ ��� �����, ������ ����� ���� �����".
class IMenuScreenState;

class MenuManager {
private:
    // ����� ��� ������ �� ���� ������.
    // ������ �-unique_ptr ����� �������� �� ���� ������ �������� ���-MenuManager ����,
    // �� ��������� ���� ���.
    std::unique_ptr<IMenuScreenState> currentState;

    // ��� ���� ������ ������� ������� �������, ������:
    // sf::RenderWindow* windowRef; // ����� ����� ����� (�� ������ �����)
    // AssetManager* assetManagerRef; // ����� ����� ����� (������, �������� ���')

public:
    // ����������
    MenuManager();

    // ��������
    ~MenuManager();

    // �������� ������� ������ ����� ������
    void setState(std::unique_ptr<IMenuScreenState> newState);

    // �������� ������� ���� ����� ����� ������
    // �������� �� ������ ���� �����
    void handleInput(sf::Event& event, sf::RenderWindow& window);
    void update(sf::Time deltaTime); // ������� ������ ���������
    void render(sf::RenderWindow& window);

    // �������� ��� ����� ���� ������ (�� ����)
    IMenuScreenState* getCurrentState();
};