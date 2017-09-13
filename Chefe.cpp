#include "Chefe.h"



Chefe::Chefe()
{
}


Chefe::~Chefe()
{
}

void Chefe::atualizar(TileMap * map, Jogador * j)
{
	if (vivo)
	{
		obj->setPosCentro(x, y);
		//desenhar();
		sprite.avancarAnimacao();

		if (map->tileECaminhavel(x + 1.6, y) && j->getX() > x && !(j->getX() - x < 0.3))
		{
			
			x += 0.03;
		}

		else if (map->tileECaminhavel(x, y + 1.6) && j->getY() > y)
		{
			
			y += 0.03;
		}

		else if (map->tileECaminhavel(x - 1.6, y) && j->getX() < x && !(x - j->getX() < 0.3))
		{
			
			x -= 0.03;
		}
		else if (map->tileECaminhavel(x, y - 1.1) && j->getY() < y)
		{
			
			y -= 0.03;
		}

		if (invencivel)
		{
			invencitime++;
			if (invencitime > 50)
			{
				invencivel = false;
				invencitime = 0;
			}
		}

		if (hp <= 0)
		{
			vivo = false;
			obj->setVisivel(false);
		}
	}
}
