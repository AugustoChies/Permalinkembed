#pragma once
#include "Monstro.h"
class Chefe:public Monstro
{
public:
	Chefe();
	~Chefe();
	void atualizar(TileMap *, Jogador *);
};

