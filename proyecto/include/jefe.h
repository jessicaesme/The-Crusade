#ifndef JEFE_H
#define JEFE_H 
#include <node.h>
#include <personaje.h>

class jefe : public personaje
{
private:
	node *Node[9]; 

public:
	jefe();
	~jefe();
	
	void inteligencia();

	void insertVariables(int X, int Y,int Z, int C,int vida,int VIDA);

	node * getRoot();

	action Compare(node* root);

};


bool distancia(int X, int Y,int Z, int C,int vida,int VIDA)  ;
bool ifvida(int X, int Y,int Z, int C,int vida,int VIDA) ;
bool retroceder(int X, int Y,int Z, int C,int vida,int VIDA) ;

#endif