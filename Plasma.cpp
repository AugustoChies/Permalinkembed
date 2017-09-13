#include "Plasma.h"



Plasma::Plasma()
{
}


Plasma::~Plasma()
{
}

void Plasma::inicializar()
{
	sprite.setSpriteSheet("plasma");
	ativo = true;
	timerativo = 0;
}

void Plasma::atualizar(TileMap * map)
{
	if (ativo)
	{
		desenharConvert(map);
		sprite.avancarAnimacao();

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
				x -= 0.09;
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
