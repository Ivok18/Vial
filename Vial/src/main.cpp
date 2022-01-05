#include "AGame.h"

int main()
{
	//code
	srand(time(nullptr));
	AGame game;
	game.run();
	return EXIT_SUCCESS;
}







































































































































































//#include <iostream>


//onstexpr auto SCALE = 30.f;



//#include "SFML/Graphics.hpp"
//#include "box2d/box2d.h"







	/*sf::RenderWindow gameWindow(sf::VideoMode(1200, 800), "Vial");
	gameWindow.setFramerateLimit(120);
	gameWindow.setMouseCursorVisible(false);

	
	b2Vec2 gravity(0.f, 9.8f);
	b2World world(gravity);

	sf::Texture cursorTexture;
	cursorTexture.loadFromFile("data/cursor.png");
	sf::Sprite cursorSprite(cursorTexture);


	int level = 1;

	sf::Font font;
	if (!font.loadFromFile(("data/Fonts/arial.ttf")))
		return EXIT_FAILURE;


	

	sf::RectangleShape rectangle;
	rectangle.setSize(sf::Vector2f(200, 200));
	rectangle.setPosition(100, 100);
	rectangle.setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255, 50 + rand() % 206));

	sf::Texture groundTexture;
	if(!groundTexture.loadFromFile("data/ground.jpg"))
	{
		return EXIT_FAILURE;
	}

	sf::RectangleShape ground;
	ground.setSize(sf::Vector2f(1200, 16));
	ground.setOrigin(600, 8);
	ground.setPosition(600, 800);
	ground.setFillColor(sf::Color::Green);

	sf::RectangleShape colliderView;

	

	b2BodyDef groundBodyDef;
	float x = 600;
	float y = 800;
	groundBodyDef.position = b2Vec2(x/ SCALE, y / SCALE);
	groundBodyDef.type = b2_staticBody;
	b2Body* groundBody = world.CreateBody(&groundBodyDef);
	b2PolygonShape groundShape;
	groundShape.SetAsBox(1200.f/ 2 / SCALE, 16.f / 2 / SCALE);
	b2FixtureDef groundFixtureDef;
	groundFixtureDef.density = 0.f;
	groundFixtureDef.shape = &groundShape;
	groundBody->CreateFixture(&groundFixtureDef); //create ground

	


	


	//movement
	bool up = false;
	bool down = false;
	bool left = false;
	bool right = false;


	while (gameWindow.isOpen())
	{
		cursorSprite.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(gameWindow)));
		float x = sf::Mouse::getPosition(gameWindow).x;
		float y = sf::Mouse::getPosition(gameWindow).y;

		sf::Event event;

		while (gameWindow.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
			{
				gameWindow.close();
			}
			if(event.type == sf::Event::KeyPressed)
			{
				if(event.key.code == sf::Keyboard::Z || event.key.code == sf::Keyboard::Up)
				{
					for (b2Body* bodyIterator = world.GetBodyList(); bodyIterator != 0; bodyIterator = bodyIterator->GetNext())
					{
						if(bodyIterator->GetType() == b2_dynamicBody)
						{
							float bodyXpos = bodyIterator->GetPosition().x * SCALE;
							float bodyYpos = bodyIterator->GetPosition().y * SCALE;
							float bodyWidth = 50.f;
							float bodyHeight = 50.f;

							//std::cout << "body pos x:" << boxXPos << std::endl;
							//std::cout << "body pos y:" << boxYPos << std::endl;
							sf::RectangleShape bodyShape;
							bodyShape.setSize(sf::Vector2f(50, 50));
							bodyShape.setOrigin(25, 25);
							bodyShape.setPosition(SCALE * bodyIterator->GetPosition().x, SCALE * bodyIterator->GetPosition().y);
							bodyShape.setRotation(bodyIterator->GetAngle() * 180 / b2_pi);
							bodyShape.setFillColor(sf::Color::Green);

							sf::FloatRect boxCollider(bodyXpos - bodyWidth / 2.f, bodyYpos - bodyHeight / 2.f, 50, 55);

							//sf::RectangleShape colliderView;
							//colliderView.setSize(sf::Vector2f(boxCollider.width, boxCollider.height));
							//colliderView.setPosition(boxCollider.left, boxCollider.top);
							//colliderView.setRotation(bodyIterator->GetAngle() * 180 / b2_pi);
							//colliderView.setOutlineThickness(-2);
							//colliderView.setOutlineColor(sf::Color::Blue);
							//colliderView.setFillColor(sf::Color::Transparent);

							std::cout << "---ground---" << std::endl;
							std::cout << ground.getPosition().x << std::endl;
							std::cout << ground.getPosition().y << std::endl;

							std::cout << std::endl << std::endl;
							std::cout << "---box---" << std::endl;
							std::cout << boxCollider.left << std::endl;
							std::cout << boxCollider.top << std::endl;

							if (boxCollider.intersects(ground.getGlobalBounds()))
							{
								up = true;
								std::cout << "I can jump now" << std::endl;
							}

							
						}
					}
					
				}
				if(event.key.code == sf::Keyboard::S || event.key.code == sf::Keyboard::Down)
				{
					down = true;
				}
				if(event.key.code == sf::Keyboard::Q || event.key.code == sf::Keyboard::Left)
				{
					left = true;
				}
				if (event.key.code == sf::Keyboard::D || event.key.code == sf::Keyboard::Right)
				{
					right = true;
				}
			}
			if (event.type == sf::Event::KeyReleased)
			{
				if (event.key.code == sf::Keyboard::Z || event.key.code == sf::Keyboard::Up)
				{
					up = false;
				}
				if (event.key.code == sf::Keyboard::S || event.key.code == sf::Keyboard::Down)
				{
					down = false;
				}
				if (event.key.code == sf::Keyboard::Q || event.key.code == sf::Keyboard::Left)
				{
					left = false;
				}
				if (event.key.code == sf::Keyboard::D || event.key.code == sf::Keyboard::Right)
				{
					right = false;
				}
			}
			if(event.type == sf::Event::MouseButtonPressed)
			{
				if(event.mouseButton.button == sf::Mouse::Left)
				{
					b2BodyDef boxBodyDef;
					boxBodyDef.position = b2Vec2(x / SCALE, y / SCALE);
					boxBodyDef.type = b2_dynamicBody;
					b2Body* boxBody = world.CreateBody(&boxBodyDef);

					b2PolygonShape boxShape;
					boxShape.SetAsBox(50.f / 2 / SCALE, 50.f / 2.f / SCALE);
					b2FixtureDef boxFixtureDef;
					boxFixtureDef.density = 1.f;
					boxFixtureDef.friction = 1.f;
					boxFixtureDef.shape = &boxShape;
					boxBody->CreateFixture(&boxFixtureDef);
				}
			}
		}

		world.Step(1 / 60.f, 8, 3);

		gameWindow.clear(sf::Color::White);

		//update everything
		if(up)
		{
			for (b2Body* bodyIterator = world.GetBodyList(); bodyIterator!=0; bodyIterator = bodyIterator->GetNext())
			{
				if(bodyIterator->GetType() == b2_dynamicBody)
				{
					//sf::FloatRect boxCollider(SCALE * (bodyIterator->GetPosition().x - 25), SCALE * (bodyIterator->GetPosition().y - 25), 50, 50);
					float force = bodyIterator->GetMass() * gravity.y;
					//float limiter = 0.1f;
					bodyIterator->ApplyLinearImpulse(b2Vec2(0.f, -force), b2Vec2(bodyIterator->GetPosition().x, bodyIterator->GetPosition().y), true);
					up = false;
				}
				
			}
		}
		/*if(down)
		{
			for (b2Body* bodyIterator = world.GetBodyList(); bodyIterator != 0; bodyIterator = bodyIterator->GetNext())
			{
				if (bodyIterator->GetType() == b2_dynamicBody)
				{
					float force = bodyIterator->GetMass() * gravity.y;
					float limiter = 0.1f;
					bodyIterator->ApplyLinearImpulse(b2Vec2(0.f, force * limiter), b2Vec2(bodyIterator->GetPosition().x, bodyIterator->GetPosition().y), true);
				}

			}
		}
		*/
	/*
	if(left)
		{
			for (b2Body* bodyIterator = world.GetBodyList(); bodyIterator != 0; bodyIterator = bodyIterator->GetNext())
			{
				if (bodyIterator->GetType() == b2_dynamicBody)
				{
					float force = bodyIterator->GetMass() * gravity.y;
					float limiter = 0.05f;
					bodyIterator->ApplyLinearImpulse(b2Vec2(-force * limiter, 0.f), b2Vec2(bodyIterator->GetPosition().x, bodyIterator->GetPosition().y), true);
				}

			}
		}
		if(right)
		{
			for (b2Body* bodyIterator = world.GetBodyList(); bodyIterator != 0; bodyIterator = bodyIterator->GetNext())
			{
				if (bodyIterator->GetType() == b2_dynamicBody)
				{
					float force = bodyIterator->GetMass() * gravity.y;
					float limiter = 0.05f;
					bodyIterator->ApplyLinearImpulse(b2Vec2(force * limiter, 0.f) , b2Vec2(bodyIterator->GetPosition().x, bodyIterator->GetPosition().y), true);
				}
				

			}
		}

		//draw everything 
		for (b2Body* bodyIterator = world.GetBodyList();  bodyIterator!=0 ; bodyIterator = bodyIterator->GetNext())
		{
			if(bodyIterator->GetType() == b2_dynamicBody)
			{
				float bodyXpos = bodyIterator->GetPosition().x * SCALE;
				float bodyYpos = bodyIterator->GetPosition().y * SCALE;
				float bodyWidth = 50.f;
				float bodyHeight = 50.f;
				bodyIterator->SetLinearDamping(2.f);

				//std::cout << "body pos x:" << boxXPos << std::endl;
				//std::cout << "body pos y:" << boxYPos << std::endl;
				sf::RectangleShape bodyShape;
				bodyShape.setSize(sf::Vector2f(50, 50));
				bodyShape.setOrigin(25, 25);	
				bodyShape.setPosition(SCALE * bodyIterator->GetPosition().x, SCALE * bodyIterator->GetPosition().y);
				bodyShape.setRotation(bodyIterator->GetAngle() * 180 / b2_pi);
				bodyShape.setFillColor(sf::Color::Green);

				sf::Text text;
				float textSize = text.getCharacterSize();
				text.setOrigin(textSize / 2.f, textSize / 2.f);
				text.setPosition(bodyXpos, bodyYpos - bodyHeight / 2 - textSize / 2);

				// select the font
				text.setFont(font); // font is a sf::Font


				// set the string to display
				text.setString(std::to_string(level));

				// set the character size
				text.setCharacterSize(15); // in pixels, not points!

				// set the color
				text.setFillColor(sf::Color::Red);
				text.setOutlineColor(sf::Color::Blue);
				text.setOutlineThickness(1);

				// set the text style
				text.setStyle(sf::Text::Bold | sf::Text::Underlined);

				

				/*sf::FloatRect boxCollider(bodyXpos - bodyWidth / 2.f, bodyYpos - bodyHeight / 2.f, 50, 51);

				sf::RectangleShape colliderView;
				colliderView.setSize(sf::Vector2f(boxCollider.width, boxCollider.height));
				colliderView.setPosition(boxCollider.left, boxCollider.top);
				colliderView.setRotation(bodyIterator->GetAngle() * 180 / b2_pi);
				colliderView.setOutlineThickness(-2);
				colliderView.setOutlineColor(sf::Color::Blue);
				colliderView.setFillColor(sf::Color::Transparent);
				*/

				
/*
				gameWindow.draw(bodyShape);
				gameWindow.draw(text);
				//gameWindow.draw(colliderView);
			}

			else
			{
				float groundYPos = groundBody->GetPosition().y;
				//std::cout << "ground:" << groundYPos << std::endl;
			}
		}
		gameWindow.draw(ground);
		gameWindow.draw(cursorSprite);
		gameWindow.display();
		
	}
	*/

