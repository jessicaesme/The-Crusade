#include "juego.h"

juego::juego()
{
	this->x = 0;
	this->y = 310;

  this->enemyX = 500; 
  this->enemyY = 340; 

	this->SlimiteY = 290;
	this->IlimiteY = 480;

  P1.setDan(10);
	
  if (!buffer.loadFromFile("espada.wav"))
  {
    throw EXIT_FAILURE;
  }
  

  sonido.setBuffer(buffer);
  
  sonido.setVolume(100);

  if (!music.openFromFile("sonidosFondo/NG70107.ogg"))
    throw EXIT_FAILURE; 
  music.setLoop(true);


  int anchos[4] = {210,368,454,454};
  int altos[4] = {236,416,500,500};
  
  int anchosJ[3] = {210,362,362};
  int altosJ[3] = {236,432,432};
  
  P1.cargarVariable(anchos,altos,3);
  J1.cargarVariable(anchosJ,altosJ,3);

}

juego::~juego()
{

}

void  juego::CargarImagen()
{
std::string name;

   P1.CargarImagen("At",3);
   J1.CargarImagen("Enemy",3); 
   Cop.CargarImagen();

  if(!fondo.loadFromFile("imagenes/fond.png"))
     throw EXIT_FAILURE;

    Sfondo.setTexture(fondo);
  
   	fondo.setSmooth(true); 	

    Sfondo.setScale(sf::Vector2f(1.6f, 1.6f));


}

void juego::openW(sf::RenderWindow &window)
{
  int cantidad[3] = {7,4,3}; // cantidad de personajes en una imagen
  int cantidadJ[3] = {7,3,3}; 
  
  

	CargarImagen();	
  sf::Vector2i screenDimensions(1000,800);
  sf::Vector2f position(0, 0);

  view.reset(sf::FloatRect(0,0, 940, 800));
  view.setViewport(sf::FloatRect(0,0,1,1.3f));
  music.play();

	while (window.isOpen())
	{
    
    P1.setXY(x,y);
    J1.setXY(enemyX,enemyY);

	 	EventW1(window);

    if(P1.getSprite(0).getPosition().x + 5 <= 3000)
    {
      if(P1.getSprite(0).getPosition().x + 5 > screenDimensions.x /2) //Moviemiento a lo ancho
        position.x = P1.getSprite(0).getPosition().x +5;

      else
        position.x = screenDimensions.x / 2;
    }

    if(P1.getSprite(0).getPosition().y + 5 <= 1000)
    {
      if(P1.getSprite(0).getPosition().y + 5 > screenDimensions.y /2) //Moviemiento arriba abajo
        position.y = P1.getSprite(0).getPosition().y +5;

      else
        position.y = screenDimensions.y / 2;
    }

    view.setCenter(position);
    
    window.setView(view);
    
    for (int i = 0; i < 3; ++i)
       if (P1.getActivadores(i))
          P1.animar(window,i,cantidad[i]);


    for (int i = 0; i < 3; ++i)
       if (J1.getActivadores(i))
          J1.animar(window,i,cantidadJ[i]);

   
   if(J1.getVidas() > 5 )
   {

    time1 = clock.getElapsedTime();
    sf::Time t1 = sf::milliseconds(800);

    if (time1.asMilliseconds() > t1.asMilliseconds())
    {
      enemyAction();
      clock.restart();
    }
   
   }     


    if (P1.getVidas() < 5 )
    {
      music.stop();
      M.Mwindow(window,x,y);
    }

    Dibujar1(window);	
     		   	

	}
	
}

void juego::EventW1(sf::RenderWindow &window)
{
  bool SpritesColision = false ;

	  while (window.pollEvent(event))
      {
        SpritesColision = Cop.ColSprites(P1.getSprite(0),J1.getSprite(0),x,y);

          if (event.type == sf::Event::Closed)
              window.close();


          if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) )
                 window.close(); 

          if (sf::Keyboard::isKeyPressed(sf::Keyboard::X) )
          {
                sonido.play();
               P1.setActivadores(1 ,true);
          }    

          if (sf::Keyboard::isKeyPressed(sf::Keyboard::C) )
          {
                sonido.play();
              P1.setActivadores(2 ,true);
          }    

           if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) )
            {
              P1.setIzquierda(false);
            	P1.setActivadores(0 ,true);
            
            if ( x < (2000) and Cop.colicionD(P1.getSprite(0),x,y) != true)
            	x  += 5; 
         
            }


          if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) )
          {
            P1.setIzquierda(true);
              P1.setActivadores(0 ,true);
             if( (x > 0 ) and Cop.colicionI(P1.getSprite(0),x,y) != true )
                x  -= 5;
           }


          if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) )
          {
            P1.setActivadores(0 ,true);
              if (y > SlimiteY  and Cop.colicionS(P1.getSprite(0),x,y) != true )
                 y  -= 5;

          } 

          if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) )
           {
            P1.setActivadores(0 ,true);
              if ( y < IlimiteY and Cop.colicionInf(P1.getSprite(0),x,y) != true )
                 y  += 5;
          }



      }

}


void juego::Dibujar1(sf::RenderWindow &window)
{

	
	window.clear();

  if(J1.getVidas() < 5 )
  J1.Dibujar(window);    
    		
	window.draw(Sfondo);
  
  Cop.DibujarOb(window,1);   

  Cop.DibujarOb(window,0);   

  Cop.DibujarOb(window,2);   


  if(J1.getVidas() > 5 )
    J1.Dibujar(window);    
  
  P1.Dibujar(window);    
  
	window.display();
		

}


void juego::enemyAction()
{

  bool SpritesColision = Cop.ColSprites(P1.getSprite(0),J1.getSprite(0),x,y);
  int Disty= y - enemyY;
  int Distx= x - enemyX;
  J1.inteligencia();
  J1.insertVariables(enemyX, enemyY,J1.getVidas(), x,y,P1.getVidas());

  action act = J1.Compare(J1.getRoot());
  sf::FloatRect P = P1.getSprite(0).getGlobalBounds();
  sf::FloatRect J = J1.getSprite(0).getGlobalBounds();

  bool intersec = P.intersects(J);

  if (act == action::walpos)
  {
      if (x < enemyX)
      {

        J1.setIzquierda(true);
        J1.setActivadores(0 ,true);
        if (Cop.colicionI(J1.getSprite(0),enemyX,enemyY) != true)
         enemyX -= 20;
        else
          if (Cop.colicionS(J1.getSprite(0),enemyX,enemyY) != true)
          enemyY += 20;
            else
              enemyY -= 20;

      }else
      {
        J1.setIzquierda(false);
        J1.setActivadores(0 ,true);
        if (Cop.colicionI(J1.getSprite(0),enemyX,enemyY) != true)
         enemyX += 20;
        else
          if (Cop.colicionS(J1.getSprite(0),enemyX,enemyY) != true)
          enemyY += 20;
            else
              enemyY -= 20;

      }
      
  }

  

  if ( Disty > 10 and Cop.colicionI(J1.getSprite(0),enemyX,enemyY) != true)
    enemyY+=2;
  if ( Disty < 10 and Cop.colicionS(J1.getSprite(0),enemyX,enemyY) != true)
    enemyY-=2;

  
  if (act == action::attac)
    J1.setActivadores(2 ,true);
      

  
  if (act == action::attac and SpritesColision == true)
  {
    P1.setVidas(P1.getVidas() - J1.getDan());
  }

  if ( (P1.getActivadores(1) == true or P1.getActivadores(2) == true) and SpritesColision == true)
      J1.setVidas(J1.getVidas() - P1.getDan());
        


    sleep(0.99);

}


void aparecerEnemigos()
{
  
}
