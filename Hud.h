#ifndef HUD_H
#define HUD_H
#include "Jogador.h"
class Hud
{
public:
	Hud();
	~Hud();
	void inicializar();
	void escreveStats(Jogador*);
	void escreveGold(Jogador*);
	void escreveItem(Jogador*);
	void escreverGeral(Jogador*);

protected:
	Texto tstats, tgold, titem;
	Item *item;
};

#endif

