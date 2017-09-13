#include "Tanker.h"



Tanker::Tanker()
{
}


Tanker::~Tanker()
{
}

void Tanker::inicializar()
{
	inventario = new Inventario();
	nome = "Zerg";
	tipoClasse = 2;
	itematual = 0;
	pontmonstros = 0;
	vivo = true;
	podeatacar = true;
	gold = 0;
	dano = rand() % 11 + 2;
	maxhp = rand() % 11 + 2;
	hp = maxhp;
	maxrage = 10;
	rage = maxrage;
	defesa = 7;
	velocidade = 8;
	if (!gRecursos.carregouSpriteSheet("warrior"))
	{
		gRecursos.carregarSpriteSheet("warrior", "./imagens/tanker.png", 4, 4);
	}
	sprite.setSpriteSheet("warrior");
}

void Tanker::inicializarLoad()
{
	tipoClasse = 2;
	itematual = 0;
	vivo = true;
	velocidade = 8;
	if (!gRecursos.carregouSpriteSheet("warrior"))
	{
		gRecursos.carregarSpriteSheet("warrior", "./imagens/tanker.png", 4, 4);
	}
	sprite.setSpriteSheet("warrior");
}


void Tanker::finalizar()
{

}

void Tanker::atacar()
{

}

void Tanker::setEnergia(int r)
{
	rage = r;
}

void Tanker::setMaxenergia(int r)
{
	maxrage = r;
}

int Tanker::getEnergia()
{
	return rage;
}

int Tanker::getMaxenergia()
{
	return maxrage;
}
