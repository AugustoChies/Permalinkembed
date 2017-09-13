#pragma once
#include "Tela.h"
class TelaMenu:public Tela
{
public:
	TelaMenu();
	~TelaMenu();
	Tela* executar(Mapa * &mapa, Hud *hud);
protected:
	Sprite inicial;
	Botao *botoes;
};

