#include "Inventario.h"



Inventario::Inventario()
{

}


Inventario::~Inventario()
{
}

void Inventario::adicionarItem(Item *item)
{
	if (itens.size() < 10)
	{
		itens.push_back(item);
	}
}

void Inventario::deletarItem(Item *item)
{
	j = itens.end();
	for (i = itens.begin(); i != itens.end(); i++)
	{
		if ((*i)->getNome() == item->getNome())
		{
			j = i;
			break;
		}
	}
	if (j != itens.end())
	{
		itens.erase(j);
	}
}

Item* Inventario::localizarItem(int quant)
{
	i = itens.begin();
	for (int k=0; k < quant; k++)
	{
		if (quant != 0)
		{
			i++;
		}
	}
	return *i;
}

int Inventario::getTam()
{
	return itens.size();
}

