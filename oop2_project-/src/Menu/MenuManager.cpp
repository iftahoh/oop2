#include "Menu/MenuManager.h"
#include "Menu/MenuScreenState.h" // אנחנו צריכים את ההגדרה המלאה כאן כדי לקרוא למתודות של המצב

MenuManager::MenuManager() {
    // קונסטרקטור ריק כרגע.
    // אם היו משאבים משותפים, היינו מאתחלים אותם כאן.
}

MenuManager::~MenuManager() {
    // דסטרקטור ריק.
    // unique_ptr ידאג לשחרר את הזיכרון של currentState באופן אוטומטי.
}

void MenuManager::setState(std::unique_ptr<IMenuScreenState> newState) {
    // 1. אם קיים מצב ישן, קרא לפונקציית היציאה שלו כדי שינקה את עצמו.
    if (currentState) {
        currentState->onExit();
    }

    // 2. העבר את הבעלות על המצב החדש למצביע החכם שלנו.
    //    std::move מעביר את הבעלות ביעילות מבלי להעתיק את האובייקט.
    currentState = std::move(newState);

    // 3. אם המצב החדש שהתקבל תקין, קרא לפונקציית הכניסה שלו כדי שיאתחל את עצמו.
    if (currentState) {
        currentState->onEnter(this); // 'this' הוא מצביע ל-MenuManager עצמו, כדי שהמצב יוכל לתקשר בחזרה
    }
}

void MenuManager::handleInput(sf::Event& event, sf::RenderWindow& window) {
    // בדוק אם יש מצב פעיל, ואם כן, העבר לו את הקלט לטיפול
    if (currentState) {
        currentState->handleInput(event, window);
    }
}

void MenuManager::update(sf::Time deltaTime) {
    // בדוק אם יש מצב פעיל, ואם כן, עדכן אותו
    if (currentState) {
        // נצטרך להוסיף את המתודה update לממשק IMenuScreenState אם נרצה להשתמש בזה
        // currentState->update(deltaTime);
    }
}

void MenuManager::render(sf::RenderWindow& window) {
    // בדוק אם יש מצב פעיל, ואם כן, קרא לו לצייר את עצמו על החלון
    if (currentState) {
        currentState->render(window);
    }
}

IMenuScreenState* MenuManager::getCurrentState() {
    return currentState.get(); // .get() מחזיר מצביע גולמי לאובייקט שבתוך ה-unique_ptr
}