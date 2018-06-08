#ifndef PERSONAJE_H
#define PERSONAJE_H 

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <unistd.h>
#include "vida.h"

class personaje
{


private:
  
  sf::Texture Tpersonaje[4];
 	sf::Sprite Spersonaje[3];
  vida Vid;
  int posx[4],posy[4],ancho[4],alto[4]; //datos para el caminar del personaje 

  bool activadores[4];

  int dan;
 
  bool izquierda;

   int x,y;

public:
	
	personaje();
	~personaje();

  void cargarVariable(int *ancho,int *alto,int tam);
	void CargarImagen(std::string titulo,int cantidad);

  void setIzquierda(bool T);

  int getVidas();
  void setVidas(int);

  int getDan();
  void setDan(int);

  void setActivadores(int ,bool);

  bool getActivadores(int);

  sf::Sprite getSprite(int n);

	void  animar(sf::RenderWindow &window,int,int);

	void Dibujar(sf::RenderWindow &window);

  void MoverSprite(int X,int Y);

  void setXY(int X, int Y);

};



#endif