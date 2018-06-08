#include "personaje.h"

personaje::personaje()
{

  this->dan = 5;
  this->izquierda = false;
  this->x = 0;
  this->y = 310;
  this->Vid.setVida(100);


}

personaje::~personaje()
{

}
int personaje::getVidas()
{
  return this->Vid.getVida();
}
void personaje::setVidas(int v)
{
  this->Vid.setVida(v);
}

void personaje::cargarVariable(int *anchos,int *altos,int tam)
{
  
  for (int i = 0; i < tam; ++i)
  {
    posx[i] = 0;
    posy[i] = 0;
    ancho[i] = *(anchos+i);
    alto[i] = *(altos+i);
    activadores[i] = false;
  
  }  
}

void personaje::setXY(int X, int Y)
{
  this->x = X;
  this->y = Y;
}

int personaje::getDan()
{
  return this->dan;
}

void personaje::setDan(int d)
{
  this->dan = d;
}


void personaje::MoverSprite(int X,int Y)
{
  Spersonaje[0].setPosition(sf::Vector2f(x,y));
}

void personaje::setIzquierda(bool T)
{
  this->izquierda = T;
} 

void  personaje::CargarImagen(std::string titulo,int cantidad)
{
  Vid.cargarImagen();

  std::string name;
	for (int i = 0; i < cantidad; ++i)
    {
      name ="imagenes/"+titulo+std::to_string(i)+".png";

      if(!Tpersonaje[i].loadFromFile(name))
        throw EXIT_FAILURE;

      Tpersonaje[i].setSmooth(true); 
      Spersonaje[i].setTexture(Tpersonaje[i]);

    }

	Spersonaje[0].setScale(sf::Vector2f(0.75f, 0.85f));
  Spersonaje[0].setPosition(sf::Vector2f(x,y));
  sf::IntRect pos(posx[0], posy[0], ancho[0], alto[0]);
  Spersonaje[0].setTextureRect(pos);

	Spersonaje[1].setScale(sf::Vector2f(0.39f, 0.46f));	
	Spersonaje[2].setScale(sf::Vector2f(0.33f, 0.41f));

}

void personaje::animar(sf::RenderWindow &window,int i,int cantidad)
{

  Spersonaje[i].setPosition(sf::Vector2f(x,y));
  if (posx[i] != ancho[i]* cantidad )
  {
      
    if (izquierda)
      posy[i]=alto[i];
    else
      posy[i]=0;
    
    sf::IntRect pos(posx[i], posy[i], ancho[i], alto[i]);
    Spersonaje[i].setTextureRect(pos);
    posx[i] += ancho[i];
    sleep(0.99);

    }else
    {
    
       activadores[i] = false;
       posx[i]=0;
       
    }
} 

sf::Sprite personaje::getSprite(int n)
{
  return Spersonaje[n];

}

void personaje::setActivadores(int i,bool T)
{
  this->activadores[i] = T;
}

bool personaje::getActivadores(int i )
{
  return activadores[i];
}

void personaje::Dibujar(sf::RenderWindow &window)
{
  
    if (activadores[0] != true and activadores[1] != true and activadores[2] != true  and activadores[3] != true )
    {
      Spersonaje[0].setPosition(sf::Vector2f(x,y));
      sf::IntRect pos(posx[0], posy[0], ancho[0], alto[0]);
      Spersonaje[0].setTextureRect(pos);
      window.draw(Spersonaje[0]);    
      
    } 


    for (int i = 0; i < 3; ++i)
    {
      if (activadores[i])
        window.draw(Spersonaje[i]);
    }

    Vid.DibujarVida(window,x,y);
      
}
	