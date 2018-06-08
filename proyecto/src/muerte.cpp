#include "muerte.h"

muerte::muerte()
{
	
}

muerte::~muerte()
{

}


void muerte::cargarImagenes(int x, int y)
{

  if(!M.loadFromFile("imagenes/muerte.png"))
     throw EXIT_FAILURE;

    M.setSmooth(true); 

    SM.setTexture(M);

    SM.setScale(sf::Vector2f(0.35f, 0.45f));

    SM.setPosition(sf::Vector2f(x+25,y+10));


   if(!GameOver.loadFromFile("imagenes/GameOver.png"))
     throw EXIT_FAILURE;

    GameOver.setSmooth(true); 

    SGameOver.setTexture(GameOver);

    //SGameOver.setScale(sf::Vector2f(0.35f, 0.45f));

    SGameOver.setPosition(sf::Vector2f(x-105,y-185));
}


void muerte::Mwindow(sf::RenderWindow &window,int x ,int y)
{
  
    cargarImagenes(x,y);

     while (window.isOpen())
    {
        
        while (window.pollEvent(event))
        {
          if (event.type == sf::Event::Closed)
              window.close();

          if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) )
                 window.close(); 

          if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return) )
                 window.close(); 
         

        }

        dibujarMuerte(window);
    }
}



void muerte::dibujarMuerte(sf::RenderWindow &window)
{
	
    window.clear();	
	window.draw(SM);
	window.draw(SGameOver);
    window.display();

}