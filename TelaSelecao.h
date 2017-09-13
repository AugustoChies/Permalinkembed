#pragma once
#include "Tela.h"
class TelaSelecao: public Tela
{
public:
	TelaSelecao();
	~TelaSelecao();
	Tela* executar(Mapa * &mapa, Hud *hud);

protected:
	Sprite selecao;
};

