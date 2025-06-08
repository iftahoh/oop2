#include <Menu/MainMenuScreenState.h>
#include <Menu/MenuManager.h>
#include <iostream>
#include <stdexcept>

//------------------------------------------------------------------
// שים לב לתיקון ל-sf::Vector2f
void MainMenuScreenState::setupText(sf::Text& text, const std::wstring& str, const sf::Vector2f& position, unsigned int size, const sf::Color& color) {
	text.setFont(font);
	text.setString(str);
	text.setCharacterSize(size);
	text.setFillColor(color);
	text.setPosition(position);
}

//------------------------------------------------------------------
MainMenuScreenState::MainMenuScreenState() : menuManagerRef(nullptr) {
	// הגישה הנכונה: תן לבנאי להיכשל אם משאב קריטי לא נטען.
	// ה-try-catch צריך להיות מחוץ לבנאי, בקוד שיוצר את האובייקט.
	if (!font.loadFromFile("assets/fonts/arial.ttf")) {
		// הסרנו את שורות ה-git המיותרות
		throw std::runtime_error("MainMenuScreenState Error: Failed to load font from assets/fonts/arial.ttf");
	}

	if (!backgroundTexture.loadFromFile("assets/images/background.png")) {
		// אפשר לזרוק שגיאה אם הרקע קריטי, או רק להדפיס אזהרה אם הוא אופציונלי.
		std::cerr << "MainMenuScreenState Warning: Failed to load background texture. Continuing without it." << std::endl;
	}
	else {
		// שים לב: שימוש ב-backgroundSprite (בהנחה שכך הגדרת אותו ב-h)
		backgroundSprite.setTexture(backgroundTexture);
	}

	// שיניתי את המיקום כאן כדי להתאים ללוגיקת המרכוז
	setupText(titleText, L"Main Menu", { 0, 0 }, 48, sf::Color::White); // מיקום התחלתי זמני
	sf::FloatRect titleBounds = titleText.getLocalBounds();
	// שים לב לתיקון ב-titleBounds
	titleText.setOrigin(titleBounds.left + titleBounds.width / 2.f, titleBounds.top + titleBounds.height / 2.f);
	titleText.setPosition(400.f, 100.f); // קביעת המיקום הסופי אחרי שינוי ה-origin

	// ... button setup ...
}