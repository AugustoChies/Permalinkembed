#include "Personagem.h"



Personagem::Personagem()
{
	invencivel = false;
}


Personagem::~Personagem()
{
}

void Personagem::setNome(string n)
{
	nome = n;
}
void Personagem::setHp(float h)
{
	hp = h;
}
void Personagem::setHpmax(float hm)
{
	maxhp = hm;
}
void Personagem::setVivo(bool v)
{
	vivo = v;
}
void Personagem::setDano(int d)
{
	dano = d;
}
void Personagem::setDefesa(int d)
{
	defesa = d;
}
void Personagem::setVelocidade(int v)
{
	velocidade = v;
}
void Personagem::setX(float x)
{
	this->x = x;
}

void Personagem::setY(float y)
{
	this->y = y;
}

void Personagem::setSprite(Sprite s)
{
	sprite = s;
}

void Personagem::setObj(ObjetoTileMap* o)
{
	obj = o;
	obj->setSprite(&sprite);
	x = o->getPosCentro().x;
	y = o->getPosCentro().y;
}

void Personagem::setInvencivel(bool i)
{
	invencivel = i;
}

string Personagem::getNome()
{
	return nome;
}
float Personagem::getHp()
{
	return hp;
}
float Personagem::getHpmax()
{
	return maxhp;
}
bool Personagem::getVivo()
{
	return vivo;
}
int Personagem::getDano()
{
	return dano;
}
int Personagem::getDefesa()
{
	return defesa;
}
int Personagem::getVelocidade()
{
	return velocidade;
}

int Personagem::getMovimento()
{
	return movendo;
}

int Personagem::getDirecao()
{
	return direcao;
}

float Personagem::getX()
{
	return x;
}

Sprite Personagem::getSprite()
{
	return sprite;
}

float Personagem::getY()
{
	return y;
}

ObjetoTileMap* Personagem::getObj()
{
	return obj;
}

float Personagem::getLargura()
{
	return sprite.getLargura();
}

float Personagem::getAltura()
{
	return sprite.getAltura();
}

bool Personagem::getInvencivel()
{
	return invencivel;
}

void Personagem::tomarDano(int damage)
{
	damage = damage - defesa;
	if (damage <= 0)
		damage = 1;
	hp -= damage;
	invencivel = true;
}