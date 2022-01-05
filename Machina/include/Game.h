#ifndef MACHINA
#define MACHINA

//GENERIC INCLUDES
#include <SFML/Graphics.hpp>
#include <iostream>

#include "Player.h"

//GAME RELATED INCLUDES


class Machina
{
protected:
	//Settings _settings;
	float totalTimeElapsed = 0.f;
	Player _player;


protected:
	void initializations();
		void initializePlayer();


	void start();
		void receiveInputs();
			void receivePlayerInputs(sf::Event& event);

	void updateDatas();

	void renderDatas();
public:
	Machina();
	Machina(Player player);
	~Machina() = default;

};

#endif
