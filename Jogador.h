#ifndef JOGADOR_H
#define JOGADOR_H
#include "Personagem.h"
#include "Inventario.h"
#include "Bala.h"
#include "Plasma.h"
class Jogador:public Personagem
{
public:
	Jogador();
	~Jogador();
	void setInventario(Inventario *);
	void setGold(int);
	void setTipoclasse(int);
	void setItematual(int ia);
	void setPontMonstros(int);
	void setPontTotal(int);
	int getPonttotal();
	int getPontMonstros();
	bool getPodeAtacar();
	Inventario* getInventario();
	int getGold();
	int getItematual();
	int getTipoclasse();
	void usarItem();
	void desenhar();
	void atualizar(TileMap *map);
	void addItem(Item *);
	Ataque* atacar();
	virtual void setEnergia(int) = 0;
	virtual void setMaxenergia(int) = 0;
	virtual int getEnergia()=0;
	virtual int getMaxenergia() = 0;
	virtual void inicializarLoad() = 0;

protected:
	Inventario *inventario;
	int gold, tipoClasse;
	int itematual,pontmonstros,ponttotal;
	int hpregen,attacktimer;
	bool podeatacar;



};
#endif;

