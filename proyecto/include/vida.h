#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/Audio.hpp>

#ifndef VIDA_H
#define VIDA_H 


class vida 
{
private:
	
	int Vida;
	int posxbar,posybar,anchobar,altobar; //datos para la barra de vida
	sf::Texture barra;
    sf::Sprite Sbarra;
	

public:
	 vida();
	~vida(){};
	
	void  Abarra(sf::RenderWindow &window,int,int);
	void cargarImagen();
	void DibujarVida(sf::RenderWindow &window,int,int);
	int getVida();
	void setVida(int);
};
#endif