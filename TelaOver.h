#pragma once
#include "Tela.h"
class TelaOver:public Tela
{
public:
	TelaOver();
	~TelaOver();
	Tela* executar(Mapa * &mapa, Hud *hud);
protected:
	Sprite inicial;
	Botao *botoes;
};

