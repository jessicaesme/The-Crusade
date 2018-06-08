#ifndef NODE_H
#define NODE_H 

#include <functional>
#include <iostream>

enum action {attac,walpos,walneg,idle};

using namespace std;


class node
{
	
private:
	node *l = nullptr;
	node *r = nullptr;
	int x,y,vida;
	int PersonX,PersonY,PersonVida;


public:
	node(){ }
	node(int X,int Y,int Vida){ x = X; y = Y; vida  = Vida;}
	~node(){
		if(l != nullptr)
			delete l;
		if(r != nullptr)
			delete r;
	}
	void insert_l(node *N){ if(l==nullptr) l = N;}
	void insert_r(node *N){ if(r==nullptr) r = N;}
	node* get_l()const{return l;}
  	node* get_r()const{return r;}

  	void setDataPerson(int X,int Y ,int Vida)
  	{
  		this->PersonX = X;
  		this->PersonY = Y; 
  		this->PersonVida  = Vida;
  	}
  	void setDataEnemy(int X,int Y ,int Vida){this->x = X; this->y = Y; this->vida  = Vida;}
	
  	int get_xPerson()const{return PersonX;}
	int get_yPerson()const{return PersonY;}
	int get_vidaPerson()const{return PersonVida;}
	

	int get_x()const{return x;}
	int get_y()const{return y;}
	int get_Vida()const{return vida;}
	void set_x(int X){ x = X;}	
	void set_y(int Y){ y = Y;}
	void set_vida(int V){vida = V;}

	virtual bool eval(){return false;}
	
	bool is_leaf()
	{
    if(l == nullptr and r == nullptr)
      return true;
    else
      return false;
  	}
};

class quest : public node 
{
private:
	function<bool(int,int,int,int,int,int)> fun;

public:
	quest(function<bool(int,int,int,int,int ,int )> f):fun(f){}

	~quest(){}


	bool eval()
	{
		return fun(get_x(),get_y(),get_xPerson(),get_yPerson(),get_Vida(),get_vidaPerson());
	}


};


class acionesEnemigo : public node
{
public:
	acionesEnemigo(action act){ A = act; }
	~acionesEnemigo();
	
  	action get_action() {return A;}


private:
 
 action A;

};

#endif