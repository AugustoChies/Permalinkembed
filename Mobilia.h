#ifndef MOB_H
#define MOB_H
#include "Entidade.h"
class Mobilia:public Entidade
{
public:
	Mobilia();
	~Mobilia();
	void inicializar();
	void desenhar();
	void atualizar(TileMap*);
	void finalizar();
	void setX(float);
	void setY(float);
	void setSprite(Sprite);
	void setObj(ObjetoTileMap*);
	float getX();
	Sprite getSprite();
	float getY();
	ObjetoTileMap* getObj();
	float getLargura();
	float getAltura();

protected:
	ObjetoTileMap *obj;
};
#endif

