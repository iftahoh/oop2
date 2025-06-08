// main.cpp

#include <SFML/Graphics.hpp>
#include "Menu/MenuManager.h"
#include "Menu/MainMenuScreenState.h" // �� �� ��� ������ ���
#include <iostream>             // ���� std::cerr
#include <stdexcept>            // ���� std::runtime_error (�-std::exception)
#include <cstdlib>              // ���� EXIT_FAILURE

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Worms Game - Exception Handling");
    window.setFramerateLimit(60);

    MenuManager menuManager;

    try {
        // ����� ������ ���� �������.
        // �� ����� �� MainMenuScreenState ���� ����� (����, ���� ��� ������ ����), ��� ����� ���.
        menuManager.setState(std::make_unique<MainMenuScreenState>());
    }
    // ����� ������ �������� ���� ����
    catch (const std::runtime_error& e) {
        std::cerr << "Runtime Error during game initialization: " << e.what() << std::endl;
        // ��� ���� ����� ����� ����� ������ (����, �� ���� ���� ���� �� �� ���� GUI)
        // �� ����� ����� "��� �����" ����� �� �� ���.
        // ����� ��, ����� �� ������� �� ���� ����� ����� �� ����.
        // (����� �����, ���� ���� ����� ���� ����� ���� �����)
        return EXIT_FAILURE;
    }
    // ����� ������ ������ ���� �� std::exception (���� runtime_error �� �� ����� ����)
    catch (const std::exception& e) {
        std::cerr << "Standard Exception during game initialization: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    // ����� �� ����� ���� ��� ����� (���� ����� ������ ����, ���� ����� ����� ��������)
    catch (...) {
        std::cerr << "An unknown error occurred during game initialization." << std::endl;
        return EXIT_FAILURE;
    }


    // --- ����� ����� ������ ---
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            // ����: �� handleInput �� update ������ ����� ������,
            // ����� ����� ���� try-catch �� ��� ��� ����� ����� �� ������ ������.
            // menuManager.handleInput(event, window);
        }

        // ����� ������
        // menuManager.update(deltaTime);

        window.clear(sf::Color::Blue);
        menuManager.render(window); // �� ���, �� render ���� ����� �����.
        window.display();
    }

    return 0;
}
