#ifndef VENTANA_H
#define  VENTANA_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <stdlib.h>
#include <time.h>
#include <iostream>

class juego
{

private:

	
	sf::Texture Iperson,fondo,carne;
   	sf::Texture objetos[4];

    sf::Sprite Sperson,Sfondo,Scarne;
    sf::Sprite Sobjetos[4];

    sf::Event event;
    int ImagenX,ImagenY,PersonX,personY;;
    int SlimiteY,IlimiteY;
    int x,y,posx,posy,ancho,alto;
   

public:
	
	juego();
	~juego();

	void CargarImagen();
	void EventW(sf::RenderWindow &window);
	void Dibujar(sf::RenderWindow &window);
	void openW(sf::RenderWindow &window);
	bool colicion(int );

	void movRand();

};

#endif