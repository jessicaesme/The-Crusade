#include "ventana.h"

juego::juego()
{
  
  
  this->SlimiteY = 210;
  this->IlimiteY = 400;
  this->x = 0;
  this->y = 210;
  this->posx = 0;
  this->posy = 0;
  this->ancho = 247;
  this->alto = 336;

}

juego::~juego()
{

}

void juego::CargarImagen()
{
std::string name;

  if(!fondo.loadFromFile("fond.png"))
     throw EXIT_FAILURE;

    Sfondo.setTexture(fondo);
  
    Sfondo.setScale(sf::Vector2f(0.94f, 0.69f));
  

  if(!Iperson.loadFromFile("grodod.png"))  
     throw EXIT_FAILURE;
  
    Iperson.setSmooth(true);
    Iperson.setRepeated(true);

    Sperson.setTexture(Iperson);

    Sperson.setScale(sf::Vector2f(0.35f, 0.45f));
    

    
    for (int i = 0; i < 4; ++i)
    {
      name = "ob"+std::to_string(i+1)+".png";

      if(!objetos[i].loadFromFile(name))
        throw EXIT_FAILURE;

      
      Sobjetos[i].setTexture(objetos[i]);
      


    }
    
    Sobjetos[0].setPosition(sf::Vector2f(450,300));
    Sobjetos[1].setPosition(sf::Vector2f(770,450));
  //  Sobjetos[2].setPosition(sf::Vector2f(800,300));
    Sobjetos[3].setPosition(sf::Vector2f(0,450));
    
    

}

void juego::openW(sf::RenderWindow &window)
{
  CargarImagen();
  
  while (window.isOpen())
    {
      Sperson.setPosition(sf::Vector2f(x, y));
        sf::IntRect pos(posx, posy, ancho, alto);
        Sperson.setTextureRect(pos);

        EventW(window);

        Dibujar(window);

    }

  }

bool juego::colicion(int a)
{
  
  bool choque = false;
  
  if (a == 0)
  {
  
    Sperson.setPosition(sf::Vector2f(x+5, y));
  }

  if (a == 1)
  {
    Sperson.setPosition(sf::Vector2f(x-5, y));
  }
  
  if (a == 2)
  {
  
    Sperson.setPosition(sf::Vector2f(x, y-5));
  }

  if (a == 3)
  {
    Sperson.setPosition(sf::Vector2f(x, y+5));
  }
  

  for (int i = 0; i < 4; ++i)
  {

      sf::Vector2f pos = Sobjetos[i].getPosition();
      sf::Vector2f tam = Sobjetos[i].getScale();
      
      sf::FloatRect rectI(pos.x,pos.y,(tam.x ),(tam.y/2.0f));
      sf::FloatRect rectD(pos.x+tam.x,pos.y,(tam.x ),(tam.y/2.0f));
      sf::FloatRect rectA(pos.x,pos.y,(tam.x ),(tam.y/2.0f));
      sf::FloatRect rectB(pos.x,posx+tam.x,(tam.x ),(tam.y/2.0f));

      if (Sperson.getGlobalBounds().intersects(rectI))
      {
        choque = true;
        break;
      }       
  }

  if (choque)
  {


    Sperson.setPosition(sf::Vector2f(x+2, y));
    return true;

  }

  
  return false;
}


void juego::EventW(sf::RenderWindow &window)
{
  

  while (window.pollEvent(event))
      {
          if (event.type == sf::Event::Closed)
              window.close();

          if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) )
            {
              
              posy = 0;
              posx += ancho;    
            
                if ( x < (940-80) and colicion(0) != true)
                  x  += 5; 
              
            
            }

 

          if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) )
          {
            

              if( (x > 0 ) and colicion(1) != true)
                x  -= 5;
  
              posy = 0;    
              posx += ancho;    

           }


          if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) )
          {
              if (y > SlimiteY and colicion(2) != true)
                 y  -= 5;

              posy = 0; 
              posx += ancho;    

          } 

          if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) )
           {

              if ( y < IlimiteY and colicion(3) != true)
                 y  += 5;
          
              posy = 0;    
              posx += ancho;
          }


          if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) )
                 window.close(); 

      }
}


void juego::Dibujar(sf::RenderWindow &window)
{
      window.clear();
      window.draw(Sfondo);
      

      for (int i = 0; i < 4; i++)
      {
        if (i != 2)
          window.draw(Sobjetos[i]);
      }
      
       window.draw(Sperson); 

      window.display();
}
