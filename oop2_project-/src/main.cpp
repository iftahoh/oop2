// main.cpp

#include <SFML/Graphics.hpp>
#include "Menu/MenuManager.h"
#include "Menu/MainMenuScreenState.h" // או כל מצב התחלתי אחר
#include <iostream>             // עבור std::cerr
#include <stdexcept>            // עבור std::runtime_error (ו-std::exception)
#include <cstdlib>              // עבור EXIT_FAILURE

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Worms Game - Exception Handling");
    window.setFramerateLimit(60);

    MenuManager menuManager;

    try {
        // יצירת והגדרת המצב ההתחלתי.
        // אם הבנאי של MainMenuScreenState זורק חריגה (למשל, בגלל כשל בטעינת פונט), היא תיתפס כאן.
        menuManager.setState(std::make_unique<MainMenuScreenState>());
    }
    // תפיסת חריגות ספציפיות יותר קודם
    catch (const std::runtime_error& e) {
        std::cerr << "Runtime Error during game initialization: " << e.what() << std::endl;
        // כאן אפשר להציג הודעת שגיאה למשתמש (למשל, עם חלון קופץ פשוט אם זה משחק GUI)
        // או לנסות לטעון "מצב שגיאה" בסיסי אם יש כזה.
        // במקרה זה, נסיים את התוכנית כי משאב קריטי כנראה לא נטען.
        // (במשחק אמיתי, אולי תרצה להציג חלון הודעה לפני סגירה)
        return EXIT_FAILURE;
    }
    // תפיסת חריגות כלליות יותר של std::exception (כולל runtime_error אם לא נתפסה קודם)
    catch (const std::exception& e) {
        std::cerr << "Standard Exception during game initialization: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    // תפיסת כל חריגה אחרת שלא זוהתה (פחות מומלץ לשימוש נרחב, עדיף לתפוס סוגים ספציפיים)
    catch (...) {
        std::cerr << "An unknown error occurred during game initialization." << std::endl;
        return EXIT_FAILURE;
    }


    // --- לולאת המשחק הראשית ---
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            // חשוב: אם handleInput או update יכולים לזרוק חריגות,
            // ייתכן שתרצה בלוק try-catch גם כאן כדי למנוע קריסה של הלולאה הראשית.
            // menuManager.handleInput(event, window);
        }

        // עדכון לוגיקה
        // menuManager.update(deltaTime);

        window.clear(sf::Color::Blue);
        menuManager.render(window); // גם כאן, אם render יכול לזרוק חריגה.
        window.display();
    }

    return 0;
}
