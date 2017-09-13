#pragma once
#include "Tela.h"
class TelaWin:public Tela
{
public:
	TelaWin();
	~TelaWin();
	Tela* executar(Mapa * &mapa, Hud *hud);
protected:
	Sprite inicial;
	Botao *botoes;
	bool once;
};

