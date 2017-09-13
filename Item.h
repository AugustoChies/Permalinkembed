#ifndef ITEM_H
#define ITEM_H
#include "Entidade.h"
class Item:public Entidade
{
public:
	Item();
	~Item();
	void inicializar();
	void inicializarLoad();
	void desenhar();
	void atualizar(TileMap*);
	void finalizar();
	void setX(float);
	void setY(float);
	void setSprite(Sprite);
	void setNome(string);
	void setVisivel(bool);
	void setAtbonus(int);
	void setDefbonus(int);
	void setHpbonus(int);
	float getX();
	Sprite getSprite();
	float getY();
	string getNome();
	bool getVisivel();
	int getAtbonus();
	int getDefbonus();
	int getHpbonus();

	

protected:
	string nome;
	bool visivel;
	int atbonus, defbonus, hpbonus;

};
#endif

