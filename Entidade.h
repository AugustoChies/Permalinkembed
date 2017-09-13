#ifndef ENTI_H
#define ENTI_H
#include "libUnicornio.h"
#include <fstream>
#include <ctime>
class Entidade
{
public:
	Entidade() {};
	~Entidade() {};
	virtual void inicializar() = 0;
	virtual void desenhar() = 0;
	virtual void atualizar(TileMap*) = 0;
	virtual void finalizar() = 0;
	virtual void setX(float) = 0;
	virtual void setY(float) = 0;
	virtual void setSprite(Sprite) = 0;
	virtual float getX() = 0;
	virtual Sprite getSprite() = 0;
	virtual float getY() = 0;

protected:
	Sprite sprite;
	float x, y;
};
#endif

