#include "jefe.h"

jefe::jefe()
{

}

jefe::~jefe()
{

}

node* jefe::getRoot()
{
	return Node[0];
}


void jefe::insertVariables(int Xenemy, int Yenemy,int enemyVida, int  Xperson,int Yperson,int personVida)
{
	Node[0]->setDataPerson(Xperson,Yperson,personVida);
	Node[0]->setDataEnemy(Xenemy,Yenemy,enemyVida);		

	Node[2]->setDataPerson(Xperson,Yperson,personVida);
	Node[2]->setDataEnemy(Xenemy,Yenemy,enemyVida);		

	Node[4]->setDataPerson(Xperson,Yperson,personVida);
	Node[4]->setDataEnemy(Xenemy,Yenemy,enemyVida);		

	Node[6]->setDataPerson(Xperson,Yperson,personVida);
	Node[6]->setDataEnemy(Xenemy,Yenemy,enemyVida);		
}

void jefe::inteligencia()
{

Node[0] = new quest(distancia);
Node[1] = new acionesEnemigo(action::walpos);
Node[0]->insert_r(Node[1]);

Node[2] = new quest(ifvida);
Node[0]->insert_l(Node[2]);
Node[3] = new acionesEnemigo(action::attac);
Node[2]->insert_r(Node[3]);

Node[4] = new quest(retroceder);
Node[2]->insert_l(Node[4]);
Node[5] = new acionesEnemigo(action::walneg);
Node[4]->insert_r(Node[5]);

Node[6] = new quest(distancia);
Node[4]->insert_l(Node[6]);
Node[7] = new acionesEnemigo(action::walpos);
Node[8] = new acionesEnemigo(action::idle);
Node[6]->insert_l(Node[8]);
Node[6]->insert_r(Node[7]);
}

action jefe::Compare(node* root)
{
  if(root->is_leaf())
  {
  	 acionesEnemigo *ptr = static_cast<acionesEnemigo*>(root);
    return ptr->get_action();
  }

  if(root->eval())
    return Compare(root->get_r());
  else
    return Compare(root->get_l());
}



bool retroceder(int X, int Y,int Z, int C,int vida,int VIDA)
{
	int Distx= X - Z;
	int Disty= Y - C;
	
	if (Distx<0)
		Distx = Distx * -1;

	if (Disty<0)
		Disty = Disty * -1;


	if (Distx <= 80 )	
		return true;
	
	else 
		return false;

}


bool distancia(int X, int Y,int Z, int C,int vida,int VIDA)
{

	int Distx= X - Z;
	int Disty= Y - C;
	
	if (Distx<0)
		Distx = Distx * -1;

	if (Disty<0)
		Disty = Disty * -1;


	if (Distx >= 80 and Distx < 380)
		return true;
	else 
		return false;

}

bool ifvida(int X, int Y,int Z, int C,int vida,int VIDA)
{
	if (retroceder(X,Y,Z,C,vida,VIDA) == true)
		return true;
	return false;
}
