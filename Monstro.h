#ifndef MONST_H
#define MONST_H
#include "Personagem.h"
#include "Jogador.h"
class Monstro:public Personagem
{
public:
	Monstro();
	~Monstro();
	void inicializar();
	void inicializarLoad();
	void atualizar(TileMap *);
	virtual void atualizar(TileMap *, Jogador *)=0;
	void desenhar();
	void finalizar();
	void setId(int i);
	int getId();

protected:
	int id, timerpramover,timermovendo;
	bool movendo, parado;
};
#endif

