#ifndef MUERTE_H
#define MUERTE_H 
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


class muerte
{
private:
	sf::Texture M;
    sf::Sprite SM;

     sf::Event event;
	
	sf::Texture GameOver;
    sf::Sprite SGameOver;
	


public:

	muerte();
	~muerte();
	
	void cargarImagenes(int x, int y);
	void dibujarMuerte(sf::RenderWindow &window);
	void Mwindow(sf::RenderWindow &window,int ,int);
};
#endif