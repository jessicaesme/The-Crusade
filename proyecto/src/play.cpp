#include "play.h"

mapa::mapa()
{

  
	if(!Tmapa.loadFromFile("mapa.png"))
     throw EXIT_FAILURE;

    Tmapa.setSmooth(true); 

    Smapa.setTexture(Tmapa);

    Smapa.setScale(sf::Vector2f(0.86f, 0.70f));
    Smapa.setPosition(sf::Vector2f(0.0f,0.0f));

}

mapa::~mapa()
{

}

void mapa::Owindow(sf::RenderWindow &window)
{

	 while (window.isOpen())
    {
     
        while (window.pollEvent(event))
      	{
          if (event.type == sf::Event::Closed)
              window.close();

          if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) )
                 window.close(); 



              if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return) )
              {
              
              	  play.openW(window);


              } 

      	}

		window.clear();
    window.draw(Smapa);
		window.display();
    }
}
