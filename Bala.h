#pragma once
#include "Ataque.h"
class Bala:public Ataque
{
	const int CIMA = 1;
	const int DIREITA = 2;
	const int BAIXO = 3;
	const int ESQUERDA = 4;
public:
	Bala();
	~Bala();
	void inicializar();
	void atualizar(TileMap*);

};

