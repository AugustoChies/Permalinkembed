#include "Wisp.h"



Wisp::Wisp()
{
	movendo = false;
	timermovendo = 0;
	timerpramover = 0;
}


Wisp::~Wisp()
{
}

void Wisp::atualizar(TileMap * map, Jogador * j)
{
	if (vivo)
	{
		obj->setPosCentro(x, y);
		//desenhar();
		sprite.avancarAnimacao();

	
	
		if (hp == maxhp)
		{
			if (!movendo)
			{
				timerpramover++;
				if (timerpramover > 100)
				{
					movendo = true;
					alea = rand() % 4;
					timerpramover = 0;
				}
			}
			if (movendo)
			{
				timermovendo++;
				if (timermovendo > 200)
				{
					movendo = false;
					timermovendo = 0;
				}
			}
			if (movendo)
			{
				switch (alea)
				{
				case 0:
					if (map->tileECaminhavel(x + 0.6, y))
					{
						x += 0.03;
					}
					break;
				case 1:
					if (map->tileECaminhavel(x, y + 0.1))
					{
						y += 0.03;
					}
					break;
				case 2:
					if (map->tileECaminhavel(x - 0.6, y))
					{
						x -= 0.03;
					}
					break;
				case 3:
					if (map->tileECaminhavel(x, y - 0.1))
					{
						y -= 0.03;
					}
					break;

				
				}
			}
		}
		else
		{
			if (map->tileECaminhavel(x + 0.6, y) && j->getX() > x && !(j->getX() - x < 0.3))
			{
				x += 0.04;
			}

			else if (map->tileECaminhavel(x, y + 0.6) && j->getY() > y)
			{
				y += 0.04;
			}

			else if (map->tileECaminhavel(x - 0.6, y) && j->getX() < x && !(x - j->getX() < 0.3))
			{
				x -= 0.04;
			}
			else if (map->tileECaminhavel(x, y - 0.1) && j->getY() < y)
			{
				y -= 0.04;
			}
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

