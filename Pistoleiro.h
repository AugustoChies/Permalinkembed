#pragma once
#include "Jogador.h"
class Pistoleiro:public Jogador
{
public:
	Pistoleiro();
	~Pistoleiro();
	void inicializar();
	void inicializarLoad();
	void finalizar();
	void atacar();
	void setEnergia(int);
	void setMaxenergia(int);
	int getEnergia();
	int getMaxenergia();

protected:
	int ammo, maxammo;
};

