#pragma once

#include <memory>       // עבור std::unique_ptr, מצביע חכם שמנהל זיכרון אוטומטית
#include <SFML/Graphics.hpp> // נכלול את הכותרות הראשיות של SFML

// Forward declaration כדי למנוע include מעגלי.
// אנחנו אומרים לקומפיילר "תדע שמחלקה כזו קיימת, ההגדרה המלאה תגיע בהמשך".
class IMenuScreenState;

class MenuManager {
private:
    // מצביע חכם שמחזיק את המצב הנוכחי.
    // השימוש ב-unique_ptr מבטיח שהזיכרון של המצב ישוחרר אוטומטית כשה-MenuManager נהרס,
    // או כשמחליפים למצב חדש.
    std::unique_ptr<IMenuScreenState> currentState;

    // כאן אפשר להוסיף מצביעים למשאבים משותפים, לדוגמה:
    // sf::RenderWindow* windowRef; // מצביע לחלון הראשי (לא בבעלות המנהל)
    // AssetManager* assetManagerRef; // מצביע למנהל נכסים (פונטים, טקסטורות וכו')

public:
    // קונסטרקטור
    MenuManager();

    // דסטרקטור
    ~MenuManager();

    // הפונקציה המרכזית להחלפת מצבים בתפריט
    void setState(std::unique_ptr<IMenuScreenState> newState);

    // פונקציות שיופעלו מתוך לולאת המשחק הראשית
    // ומעבירות את העבודה למצב הפעיל
    void handleInput(sf::Event& event, sf::RenderWindow& window);
    void update(sf::Time deltaTime); // לעדכוני לוגיקה ואנימציות
    void render(sf::RenderWindow& window);

    // פונקציית עזר לקבלת המצב הנוכחי (אם צריך)
    IMenuScreenState* getCurrentState();
};