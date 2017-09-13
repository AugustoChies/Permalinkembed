#include "Bala.h"



Bala::Bala()
{
}


Bala::~Bala()
{
}


void Bala::inicializar()
{
	sprite.setSpriteSheet("bala");
	ativo = true;
	timerativo = 0;
}

void Bala::atualizar(TileMap * map)
{
	if (ativo)
	{
		desenharConvert(map);

		if (direcao == CIMA)
		{
			if (map->tileECaminhavel(x, y - 0.1))
			{
				y -= 0.09;
			}
			else
			{
				ativo = false;
				timerativo = 0;
			}
		}
		else if (direcao == BAIXO)
		{
			if (map->tileECaminhavel(x, y + 0.1))
			{
				y += 0.09;
			}
			else
			{
				ativo = false;
				timerativo = 0;
			}
		}
		else if (direcao == ESQUERDA)
		{
			if (map->tileECaminhavel(x - 0.1, y))
			{
				x  -= 0.09;
			}
			else
			{
				ativo = false;
				timerativo = 0;
			}
		}
		else if (direcao == DIREITA)
		{
			if (map->tileECaminhavel(x + 0.1, y))
			{
				x += 0.09;
			}
			else
			{
				ativo = false;
				timerativo = 0;
			}
		}


		timerativo++;
		if (timerativo >= 100)
		{
			ativo = false;
			timerativo = 0;
		}
	}
}

