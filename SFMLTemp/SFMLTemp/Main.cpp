#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

int main()
{

	sf::RenderWindow window(sf::VideoMode(600, 600), "Neato");

	sf::Event event;

	sf::Texture texture;
	if (!texture.loadFromFile("res/img/Sprite_spr.png"))
	{
		cout << "Load failed" << endl;
		system("pause");
	}
	

	sf::Sprite itsASprite;
	itsASprite.setTexture(texture);

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		window.clear();


		window.draw(itsASprite);

		window.display();
	}
	
	return 0;
}
