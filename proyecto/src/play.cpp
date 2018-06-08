#include "play.h"

mapa::mapa()
{

  
	if(!Tmapa.loadFromFile("imagenes/mapa.jpg"))
     throw EXIT_FAILURE;
    this->x = 0;
    this->y = 0;
    this->cont=0;

    Tmapa.setSmooth(true); 

    Smapa.setTexture(Tmapa);

    Smapa.setScale(sf::Vector2f(0.86f, 0.70f));

    //Smapa.setScale(sf::Vector2f(0.49f, 0.43f));
    Smapa.setPosition(sf::Vector2f(25.0f,0.0f));

   
}

mapa::~mapa()
{

}

void mapa::Owindow(sf::RenderWindow &window)
{
  sf::Vector2i screenDimensions(1000,800);

  sf::Vector2f position(0, 0);


  view.reset(sf::FloatRect(0,0, 940, 800));
  view.setViewport(sf::FloatRect(0,0,1,1.5f));
  
  bool acerca = false ;

	 while (window.isOpen())
    {
          if (acerca)
          {     
                window.setView(view);

                time1 = clock.getElapsedTime();
                sf::Time t1 = sf::milliseconds(900);

                if (time1.asMilliseconds() > t1.asMilliseconds())
                { 
                  cont++;

                  view.setCenter(600,300);
                  view.zoom(0.7f);
                  //view.setRotation(10);                  
                 
                  clock.restart();
                }  
                if(cont==4)
                {
                  p.openW(window);
                }
          }
                
        while (window.pollEvent(event))
      	{
          if (event.type == sf::Event::Closed)
              window.close();

          if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) )
                 window.close(); 



              if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return) )
              {
              
              	  acerca = true;

              } 

      	}

          

		window.clear();
    window.draw(Smapa);
		window.display();
    }
}
