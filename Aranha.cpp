#include "Aranha.h"



Aranha::Aranha()
{
}


Aranha::~Aranha()
{
}

void Aranha::atualizar(TileMap * map ,Jogador *j)
{
	if (vivo)
	{
		obj->setPosCentro(x, y);
	//	desenhar();
		sprite.avancarAnimacao();

	//	if (j-> getX() - x > 1 && x - j->getX() < 1 || j->getY() -y > -1 && y - j->getY() < 1)
	//	{
			if (map->tileECaminhavel(x + 0.6, y) && j->getX() > x && !(j->getX() - x < 0.3))
			{
				x += 0.05;
			}

			else if (map->tileECaminhavel(x, y + 0.6) && j->getY() > y)
			{
				y += 0.05;
			}

			else if (map->tileECaminhavel(x - 0.6, y) && j->getX() < x && !(x - j->getX() < 0.3))
			{
				x -= 0.05;
			}
			else if (map->tileECaminhavel(x, y - 0.1) && j->getY() < y)
			{
				y -= 0.05;
			}
			
	//	}
		
			if (invencivel)
			{
				invencitime++;
				if (invencitime > 50)
				{
					invencivel = false;
					invencitime = 0;
				}
			}

			if (hp <=0)
			{
				vivo = false;
				obj->setVisivel(false);
			}
	
	}
}
