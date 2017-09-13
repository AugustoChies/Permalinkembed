#ifndef MAGO_H

#define MAGO_H
#include "Jogador.h"

class TechnoMago:public Jogador
{
public:
	TechnoMago();
	~TechnoMago();
	void inicializar();
	void inicializarLoad();
	void finalizar();
	void atacar();
	void setEnergia(int);
	void setMaxenergia(int);
	int getEnergia();
	int getMaxenergia();

protected:
	int mana, maxmana;
};
#endif

