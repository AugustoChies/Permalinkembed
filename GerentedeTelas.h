#pragma once
#include "Tela.h"
#include <stack>

using namespace std;

class GerentedeTelas
{
public:
	GerentedeTelas();
	~GerentedeTelas();
	void adicionar(Tela*);
	void remover();
	void exibir(Mapa * &mapa, Hud *hud);
protected:
	stack <Tela *> telas;
	
};

