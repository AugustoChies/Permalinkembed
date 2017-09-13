#include "Pistoleiro.h"



Pistoleiro::Pistoleiro()
{
}


Pistoleiro::~Pistoleiro()
{
}

void Pistoleiro::inicializar()
{
	inventario = new Inventario();
	nome = "Beebop";
	tipoClasse = 3;
	itematual = 0;
	pontmonstros = 0;
	vivo = true;
	podeatacar = true;
	gold = 0;
	dano = rand() % 11 + 2;
	maxhp = rand() % 11 + 2;
	maxammo = 10;
	ammo = maxammo;
	hp = maxhp;
	defesa = 7;
	velocidade = 12;
	if (!gRecursos.carregouSpriteSheet("cowboy"))
	{
		gRecursos.carregarSpriteSheet("cowboy", "./imagens/pistoleiro.png", 4, 4);
	}
	sprite.setSpriteSheet("cowboy");
}

void Pistoleiro::inicializarLoad()
{
	tipoClasse = 3;
	itematual = 0;
	vivo = true;
	velocidade = 12; 
	if (!gRecursos.carregouSpriteSheet("cowboy"))
	{
		gRecursos.carregarSpriteSheet("cowboy", "./imagens/pistoleiro.png", 4, 4);
	}
	sprite.setSpriteSheet("cowboy");
}

void Pistoleiro::finalizar()
{

}

void Pistoleiro::atacar()
{

}

void Pistoleiro::setEnergia(int a)
{
	ammo = a;
}

void Pistoleiro::setMaxenergia(int a)
{
	maxammo = a;
}

int Pistoleiro::getEnergia()
{
	return ammo;
}

int Pistoleiro::getMaxenergia()
{
	return maxammo;
}