#pragma once
#include "Tela.h"
class TelaLoad:public Tela
{
public:
	TelaLoad();
	~TelaLoad();
	Tela* executar(Mapa * &mapa, Hud *hud);

protected:
	Sprite selecao;
};

