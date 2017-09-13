#include "Jogador.h"
#include "Corte.h"



Jogador::Jogador():Personagem()
{
	movendo = 0;
	direcao = 3;
	hpregen = 0;
	invencitime = 0;
	attacktimer = 0;
}


Jogador::~Jogador()
{

}

void Jogador::setInventario(Inventario *i)
{
	inventario = i;
}

void Jogador::setGold(int g)
{
	gold = g;
}

void Jogador::setItematual(int ia)
{
	itematual = ia;
}

void Jogador::setTipoclasse(int t)
{
	tipoClasse = t;
}

Inventario* Jogador::getInventario()
{
	return inventario;
}

int Jogador::getGold()
{
	return gold;
}

bool Jogador::getPodeAtacar()
{
	return podeatacar;
}

int Jogador::getItematual()
{
	return itematual;
}

int Jogador::getTipoclasse()
{
	return tipoClasse;
}

void Jogador::setPontMonstros(int p)
{
	pontmonstros = p;
}
void Jogador::setPontTotal(int p)
{
	ponttotal = p;
}
int Jogador::getPonttotal()
{
	return ponttotal;
}
int Jogador::getPontMonstros()
{
	return pontmonstros;
}

void Jogador::addItem(Item * i)
{
	inventario->adicionarItem(i);
}

void Jogador::usarItem()
{
	Item *token = inventario->localizarItem(itematual);
	setHpmax(maxhp + token->getHpbonus());
	setDano(dano + token->getAtbonus());
	setDefesa(defesa + token->getDefbonus());
	inventario->deletarItem(token);
	itematual = 0;

}

void Jogador::desenhar()
{
	sprite.desenhar(x, y);
}

Ataque* Jogador::atacar()
{
	Ataque *ataque;
	if (tipoClasse == 3)
	{
		ataque = new Bala;
	}
	else if(tipoClasse == 1)
	{
		ataque = new Plasma;
	}
	else
	{
		ataque = new Corte;
	}
	ataque->setDano(dano);
	ataque->setDirecao(direcao);
	if (direcao == 1)
	{
		ataque->setX(x);
		ataque->setY(y - 1);
	}
	else if (direcao == 3)
	{
		ataque->setX(x);
		ataque->setY(y + 1);
	}
	else if (direcao == 2)
	{
		ataque->setX(x + 1);
		ataque->setY(y);
	}
	else if (direcao == 4)
	{
		ataque->setX(x - 1);
		ataque->setY(y);
	}
	
	ataque->inicializar();

	podeatacar = false;

	return ataque;
}

void Jogador::atualizar(TileMap *map)
{
	if (vivo)
	{

		if (!gTeclado.segurando[TECLA_DIR] || !gTeclado.segurando[TECLA_ESQ])
		{
			if (gTeclado.segurando[TECLA_DIR])
			{
				movendo = 2;
				direcao = 2;
				if (map->tileECaminhavel(x + 0.6, y)) //&& map->getObjetoNaPos(x + 0.6, y) == NULL)
				{
					sprite.setAnimacao(1);
					x += 0.004 * velocidade;
					sprite.avancarAnimacao();
				}
			}
			if (gTeclado.segurando[TECLA_ESQ])
			{
				movendo = 4;
				direcao = 4;
				if (map->tileECaminhavel(x - 0.6, y))// && map->getObjetoNaPos(x - 0.6, y) == NULL)
				{
					sprite.setAnimacao(3);
					x -= 0.004 * velocidade;
					sprite.avancarAnimacao();
				}
			}
		}

		if (!gTeclado.segurando[TECLA_CIMA] || !gTeclado.segurando[TECLA_BAIXO])
		{
			if (gTeclado.segurando[TECLA_CIMA])
			{
				movendo = 1;
				direcao = 1;
				if (map->tileECaminhavel(x, y - 0.1))// && map->getObjetoNaPos(x, y - 0.6) == NULL)
				{
					sprite.setAnimacao(2);
					y -= 0.004 * velocidade;
					sprite.avancarAnimacao();
				}
			}
			if (gTeclado.segurando[TECLA_BAIXO])
			{
				movendo = 3;
				direcao = 3;
				if (map->tileECaminhavel(x, y + 0.6))// && map->getObjetoNaPos(x, y + 0.6) == NULL)
				{
					sprite.setAnimacao(0);
					y += 0.004 * velocidade;
					sprite.avancarAnimacao();
				}
			}
		}
		if (gTeclado.soltou[TECLA_CIMA] || gTeclado.soltou[TECLA_BAIXO] || gTeclado.soltou[TECLA_ESQ] || gTeclado.soltou[TECLA_DIR])
		{
			movendo = 0;
		}

		if (gTeclado.pressionou[TECLA_Q])
		{
			itematual--;
			if (itematual < 0)
			{
				if (inventario->getTam() > 0)
				{
					itematual = inventario->getTam() - 1;
				}
				else
				{
					itematual = 0;
				}
			}
		}
		if (gTeclado.pressionou[TECLA_E])
		{
			itematual++;
			if (itematual > 9 || itematual > inventario->getTam() - 1)
			{
				itematual = 0;
			}
		}
		if (gTeclado.pressionou[TECLA_U])
		{
			if (inventario->getTam() > 0)
			{
				usarItem();
			}
		}
		if (gTeclado.pressionou[TECLA_P])
		{
			Item *teste = new Item();
			teste->inicializar();
			addItem(teste);
		}

		obj->setPosCentro(x, y);
		if (hp <= 0)
		{
			vivo = false;
		}
		if (gold > 10000)
		{
			gold = 10000;
		}
		if (hp < maxhp)
		{
			hpregen++;
			if (hpregen > 300)
			{
				hp++;
				hpregen = 0;
			}
		}
		if (invencivel)
		{
			invencitime++;
			if (invencitime > 100)
			{
				invencivel = false;
				invencitime = 0;
			}
		}

		if (!podeatacar)
		{
			attacktimer++;
			if (attacktimer > 25)
			{
				podeatacar = true;
				attacktimer = 0;
			}
		}

		ponttotal = pontmonstros + gold;
	}

}