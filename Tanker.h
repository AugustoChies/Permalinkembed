#pragma once
#include "Jogador.h"
class Tanker:public Jogador
{
public:
	Tanker();
	~Tanker();
	void inicializar();
	void inicializarLoad();
	void finalizar();
	void atacar();
	void setEnergia(int);
	void setMaxenergia(int);
	int getEnergia();
	int getMaxenergia();

protected:
	int rage, maxrage;
};

