#include "Settings.h"


Settings::Settings() : _widthOfGameWindow(1200), _heighOfGameWindow(800)
{
	_gameWindow.create(sf::VideoMode(_widthOfGameWindow, _heighOfGameWindow), "");
	inits();
}
Settings::Settings(unsigned width, unsigned height, std::string title) :_widthOfGameWindow(width), _heighOfGameWindow(height) 
{
	_gameWindow.create(sf::VideoMode(_widthOfGameWindow, _heighOfGameWindow), title);
	inits();
}
sf::RenderWindow& Settings::getGameWindow()
{
	return _gameWindow;
}

float Settings::getWidthOfGameWindow()
{
	return _gameWindow.getSize().x;
}

void Settings::setWidthOfGameWindow(float newWidth)
{
	_widthOfGameWindow = newWidth;
}

float Settings::getHeightOfGameWindow()
{
	return _gameWindow.getSize().y;
}

void Settings::setHeightOfGameWindow(float newHeight)
{
	_heighOfGameWindow = newHeight;
}

sf::RectangleShape& Settings::getGameWindowBorders()
{
	return _gameWindowBorders;
}

void Settings::setGameWindowBorders(sf::RectangleShape newBorders)
{
	_gameWindowBorders = newBorders;
}

float Settings::getWidthOfGameWindowBorders()
{
	return _gameWindowBorders.getSize().x* _gameWindowBorders.getScale().x;
}

void Settings::setWidthOfGameWindowBorders(float width)
{
	_gameWindowBorders.setSize(sf::Vector2f(width, _gameWindowBorders.getSize().y));
}

float Settings::getHeightOfGameWindowBorders()
{
	return _gameWindowBorders.getSize().y* _gameWindowBorders.getScale().y;
}

void Settings::setHeightOfGameWindowBorders(float height)
{
	_gameWindowBorders.setSize(sf::Vector2f(_gameWindowBorders.getSize().x, height));
}

sf::RectangleShape& Settings::getBattleAreaBorders()
{
	return _battleAreaBorders;
}

void Settings::setBattleAreaBorders(sf::RectangleShape newBorders)
{
	_battleAreaBorders = newBorders;
}

float Settings::getWidthOfBattleAreaBorders()
{
	return _battleAreaBorders.getSize().x * _battleAreaBorders.getScale().x;
}

void Settings::setWidthOfBattleAreaBorders(float width)
{
	_battleAreaBorders.setSize(sf::Vector2f(width, _battleAreaBorders.getSize().y));
}

float Settings::getHeightOfBattleAreaBorders()
{
	return _battleAreaBorders.getSize().y * _battleAreaBorders.getScale().y;
}

void Settings::setHeightOfBattleAreaBorders(float height)
{
	_battleAreaBorders.setSize(sf::Vector2f(_battleAreaBorders.getSize().x, height));
}

void Settings::inits()
{
	initGameWindowBorders();
	initBattleAreaBorders();
}
	void Settings::initGameWindowBorders()
{
	_gameWindowBorders.setSize(sf::Vector2f(_widthOfGameWindow, _heighOfGameWindow));
	_gameWindowBorders.setPosition(0, 0);
	_gameWindowBorders.setFillColor(sf::Color::Transparent);
	_gameWindowBorders.setOutlineThickness(_outlineThickness);
	_gameWindowBorders.setOutlineColor(sf::Color::Black);
}
	void Settings::initBattleAreaBorders()
{
	float widthOfGameWindow = _widthOfGameWindow;
	float heightOfGameWindow = _heighOfGameWindow;

	_battleAreaBorders.setSize(sf::Vector2f(widthOfGameWindow * 0.8f, heightOfGameWindow * 0.8f));
	_battleAreaBorders.setPosition(widthOfGameWindow * 0.1f, heightOfGameWindow * 0.1f);
	_battleAreaBorders.setFillColor(sf::Color::Transparent);
	_battleAreaBorders.setOutlineThickness(_outlineThickness);
	_battleAreaBorders.setOutlineColor(sf::Color::Black);
}
