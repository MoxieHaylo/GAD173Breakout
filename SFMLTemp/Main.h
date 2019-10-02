#include <SFML/Graphics.hpp>
#include <iostream>

Using namespace std;

class BrickClass
{
public:
	BrickClass() {}

private:
	sf::RectangleShape bShape;
	sf::Color bColour;
	sf::Vector2f bSize;
	sf::Vector2f bPos;

};

class Ball
{
public:

private:
	sf::CircleShape ballShape;
	sf::Vector2f startPos;
	float ballRadius 10.f;
};

class Game
{
public:

	bool Start();

	int Update();

private:

	sf::RenderWindow window;

	float windW = 1200;
	float windH = 600;
	int score = 0;
	int lives = 3;

};