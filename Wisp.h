#pragma once
#include "Monstro.h"
class Wisp: public Monstro
{
public:
	Wisp();
	~Wisp();
	void atualizar(TileMap *, Jogador *);

private:
	int alea;
};

