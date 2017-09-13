#include "Mobilia.h"



Mobilia::Mobilia()
{
}


Mobilia::~Mobilia()
{
}

void Mobilia::inicializar()
{

}

void Mobilia::desenhar()
{

}

void Mobilia::atualizar(TileMap*)
{

}

void Mobilia::finalizar()
{

}

void Mobilia::setX(float x)
{
	this->x = x;
}

void Mobilia::setY(float y)
{
	this->y = y;
}

void Mobilia::setSprite(Sprite s)
{
	sprite = s;
}

void Mobilia::setObj(ObjetoTileMap* o)
{
	obj = o;
	obj->setSprite(&sprite);
	x = o->getPosCentro().x;
	y = o->getPosCentro().y;
}

float Mobilia::getX()
{
	return x;
}

Sprite Mobilia::getSprite()
{
	return sprite;
}

float Mobilia::getY()
{
	return y;
}

ObjetoTileMap* Mobilia::getObj()
{
	return obj;
}


float Mobilia::getLargura()
{
	return sprite.getLargura();
}

float Mobilia::getAltura()
{
	return sprite.getAltura();
}