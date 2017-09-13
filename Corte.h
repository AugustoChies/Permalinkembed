#pragma once
#include "Ataque.h"
class Corte:public Ataque
{
	const int CIMA = 1;
	const int DIREITA = 2;
	const int BAIXO = 3;
	const int ESQUERDA = 4;
public:
	Corte();
	~Corte();
	void inicializar();
	void atualizar(TileMap*);
};

