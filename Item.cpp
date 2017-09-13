#include "Item.h"



Item::Item()
{
}


Item::~Item()
{
}

void Item::inicializar()
{
	int tamanho,id,i;
	char buffer[50];
	ifstream arq("itens.txt");
	arq >> tamanho;
	id = rand()%tamanho;
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
	arq >> atbonus;
	arq >> defbonus;
	arq >> hpbonus;
	sprite.setSpriteSheet(nome);
	arq.close();
}

void Item::inicializarLoad()
{
	sprite.setSpriteSheet(nome);
}

void Item::desenhar()
{
	if (sprite.getSpriteSheet() != NULL)
	{
		sprite.desenhar(x, y);
	}
}

void Item::atualizar(TileMap*)
{
	if (visivel)
	{
		desenhar();
	}
}

void Item::finalizar()
{

}


void Item::setX(float x)
{
	this->x = x;
}

void Item::setY(float y)
{
	this->y = y;
}

void Item::setSprite(Sprite s)
{
	sprite = s;
}

void Item::setNome(string n)
{
	nome = n;
}

void Item::setVisivel(bool v)
{
	visivel = v;
}

void Item::setAtbonus(int a)
{
	atbonus = a;
}

void Item::setDefbonus(int d)
{
	defbonus = d;
}

void Item::setHpbonus(int h)
{
	hpbonus = h;
}

float Item::getX()
{
	return x;
}

Sprite Item::getSprite()
{
	return sprite;
}

float Item::getY()
{
	return y;
}

string Item::getNome()
{
	return nome;
}

bool Item::getVisivel()
{
	return visivel;
}

int Item::getAtbonus()
{
	return atbonus;
}

int Item::getDefbonus()
{
	return defbonus;
}

int Item::getHpbonus()
{
	return hpbonus;
}