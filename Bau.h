#ifndef BAU_H
#define BAU_H
#include "Mobilia.h"
#include "Item.h"
class Bau:public Mobilia
{
public:
	Bau();
	~Bau();
	void inicializar();
	void desenhar();
	void atualizar(TileMap*);
	Item* dropItem();
	int dropGold();
	bool getAberto();
	void setAberto(bool);

protected:
	bool aberto;
};
#endif
