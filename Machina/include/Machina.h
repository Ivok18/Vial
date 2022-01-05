ifndef GAME
#define GAME

//GENERIC INCLUDES
#include <SFML/Graphics.hpp>
#include <iostream>

#include "Player.h"

//GAME RELATED INCLUDES


class Game
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
	Game();
	Game(Player player);
	~Game();

};

#endif
