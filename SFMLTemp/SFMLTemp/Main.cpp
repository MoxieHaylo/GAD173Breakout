#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <conio.h> //C header file used mostly by MS-DOS compilers to provide console input/output. 
#include <iostream>
#include "Main.h"

using namespace std;

BrickClass brick;
	//vector list of bricks
	vector<BrickClass>brick(5, brick(brick));

bool Game::Start() 
{
	

	for (int i = 0; i < 15; i++)
	{
		brick[i].bShape.setSize(sf::Vector2f(75, 30));
		brick[i].bShape.setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255, rand() % 255, )));
		if (i <= 5)
		{
			brick[i].bShape.setposition(75 * i, 0);
		}
		if else(i = > 10)
		{
			brick[i].bShape.setposition(75 * (i - 11), 60);
		}
		if else(i = > 5)
		{
			brick[i].bShape.setposition(75 * (i - 6), 30);
		}
	}

	//if briks i . bshape getglobalbounds, intersects ball getglobal 
	//ball bounce0
	//brick ded move it way off the screen. Or find a better way.
	//increase score score+=1;
	//ball.ballveocity = ballvelocity * 1.03f;
	for (int i = 0; i < 15; i++)
	{
		window.draw(brick[i].bShape);
	}


	//window width & height constexpr specifies value at compile time, keeping the value constant
	constexpr int windowX{ 1200 }, windowY{ 600 };
	sf::RenderWindow window(sf::VideoMode(windowX, windowY), "Another Janky Student Game!");
	window.setFramerateLimit(60); //Scotty says we can't go any faster
	

	//set boundaries
	top.setSize((sf::Vector2f(windowX, 1)));
	top.setPosition(0, 0);
	top.setFillColor(sf::Color::Black);

	bottom.setSize((sf::Vector2f(windowX, 1)));
	bottom.setPosition(0, windowY - 1);
	bottom.setFillColor(sf::Color::Black);

	left.setSize((sf::Vector2f(1, windowY)));
	left.setPosition(0, 0);
	left.setFillColor(sf::Color::Black);

	right.setSize((sf::Vector2f(windowY, -1)));
	right.setPosition((windowX - 0, 0));
	right.setFillColor(sf::Color::Black);

	return true;
}

 

int main()
{
	Game mygame;
	if (!myGame.Start())
	{
		return EXIT_FAILURE;
	}
	return mygame.Update;

	Paddle paddle;
	paddle.paddle.setSize(sf::Vector2f(120.f, 15.f));

	Ball ball;
	ball.ballShape.setRadius(12.f);
	ball.ballShape.setPosition(paddle.paddle.getPosition().x, paddle.paddle.getPosition().y - 75);

	Ball.ball.move(ballVelocity);
	//constexpr float ballRadius = 10.f;
	int speed = 10; //paddle speed

	

	//struct Ball
	//{
	//	sf::CircleShape ball; //Create ball

	//	Ball(float mX, float mY)
	//	{
	//		ball.setPosition(mX, mY);//set starting position
	//		ball.setRadius(ballRadius);
	//		ball.setFillColor(sf::Color::Cyan); //Set ball colour
	//		ball.setOrigin(ballRadius, ballRadius);//this is the centre of the object
	//	}
	//};

	sf::Vector2f rectSize = sf::Vector2f(100.f, 15.f); //paddle dimensions in pixels
	sf::Vector2f rectPosition = sf::Vector2f((windowX / 2) - (rectSize.x / 2), (windowY / 1.15) - (rectSize.y / 1.15)); //positions paddle towards the bottom of the screen
	sf::Color colour = sf::Color(255, 255, 255, 255); //0-255 for all 4, r,g,b,a

	Ball ball{ windowX / 2, windowY / 2 };//initialises ball

	//ball.setPosition(sf::Vector2f(rectPosition.x, rectPosition.y - rectSize.y));

	//Code runs while window is open
	while (window.isOpen())
	{
		Paddle paddle

			//if(paddle.paddle.getGlobalBounds

			if (top.getglobalbounds()
				ball.Bounce(0);
				lives -= 1;
				if lives < 1)
			{
				//ends game
				return 1;
			}
		if(left.getGloablbounds().intersects(ball.ballshape.getglova())||

			//do some bouncy shit. This needs a huge clean up. Bleh.
		
		/*if (ball.getPosition().x <= 0 || ball.getPosition().x >= windowX)
		{
			velocity.x = velocity.y;
		}
		else if (ball.getPosition().y <= 0 || ball.getPosition().y >= windowY)
		{
			velocity.y = -velocity.x;
		}*/

		//check if left is pressed
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			//Move left
			rectPosition.x -= speed;
			//if our position is outside of the window, come back
			if (rectPosition.x <= 0)
			{
				rectPosition.x = 0;
			}
			//update the position of our paddle
			paddle.setPosition(rectPosition);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			//Move right
			rectPosition.x += speed;
			//If we are outside of the window, come back
			if (rectPosition.x >= windowX - rectSize.x)
			{
				rectPosition.x = windowX - rectSize.x;
			}
			//update the position of our paddle
			paddle.setPosition(rectPosition);
		}

		//ball.move(velocity); //constant movement for ball

		sf::Event event;
		//PollEvent is our window updating event
		while (window.pollEvent(event))
		{
			//if window closes
			if (event.type == sf::Event::Closed)
				window.close();
		}
		//clear window and redraw images
		window.clear();
		window.draw(paddle.paddle);
		window.draw(ball.ball);
		window.draw(top);
		window.draw(bottom);
		window.draw(left);
		window.draw(right);
		window.display();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) break;
	}
	return 0;
}