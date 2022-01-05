#include "MySettings.h"

MySettings::MySettings() : _widthOfGameWindow(1200), _heighOfGameWindow(800)
{
    _gameWindow.create(sf::VideoMode(_widthOfGameWindow, _heighOfGameWindow), "");
    _gameWindow.setFramerateLimit(120);
    _gameWindow.setMouseCursorVisible(false);
    initGameWindowBorders();
    initBattleAreaBorders();
}

MySettings::MySettings(unsigned width, unsigned height, std::string title) : _widthOfGameWindow(width), _heighOfGameWindow(height)
{
    _gameWindow.create(sf::VideoMode(_widthOfGameWindow, _heighOfGameWindow), title);
}

void MySettings::initGameWindowBorders()
{
    _gameWindowBorders.setSize(sf::Vector2f(_widthOfGameWindow, _heighOfGameWindow));
    _gameWindowBorders.setPosition(0, 0);
    _gameWindowBorders.setFillColor(sf::Color::Transparent);
    _gameWindowBorders.setOutlineThickness(_outlineThickness);
    _gameWindowBorders.setOutlineColor(sf::Color::Black);
}

void MySettings::initBattleAreaBorders()
{
    float widthOfGameWindow = _widthOfGameWindow;
    float heightOfGameWindow = _heighOfGameWindow;

    _battleAreaBorders.setSize(sf::Vector2f(widthOfGameWindow * 0.8f, heightOfGameWindow * 0.8f));
    _battleAreaBorders.setPosition(widthOfGameWindow * 0.1f, heightOfGameWindow * 0.1f);
    _battleAreaBorders.setFillColor(sf::Color::Transparent);
    _battleAreaBorders.setOutlineThickness(_outlineThickness);
    _battleAreaBorders.setOutlineColor(sf::Color::Black);
}


sf::RenderWindow& MySettings::getGameWindow()
{
    return _gameWindow;
}

float MySettings::getWidthOfGameWindow()
{
    return _widthOfGameWindow;
}

void MySettings::setWidthOfGameWindow(float newWidth)
{
    _widthOfGameWindow = newWidth;
}

float MySettings::getHeightOfGameWindow()
{
    return _heighOfGameWindow;
}

void MySettings::setHeightOfGameWindow(float newHeight)
{
    _heighOfGameWindow = newHeight;
}

sf::RectangleShape& MySettings::getGameWindowBorders()
{
    return _gameWindowBorders;
}

void MySettings::setGameWindowBorders(sf::RectangleShape newBorders)
{
    _gameWindowBorders = newBorders;
}

float MySettings::getWidthOfGameWindowBorders()
{
    return _gameWindowBorders.getSize().x;
}

void MySettings::setWidthOfGameWindowBorders(float width)
{
    _gameWindowBorders.setSize(sf::Vector2f(width, _gameWindowBorders.getSize().y));
}

float MySettings::getHeightOfGameWindowBorders()
{
    return _gameWindowBorders.getSize().y;
}

void MySettings::setHeightOfGameWindowBorders(float height)
{
    _gameWindowBorders.setSize(sf::Vector2f(_gameWindowBorders.getSize().x, height));
}

sf::RectangleShape& MySettings::getBattleAreaBorders()
{
    return _battleAreaBorders;
}

void MySettings::setBattleAreaBorders(sf::RectangleShape newBorders)
{
    _battleAreaBorders = newBorders;
}

float MySettings::getWidthOfBattleAreaBorders()
{
    return _battleAreaBorders.getSize().x;
}

void MySettings::setWidthOfBattleAreaBorders(float width)
{
    _battleAreaBorders.setSize(sf::Vector2f(width, _battleAreaBorders.getSize().y));
}

float MySettings::getHeightOfBattleAreaBorders()
{
    return _battleAreaBorders.getSize().y;
}

void MySettings::setHeightOfBattleAreaBorders(float height)
{
    _battleAreaBorders.setSize(sf::Vector2f(_battleAreaBorders.getSize().x, height));
}
