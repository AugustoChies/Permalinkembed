#include "Ataque.h"



Ataque::Ataque()
{
}


Ataque::~Ataque()
{
}

void Ataque::setObj(ObjetoTileMap* o)
{
	obj = o;
	obj->setSprite(&sprite);
	x = o->getPosCentro().x;
	y = o->getPosCentro().y;
}

ObjetoTileMap* Ataque::getObj()
{
	return obj;
}

void Ataque::setDano(int d)
{
	dano = d;
}
int Ataque::getDano()
{
	return dano;
}

void Ataque::desenhar()
{
	if (sprite.getSpriteSheet() != NULL)
	{
		sprite.desenhar(x, y);
	}
}

void Ataque::desenharConvert(TileMap * map)
{
	int xt, yt;
	map->tileParaTela(x,y,xt,yt);
	if (sprite.getSpriteSheet() != NULL)
	{
		sprite.desenhar(xt, yt);
	}
}

void Ataque::finalizar()
{

}

void Ataque::setX(float xo)
{
	x = xo;
}
void Ataque::setY(float yo)
{
	y = yo;
}
void Ataque::setSprite(Sprite s)
{
	sprite = s;
}

float Ataque::getX()
{
	return x;
}
Sprite Ataque::getSprite()
{
	return sprite;
}
float Ataque::getY()
{
	return y;
}

void Ataque::setAtivo(bool a)
{
	ativo = a;
}
bool Ataque::getAtivo()
{
	return ativo;
}

void Ataque::setDirecao(int d)
{
	direcao = d;
}
int Ataque::getDirecao()
{
	return direcao;
}