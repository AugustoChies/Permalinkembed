#pragma once
#include "Tela.h"

class TelaRank:public Tela
{
public:
	TelaRank();
	~TelaRank();
	Tela* executar(Mapa * &mapa, Hud *hud);
protected:
	Sprite inicial;
	Botao *botoes;
	bool once;
	string text;
	Texto tpontuacao;
};

