#include "SFML/Graphics.hpp"
#include <iostream>
#include "Menu.h"
#include "play.h"

int main()
{
	mapa 	play;
	sf::Texture texture;
	sf::Sprite texture1;
	sf::RenderWindow window(sf::VideoMode(940, 800), " ");
	sf:window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(7);

	Menu menu(window.getSize().x,window.getSize().y);

	if(!texture.loadFromFile("pergamino.jpg"))
	{
		return EXIT_FAILURE;
	}

	texture1.setTexture(texture);
	texture1.setPosition(200,200);
	texture1.scale(sf::Vector2f(0.27f,0.24f));

	while(window.isOpen())
	{
		sf::Event event;
		texture1.setPosition(000,000);

		while(window.pollEvent(event))
		{
			switch(event.type)
			{

				case sf::Event::KeyReleased:

					switch (event.key.code)
					{
						case sf::Keyboard::Left:
							menu.MoveUp();
							break;

						case sf::Keyboard::Right:
							menu.MoveDown();
							break;

						case sf::Keyboard::Return:

							switch (menu.Boton())
							{
								case 0:

          							play.Owindow(window);
									std::cout << "Play Button has been Pressed" << "\n";
									break;

								case 1:
									std::cout << "Option Button has been Pressed" << "\n";
									break;

								case 2:
									window.close();
									break;
							}
							break;
					}

					break;

				case sf::Event::Closed:
					window.close();

					break;
			}
		}

		window.clear();

		window.clear(); 
        window.draw(texture1);

		menu.draw(window);

		window.display();
	}

	return 0;
}
