#ifndef ENTITY
#define ENTITY

//#include <string>
//#include <iostream>
//#include "termcolor/termcolor.hpp"
#include <thread>
//#include <chrono>
#include <SFML/Graphics.hpp>
#include <SFML\Audio\Music.hpp>
//#include <stdio.h>

class Entity
{
protected:
	std::string name;
	
	
public:
	Entity();
	Entity(std::string name_);
	~Entity();

};

#endif // 