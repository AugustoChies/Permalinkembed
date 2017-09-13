#pragma once
#include "Mapa.h"
#include "Hud.h"
#include "Botao.h"
#include "Arquivo.h"
class Tela
{
public:
	Tela();
	~Tela();
	virtual Tela* executar(Mapa * &mapa,Hud *hud)=0;
};

