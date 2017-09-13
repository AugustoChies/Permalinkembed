#ifndef INVENTORY
#define INVENTORY
#include "Item.h"
#include <list>

class Inventario
{
public:
	Inventario();
	~Inventario();
	void adicionarItem(Item*);
	void deletarItem(Item*);
	Item *localizarItem(int);
	int getTam();

protected:
	list<Item*> itens;
	list<Item*>::iterator i,j;	

};
#endif
