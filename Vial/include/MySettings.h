#ifndef MYSETTINGS
#define MYSETTINGS
#include <SFML/Graphics.hpp>

constexpr auto _outlineThickness = -5;

class MySettings
{
protected:
	sf::RenderWindow _gameWindow;
	unsigned _widthOfGameWindow;
	unsigned _heighOfGameWindow;

	sf::RectangleShape _gameWindowBorders;
	sf::RectangleShape _battleAreaBorders;

protected:
	void initGameWindowBorders();
	void initBattleAreaBorders();

public:
	MySettings();
	MySettings(unsigned width, unsigned height, std::string title);
	~MySettings() = default;

	sf::RenderWindow& getGameWindow();

	float getWidthOfGameWindow();
	void setWidthOfGameWindow(float newWidth);

	float getHeightOfGameWindow();
	void setHeightOfGameWindow(float newHeight);

	sf::RectangleShape& getGameWindowBorders();
	void setGameWindowBorders(sf::RectangleShape newBorders);

	float getWidthOfGameWindowBorders();
	void setWidthOfGameWindowBorders(float width);

	float getHeightOfGameWindowBorders();
	void setHeightOfGameWindowBorders(float height);

	sf::RectangleShape& getBattleAreaBorders();
	void setBattleAreaBorders(sf::RectangleShape newBorders);

	float getWidthOfBattleAreaBorders();
	void setWidthOfBattleAreaBorders(float width);

	float getHeightOfBattleAreaBorders();
	void setHeightOfBattleAreaBorders(float height);
};

#endif


