#include "Monstro.h"



Monstro::Monstro()
{
	invencitime = 0;
}


Monstro::~Monstro()
{
}

void Monstro::setId(int i)
{
	id = i;
}
int Monstro::getId()
{
	return id;
}

void Monstro::inicializar()
{
	int i;
	char buffer[50];
	ifstream arq("monstros.txt");
	{
		while (true)
		{
			arq >> buffer;
			if (buffer[0] == '*')
			{
				i = buffer[1] - '0';
				if (i == id)
					break;
			}
		}
		arq >> nome;
		arq >> dano;
		arq >> defesa;
		arq >> maxhp;
		hp = maxhp;
		sprite.setSpriteSheet(nome);
		velocidade = 10;
		vivo = true;
		arq.close();
	}
}

void Monstro::inicializarLoad()
{
	sprite.setSpriteSheet(nome);
	velocidade = 10;
}

void Monstro::desenhar()
{
	if (sprite.getSpriteSheet() != NULL)
	{
		sprite.desenhar(x, y);
	}
}

void Monstro::atualizar(TileMap * m)
{

}

void Monstro::finalizar()
{

}