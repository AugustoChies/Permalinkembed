#pragma once
#include "Ataque.h"
class Plasma :public Ataque
{
	const int CIMA = 1;
	const int DIREITA = 2;
	const int BAIXO = 3;
	const int ESQUERDA = 4;
public:
	Plasma();
	~Plasma();
	void inicializar();
	void atualizar(TileMap*);
};

