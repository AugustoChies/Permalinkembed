#include "Porta.h"



Porta::Porta()
{
}


Porta::~Porta()
{
}

void Porta::inicializar()
{
	if (!gRecursos.carregouSpriteSheet("porta"))
	{
		gRecursos.carregarSpriteSheet("porta", "./imagens/porta.png", 1, 1);
	}
	sprite.setSpriteSheet("porta");
	x = 575;
	y = 70;
}

void Porta::desenhar()
{
	sprite.desenhar(x, y);
}

void Porta::atualizar(TileMap*)
{

}

void Porta::finalizar()
{

}


void Porta::setX(float x)
{
	this->x = x;
}

void Porta::setY(float y)
{
	this->y = y;
}

void Porta::setSprite(Sprite s)
{
	sprite = s;
}

void Porta::setDestino(int des)
{
	destino = des;
}

void Porta::setObj(ObjetoTileMap* o)
{
	obj = o;
	obj->setSprite(&sprite);
	x = o->getPosCentro().x;
	y = o->getPosCentro().y;
}

float Porta::getX()
{
	return x;
}

Sprite Porta::getSprite()
{
	return sprite;
}

float Porta::getY()
{
	return y;
}

int Porta::getDestino()
{
	return destino;
}

ObjetoTileMap* Porta::getObj()
{
	return obj;
}


float Porta::getLargura()
{
	return sprite.getLargura();
}

float Porta::getAltura()
{
	return sprite.getAltura();
}