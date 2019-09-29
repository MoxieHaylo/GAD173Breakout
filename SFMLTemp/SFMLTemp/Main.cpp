#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <conio.h> //C header file used mostly by MS-DOS compilers to provide console input/output. 
#include <iostream>
using namespace std;

int main()
{
	//window width & height constexpr specifies value at compile time, keeping the value constant
	constexpr int windowX{ 1200 }, windowY{ 600 };
	sf::RenderWindow window(sf::VideoMode(windowX, windowY), "Another Janky Student Game!");
	window.setFramerateLimit(60); //Scotty says we can't go any faster

	constexpr float ballRadius = 10.f;
	int speed = 10; //paddle speed


	struct Ball
	{
		sf::CircleShape ball; //Create ball

		Ball(float mX, float mY)
		{
			ball.setPosition(mX, mY);//set starting position
			ball.setRadius(ballRadius);
			ball.setFillColor(sf::Color::Cyan); //Set ball colour
			ball.setOrigin(ballRadius, ballRadius);//this is the centre of the object
		}
	};

	sf::Vector2f rectSize = sf::Vector2f(100.f, 15.f); //paddle dimensions in pixels
	sf::Vector2f rectPosition = sf::Vector2f((windowX / 2) - (rectSize.x / 2), (windowY / 1.15) - (rectSize.y / 1.15)); //positions paddle towards the bottom of the screen
	sf::Color colour = sf::Color(255, 255, 255, 255); //0-255 for all 4, r,g,b,a

	sf::RectangleShape paddle(rectSize); //Our rectangle itself
	paddle.setFillColor(colour); //Set the colour
	paddle.getLocalBounds();
	paddle.setPosition(rectPosition);

	Ball ball{ windowX / 2, windowY / 2 };//initialises ball

	//ball.setPosition(sf::Vector2f(rectPosition.x, rectPosition.y - rectSize.y));

	//Code runs while window is open
	while (window.isOpen())
	{

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
		window.draw(paddle);
		window.draw(ball.ball);
		window.display();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) break;
	}
	return 0;
}