#include "Corte.h"



Corte::Corte()
{
}


Corte::~Corte()
{
}

void Corte::inicializar()
{
	sprite.setSpriteSheet("corte");
	ativo = true;
	timerativo = 0;
	sprite.setVelocidadeAnimacao(4);
}

void Corte::atualizar(TileMap * map)
{
	if (ativo)
	{
		desenharConvert(map);
		sprite.avancarAnimacao();
		
		timerativo++;
		if (timerativo >= 50)
		{
			ativo = false;
			timerativo = 0;
		}
	}
}
