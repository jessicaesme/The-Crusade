#ifndef COLISIONES_H
#define COLISIONES_H 

#include <personaje.h>

class colisiones
{


private:
    
    sf::Texture objetos[3];
    sf::Sprite Sobjetos[3];

   
   
public:
	
	colisiones();
	~colisiones();

	void CargarImagen();

  bool ColSprites(sf::Sprite,sf::Sprite,int x,int y);
	
  void Dibujar1(sf::RenderWindow &window);

  void DibujarOb(sf::RenderWindow &window,int a);

  bool colicionD(sf::Sprite P,int x, int y);

  bool colicionI(sf::Sprite P,int x, int y);

  bool colicionInf(sf::Sprite P,int x, int y);

  bool colicionS(sf::Sprite P,int x, int y);

};



#endif