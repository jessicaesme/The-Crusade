
#include <SFML/Graphics.hpp>
#include "juego.h"

class mapa
{
private:
	
	
	sf::Event event;

	juego p;	

	sf::Texture Tmapa;

    sf::Sprite Smapa;

    sf::View view;
   
    sf::Clock clock;

    sf::Time time1;

    int x, y,cont;
   

public:
	mapa();
	~mapa();
	
	void Owindow(sf::RenderWindow &window);
};