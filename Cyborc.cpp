#include "Cyborc.h"



Cyborc::Cyborc()
{
}


Cyborc::~Cyborc()
{
}

void Cyborc::atualizar(TileMap * map,Jogador * j)
{
	if (vivo)
	{
		obj->setPosCentro(x, y);
		//desenhar();
		sprite.avancarAnimacao();

		if (map->tileECaminhavel(x + 0.6, y) && j->getX() > x && !(j->getX() - x < 0.3))
		{
			sprite.setAnimacao(1);
			x += 0.03;
		}

		else if (map->tileECaminhavel(x, y + 0.1) && j->getY() > y)
		{
			sprite.setAnimacao(0);
			y += 0.03;
		}

		else if (map->tileECaminhavel(x - 0.6, y) && j->getX() < x && !(x - j->getX() < 0.3))
		{
			sprite.setAnimacao(2);
			x -= 0.03;
		}
		else if (map->tileECaminhavel(x, y - 0.1) && j->getY() < y)
		{
			sprite.setAnimacao(3);
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
