#pragma once
#include "Entidade.h"
class Porta:public Entidade
{
public:
	Porta();
	~Porta();
	void inicializar();
	void desenhar();
	void atualizar(TileMap*);
	void finalizar();
	void setX(float);
	void setY(float);
	void setSprite(Sprite);
	void setDestino(int);
	void setObj(ObjetoTileMap*);
	float getX();
	Sprite getSprite();
	float getY();
	int getDestino();
	ObjetoTileMap* getObj();
	float getLargura();
	float getAltura();

protected:
	int destino;
	ObjetoTileMap *obj;
};

