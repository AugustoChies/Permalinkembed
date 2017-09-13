#pragma once
#include "Monstro.h"
class Aranha: public Monstro
{
public:
	Aranha();
	~Aranha();
	void atualizar(TileMap *,Jogador *);
	
};

