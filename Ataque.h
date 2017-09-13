#pragma once
#include "Entidade.h"
class Ataque:public Entidade
{
public:
	Ataque();
	~Ataque();
	void setObj(ObjetoTileMap*);
	ObjetoTileMap* getObj();
	void setDano(int);
	int getDano();
	void desenhar();
	void desenharConvert(TileMap *);
	void finalizar();
	void setX(float);
	void setY(float);
	void setSprite(Sprite);
	float getX();
	Sprite getSprite();
	float getY();
	void setAtivo(bool);
	bool getAtivo();
	void setDirecao(int);
	int getDirecao();
protected:
	ObjetoTileMap *obj;
	int dano,timerativo,direcao;
	bool ativo;
};

