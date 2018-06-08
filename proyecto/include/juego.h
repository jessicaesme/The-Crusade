#ifndef JUEGO_H
#define JUEGO_H 

#include <personaje.h>
#include <jefe.h>
#include <colisiones.h>
#include "muerte.h"

class juego
{


private:

    sf::Music music;
    
    sf::SoundBuffer buffer;
    sf::Sound sonido;

    personaje P1;
    jefe J1;
    jefe J2[4];
    colisiones Cop;
   
    sf::Clock clock;
    sf::Time time1;

    muerte M;

    sf::Texture fondo;
     sf::Sprite Sfondo;

    sf::Event event;

    sf::View view;

    int enemyX,enemyY;
    int enemyX2[4],enemyY2[4];    
    int x,y,SlimiteY,IlimiteY;
    int posxbar,posybar,anchobar,altobar; //datos para la barra de vida

   
   
public:
	
	juego();
	~juego();

	void CargarImagen();

	void openW(sf::RenderWindow &window);

    void aparecerEnemigos();

	void Dibujar1(sf::RenderWindow &window);

	void EventW1(sf::RenderWindow &window);

  void enemyAction();


};



#endif