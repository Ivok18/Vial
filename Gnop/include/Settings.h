#ifndef SETTINGS
#define SETTINGS
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

constexpr auto _outlineThickness = -5;

class Settings
{
protected:
	sf::RenderWindow _gameWindow;
	unsigned _widthOfGameWindow;
	unsigned _heighOfGameWindow;

	sf::RectangleShape _gameWindowBorders;

	sf::RectangleShape enemyTest;
	sf::IntRect enemyBox;

	sf::RectangleShape _battleAreaBorders;

	

protected:
	void inits();
		void initGameWindowBorders();
		void initBattleAreaBorders();
public:
	Settings();
	Settings(unsigned width, unsigned height, std::string title);
	~Settings() = default;

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

