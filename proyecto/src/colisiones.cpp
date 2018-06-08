#include "colisiones.h"

colisiones::colisiones()
{
  
}

colisiones::~colisiones()
{

}

void  colisiones::CargarImagen()
{
std::string name;

for (int i = 0; i < 3; ++i)
{
  name = "imagenes/ob"+std::to_string(i)+".png";

  if(!objetos[i].loadFromFile(name))
    throw EXIT_FAILURE;

  Sobjetos[i].setTexture(objetos[i]);

  Sobjetos[0].setPosition(sf::Vector2f(450,380));
  Sobjetos[1].setPosition(sf::Vector2f(1770,600));
  Sobjetos[2].setPosition(sf::Vector2f(1300,400));
}

}

void colisiones::DibujarOb(sf::RenderWindow &window,int a)
{
      window.draw(Sobjetos[a]); 
}


void colisiones::Dibujar1(sf::RenderWindow &window)
{
  for (int i = 0; i < 3; ++i)
    window.draw(Sobjetos[i]); 


}
	
bool colisiones::ColSprites(sf::Sprite P1,sf::Sprite J1,int x,int y)
{

  float inferior,derecho;
  float tam,pies,base;
  sf::FloatRect Pc = P1.getGlobalBounds();

  float media = Pc.height / 6;

  pies = y + Pc.height;
  
  sf::FloatRect tamP(x,pies-media ,Pc.width/2,media);

    sf::FloatRect ob = J1.getGlobalBounds();
    sf::Vector2f pos = J1.getPosition();
    base = pos.y +ob.height;

    float mediaOb = ob.height / 4;
    sf::FloatRect obP(pos.x, base - mediaOb ,ob.width/2,mediaOb);

      if(obP.intersects(tamP))
        return true;
  
  
return false;

}  

bool colisiones::colicionD(sf::Sprite P,int x, int y)
{
  
  float inferior,derecho;
  float tam,pies,base;
  sf::FloatRect Pc = P.getGlobalBounds();

  float media = Pc.height / 6;

  pies = y + Pc.height;
  
  sf::FloatRect tamP(x,pies-media ,Pc.width/2,media);

 
  for (int i = 0; i < 3; ++i)
  {

    sf::FloatRect ob = Sobjetos[i].getGlobalBounds();
    sf::Vector2f pos = Sobjetos[i].getPosition();
    base = pos.y +ob.height;

    float mediaOb = ob.height / 4;
    sf::FloatRect obP(pos.x, base - mediaOb ,ob.width/2,mediaOb);

      if(obP.intersects(tamP))
        return true;
  
  }
return false;
  
}  

bool colisiones::colicionI(sf::Sprite P,int x, int y)
{
  
  float inferior,derecho;
  float tam,pies,base;
  sf::FloatRect Pc = P.getGlobalBounds();

  Pc.left; 
   Pc.top;

  Pc.width;//ancho 
   Pc.height;//alto
  float media = Pc.height / 6;
  pies = y + Pc.height;
  derecho = Pc.left + Pc.width;
  inferior = Pc.top + Pc.height;
  
  sf::FloatRect tamP(x,pies-media ,Pc.width/2,media);
 
  for (int i = 0; i < 3; ++i)
  {

    sf::FloatRect ob = Sobjetos[i].getGlobalBounds();
    sf::Vector2f pos = Sobjetos[i].getPosition();
    base = pos.y +ob.height;

    float mediaOb = ob.height / 4;
    sf::FloatRect obP(pos.x + ob.width/4, base - mediaOb ,ob.width/2,mediaOb);

      if(obP.intersects(tamP))
        return true;
  
  }

  return false;
}


bool colisiones::colicionInf(sf::Sprite P,int x, int y)
{
  
  float inferior,derecho;
  float tam,pies,base;
  sf::FloatRect Pc = P.getGlobalBounds();

  Pc.left; 
   Pc.top;

  Pc.width;//ancho 
   Pc.height;//alto
  float media = Pc.height / 6;
  pies = y + Pc.height;
  derecho = Pc.left + Pc.width;
  inferior = Pc.top + Pc.height;
  
  sf::FloatRect tamP(x,pies-media ,Pc.width/2,media);
 
  for (int i = 0; i < 3; ++i)
  {

    sf::FloatRect ob = Sobjetos[i].getGlobalBounds();
    sf::Vector2f pos = Sobjetos[i].getPosition();
    base = pos.y +ob.height;

    float mediaOb = ob.height / 4;
    sf::FloatRect obP(pos.x + ob.width/4, pos.y ,ob.width/2,mediaOb);

      if(obP.intersects(tamP))
        return true;
  
  }
return false;
  
}



bool colisiones::colicionS(sf::Sprite P,int x, int y)
{
  
  float inferior,derecho;
  float tam,pies,base;
  sf::FloatRect Pc = P.getGlobalBounds();

  Pc.left; 
   Pc.top;

  Pc.width;//ancho 
   Pc.height;//alto
  float media = Pc.height / 6;
  pies = y + Pc.height;
  derecho = Pc.left + Pc.width;
  inferior = Pc.top + Pc.height;
  
  sf::FloatRect tamP(x,pies-media ,Pc.width/2,media);
 
  for (int i = 0; i < 3; ++i)
  {

    sf::FloatRect ob = Sobjetos[i].getGlobalBounds();
    sf::Vector2f pos = Sobjetos[i].getPosition();
    base = pos.y +ob.height;

    float mediaOb = ob.height / 6;
    sf::FloatRect obP(pos.x,(base - mediaOb)+10,ob.width/2,mediaOb);
    

      if(obP.intersects(tamP))
        return true;
  
  }
  return false;
}