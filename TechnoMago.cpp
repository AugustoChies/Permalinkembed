#include "TechnoMago.h"



TechnoMago::TechnoMago()
{
}


TechnoMago::~TechnoMago()
{
}

void TechnoMago::inicializar()
{
	inventario = new Inventario();
	nome = "Eixtainm";
	tipoClasse = 1;
	itematual = 0;
	pontmonstros = 0;
	vivo = true;
	podeatacar = true;
	gold = 0;
	dano = rand() % 11 + 2;
	maxhp= rand() % 11 + 2;
	hp = maxhp;
	maxmana = 10;
	mana = maxmana;
	defesa = 7;
	velocidade = 10;
	if (!gRecursos.carregouSpriteSheet("implacavel"))
	{
		gRecursos.carregarSpriteSheet("implacavel", "./imagens/mago.png", 4, 4);
	}
	sprite.setSpriteSheet("implacavel");
}

void TechnoMago::inicializarLoad()
{
	tipoClasse = 1;
	itematual = 0;
	vivo = true;
	velocidade = 10;
	if (!gRecursos.carregouSpriteSheet("implacavel"))
	{
		gRecursos.carregarSpriteSheet("implacavel", "./imagens/mago.png", 4, 4);
	}
	sprite.setSpriteSheet("implacavel");
}



void TechnoMago::finalizar()
{

}

void TechnoMago::atacar()
{

}

void TechnoMago::setEnergia(int m)
{
	mana = m;
}

void TechnoMago::setMaxenergia(int m)
{
	maxmana = m;
}

int TechnoMago::getEnergia()
{
	return mana;
}

int TechnoMago::getMaxenergia()
{
	return maxmana;
}
