#include "Menu.h"

Menu::Menu(float width, float height)
{
	

	if(!font.loadFromFile("Germanica1.ttf"))
	{
		//Handle error
	}

	menu[0].setFont(font);
	menu[0].setColor(sf::Color::Red);
	menu[0].setString("Jugar");
	menu[0].setScale(sf::Vector2f(1.5f,1.5f));
	menu[0].setPosition(sf::Vector2f(width - 820, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));
	
	menu[1].setFont(font);
	menu[1].setColor(sf::Color::White);
	menu[1].setString("Opciones");
	menu[1].setScale(sf::Vector2f(1.5f,1.5f));
	menu[1].setPosition(sf::Vector2f(width - 560, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));
	
	menu[2].setFont(font);
	menu[2].setColor(sf::Color::White);
	menu[2].setString("Salir");
	menu[2].setScale(sf::Vector2f(1.5f,1.5f));
	menu[2].setPosition(sf::Vector2f(width - 250, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));
	
	Opcion = 0;
}

Menu::~Menu()
{

}

void Menu::draw(sf::RenderWindow &window)
{
	for(int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(menu[i]);
	}
}

void Menu::MoveUp()
{
	if(Opcion - 1 >= 0)
	{
		menu[Opcion].setColor(sf::Color::White);
		Opcion--;
		menu[Opcion].setColor(sf::Color::Red);
	}
}

void Menu::MoveDown()
{
	if(Opcion + 1 < MAX_NUMBER_OF_ITEMS)
	{
		menu[Opcion].setColor(sf::Color::White);
		Opcion++;
		menu[Opcion].setColor(sf::Color::Red);
	}
}
