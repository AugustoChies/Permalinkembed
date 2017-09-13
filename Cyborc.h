#pragma once
#include "Monstro.h"
class Cyborc:public Monstro
{
public:
	Cyborc();
	~Cyborc();
	void atualizar(TileMap *,Jogador *);
};

