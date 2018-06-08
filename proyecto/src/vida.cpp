#include "vida.h"
  
vida::vida()
{
  this-> anchobar = 419;
  this-> altobar = 147;
  this-> posxbar = 0;
  this-> posybar = 0;
  this-> Vida=0;

}

 int vida::getVida()
  {
    return this-> Vida;
  }

  void vida::setVida(int v)
  {
    this->Vida = v;
  }
  
 void vida::cargarImagen()
 {
 	if(!barra.loadFromFile("imagenes/BarraVida.png"))
     throw EXIT_FAILURE;

	  barra.setSmooth(true); 

	  Sbarra.setTexture(barra);

	  Sbarra.setScale(sf::Vector2f(0.25f, 0.35f));
 }

    

void vida::Abarra(sf::RenderWindow &window, int x , int y)
{
	
	  sf::IntRect posbar(posxbar,posybar,anchobar,altobar);
	  Sbarra.setTextureRect(posbar);

	  Sbarra.setPosition(sf::Vector2f(x+10,y-50));
    

      
      if(Vida >= 0)
      { 
        
          
        if(Vida >= 95)
          posybar = 0;

        if(Vida >= 90 && Vida < 95)
          posybar = altobar * 1 ;

        if(Vida >= 85 && Vida < 90)
          posybar = altobar * 2 ;

        if(Vida >= 80 && Vida < 85)
          posybar = altobar * 3 ;
  
         if(Vida >= 70 && Vida < 80)
          posybar = altobar * 4 ;

        if(Vida >= 65 && Vida < 70)
          posybar = altobar * 5 ;

        if(Vida >= 60 && Vida < 65)
          posybar = altobar * 6 ;

        if(Vida >= 50 && Vida < 60)  
          altobar * 7 ;

        if(Vida >= 45 && Vida < 50)
        {
          posybar = altobar * 0; 
          posxbar = anchobar ; 
        }

        if(Vida >= 40 && Vida < 45)
        {
          posybar = altobar * 1; 
          posxbar = anchobar ; 
        }

        if(Vida >= 35 && Vida < 40)
        {
          posybar = altobar * 2; 
          posxbar = anchobar ; 
        }

        if(Vida >= 30 && Vida < 35)
        {
          posybar = altobar * 3; 
          posxbar = anchobar ; 
        }

        if(Vida >= 20 && Vida < 30)
        {
          posybar = altobar * 4; 
          posxbar = anchobar ; 
        }

        if(Vida >= 10 && Vida < 20)
        {
          posybar = altobar * 5; 
          posxbar = anchobar ; 
        }

        if(Vida > 0 && Vida < 10)
        {
          posybar = altobar * 6; 
          posxbar = anchobar ; 
        }

        if(Vida < 5) 
        {
          posybar = altobar * 7; 
          posxbar = anchobar ; 
        }
      }
}

void vida::DibujarVida(sf::RenderWindow &window, int x , int y)
{
	
  Abarra(window,x,y); 
  window.draw(Sbarra);

}