#include <SFML/Graphics.hpp>
#include "ventana.h"

class mapa
{
private:
	
	
	sf::Event event;

	juego play;

	sf::Texture Tmapa;

    sf::Sprite Smapa;

public:
	mapa();
	~mapa();
	
	void Owindow(sf::RenderWindow &window);
};