#pragma once
#include "Tela.h"
class TelaJogo: public Tela

{
public:
	TelaJogo();
	~TelaJogo();
	Tela* executar(Mapa * &mapa, Hud *hud);
};

