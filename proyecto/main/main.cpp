#include "Menu.h"
#include "play.h"

int main()
{
	mapa 	play;
	sf::Texture texture;
	sf::Sprite texture1;
	sf::SoundBuffer buffer;
    sf::Sound sonido;
	
	sf::RenderWindow window(sf::VideoMode(940, 800), " ");
	sf:window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(13);
	
	
	if (!buffer.loadFromFile("sound.ogg"))
 	   throw EXIT_FAILURE;
 
	sonido.setBuffer(buffer);
	  
	sonido.setVolume(100);
	
	Menu menu(window.getSize().x,window.getSize().y);

	if(!texture.loadFromFile("imagenes/pergamino.jpg"))
	{
		return EXIT_FAILURE;
	}

	texture1.setTexture(texture);
	texture1.setPosition(200,200);
	texture1.scale(sf::Vector2f(0.8f,0.7f));


	

	

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
							sonido.play();
							menu.MoveUp();
							break;
							

						case sf::Keyboard::Right:
							menu.MoveDown();
							sonido.play();
							break;

						case sf::Keyboard::Return:

							switch (menu.Boton())
							{
								case 0:

          							play.Owindow(window);
          							sonido.play();
									break;

								case 1:
									sonido.play();
									break;

								case 2:
									sonido.play();
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
