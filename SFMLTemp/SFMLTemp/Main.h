#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

class BrickClass
{
public:

	sf::RectangleShape bShape;
	sf::Color bColour;
	sf::Vector2f bSize;
	sf::Vector2f bPos;

};

class Ball
{
public:

	void Bounce(int direction)
	{
		switch (direction)
		{
		case0: //V
			ballVelocity.y = -ballVelocity.y;
			break;
		case 1: //H
			ballVelocity.x = -ballVelocity.x;
			break;
		case 2:	//Both
			ballVelocity.y = -ballVelocity.y;
			ballVelocity.x = -ballVelocity.x;
			break;
		}
	}

	sf::CircleShape ballShape;
	sf::Vector2f startPos;
	float ballRadius = 10.f;
	sf::Vector2f 
};

class Paddle
{
public:
	void UpdatePosition(int direction)
	{
		paddle.setPosition(direction*speed, paddle.getPosition().y);
	}
	sf::RectangleShape paddle; //Our rectangle itself

	float speed = 10.f;
	
	sf::Color pColour; //Set the colour
	sf::Vector2f velocity
};

class Game
{
public:

	bool Start();
	int Update();

private:

	sf::RenderWindow window;

	//boundary bois
	sf::RectangleShape top;
	sf::RectangleShape bottom;
	sf::RectangleShape left;
	sf::RectangleShape right;

	float windW = 1200;
	float windH = 600;
	int score = 0;
	int lives = 3;

};