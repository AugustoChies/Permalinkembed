#include "Bau.h"



Bau::Bau()
{
	aberto = false;
}


Bau::~Bau()
{
}

void Bau::inicializar()
{
	if (!gRecursos.carregouSpriteSheet("bauteste"))
	{
		gRecursos.carregarSpriteSheet("bauteste", "./imagens/bau.png", 2, 1);
	}
	sprite.setSpriteSheet("bauteste");
}

void Bau::desenhar()
{
	sprite.desenhar(x, y);
}

void Bau::atualizar(TileMap*)
{
	if (aberto)
	{
		sprite.setAnimacao(1);
	}
	obj->setPosCentro(x, y);
}

Item* Bau::dropItem()
{
	aberto = true;
	Item *item=new Item;
	item->inicializar();
	return item;
}

int Bau::dropGold()
{
	aberto = true;
	return (rand() % 6 + 1) * 1000;
}

bool Bau::getAberto()
{
	return aberto;
}

void Bau::setAberto(bool a)
{
	aberto = a;
}
