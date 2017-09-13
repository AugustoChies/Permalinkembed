#include "Sala.h"



Sala::Sala()
{
	visitada = false;
	mapa = NULL;
}


Sala::~Sala()
{
}

void Sala::inicializar()
{
	mapa = new TileMap();
	
	if (tipo==3)
	{
		nbaus = 0;
		nmonstros = 1;
		monstros.push_back(new Chefe());
		monstros[0]->setId(3);
		monstros[0]->inicializar();
	}
	else
	{
		nbaus = rand() % 3;
		nmonstros = rand() % 6;
		for (int i = 0; i < nmonstros; i++)
		{
			int id = rand() % 3;
			switch (id)
			{
			case 0:
				monstros.push_back(new Aranha());
				monstros[i]->setId(0);
				break;
			case 1:
				monstros.push_back(new Wisp());
				monstros[i]->setId(1);
				break;
			case 2:
				monstros.push_back(new Cyborc());
				monstros[i]->setId(2);
				break;

			}
			monstros[i]->inicializar();
		}
		for (int i = 0; i < nbaus; i++)
		{
			baus.push_back(new Bau());
			baus[i]->inicializar();
		}
	}
	mapa->carregar(arquivo);
	oxj1 = mapa->getCamadaDeObjetos("Objetos")->getObjeto("Jogador")->getPosCentro().x;
	oyj1 = mapa->getCamadaDeObjetos("Objetos")->getObjeto("Jogador")->getPosCentro().y;
	if (tipo == 1 || tipo == 2)
	{
		oxj2 = mapa->getCamadaDeObjetos("Objetos")->getObjeto("Jogador2")->getPosCentro().x;
		oyj2 = mapa->getCamadaDeObjetos("Objetos")->getObjeto("Jogador2")->getPosCentro().y;
		porta = new Porta();
		porta->inicializar();
		porta->setObj(mapa->getCamadaDeObjetos("Objetos")->getObjeto("Porta"));
	}
	if (tipo == 2 || tipo == 3)
	{
		portavolta = new Porta();
		portavolta->inicializar();
		portavolta->setObj(mapa->getCamadaDeObjetos("Objetos")->getObjeto("Porta2"));
	}

	int x;
	int y;
	for (int i = 0; i < nmonstros; i++)
	{
		bool deucerto = false;
		ObjetoTileMap * obj=mapa->getCamadaDeObjetos("Objetos")->criarObjeto();
		do
		{
			x = rand() % 32;
			y = rand() % 24;

		} while (!(mapa->tileECaminhavel(x, y)) || mapa->getObjetoNaPos(x, y) != NULL || mapa->getObjetoNaPos(x + 1, y) != NULL || mapa->getObjetoNaPos(x - 1, y) != NULL
					|| mapa->getObjetoNaPos(x, y + 1) != NULL || mapa->getObjetoNaPos(x, y - 1) != NULL);
		if (tipo == 3)
		{
			obj->setPosCentro(15, 4);
		}
		else
		{
			obj->setPosCentro(x, y);
		}
		if (tipo == 3)
		{
			obj->setAltura(4);
			obj->setLargura(4);
		}
		else
		{
			obj->setAltura(1);
			obj->setLargura(1);
		}
		monstros[i]->setObj(obj);
	}
	for (int i = 0; i < nbaus; i++)
	{
		ObjetoTileMap * obj = mapa->getCamadaDeObjetos("Objetos")->criarObjeto();
		do
		{
			x = rand() % 32;
			y = rand() % 24;
		} while (!mapa->tileECaminhavel(x, y) && mapa->getObjetoNaPos(x, y) == NULL && mapa->getObjetoNaPos(x + 1, y) && mapa->getObjetoNaPos(x - 1, y)
			&& mapa->getObjetoNaPos(x, y + 1) && mapa->getObjetoNaPos(x, y - 1));
		obj->setPosCentro(x, y);
		obj->setAltura(1);
		obj->setLargura(1);
		baus[i]->setObj(obj);
	}

	
}

void Sala::inicializarLoad()
{
	mapa = new TileMap();
	mapa->carregar(arquivo);
	oxj1 = mapa->getCamadaDeObjetos("Objetos")->getObjeto("Jogador")->getPosCentro().x;
	oyj1 = mapa->getCamadaDeObjetos("Objetos")->getObjeto("Jogador")->getPosCentro().y;
	if (tipo == 1 || tipo == 2)
	{
		oxj2 = mapa->getCamadaDeObjetos("Objetos")->getObjeto("Jogador2")->getPosCentro().x;
		oyj2 = mapa->getCamadaDeObjetos("Objetos")->getObjeto("Jogador2")->getPosCentro().y;
		porta = new Porta();
		porta->inicializar();
		porta->setObj(mapa->getCamadaDeObjetos("Objetos")->getObjeto("Porta"));
	}
	if (tipo == 2 || tipo == 3)
	{
		portavolta = new Porta();
		portavolta->inicializar();
		portavolta->setObj(mapa->getCamadaDeObjetos("Objetos")->getObjeto("Porta2"));
	}
	if (nmonstros > 0)
	{
		for (int i = 0; i < nmonstros; i++)
		{
			ObjetoTileMap * obj = mapa->getCamadaDeObjetos("Objetos")->criarObjeto();
			obj->setPosCentro(monstros[i]->getX(), monstros[i]->getY());
			if (tipo == 3)
			{
				obj->setAltura(4);
				obj->setLargura(4);
			}
			else
			{
				obj->setAltura(1);
				obj->setLargura(1);
			}
			monstros[i]->setObj(obj);
		}
	}

	if (nbaus > 0)
	{
		for (int i = 0; i < nbaus; i++)
		{
			ObjetoTileMap * obj = mapa->getCamadaDeObjetos("Objetos")->criarObjeto();
			obj->setPosCentro(baus[i]->getX(), baus[i]->getY());
			obj->setAltura(1);
			obj->setLargura(1);
			baus[i]->setObj(obj);
		}
	}

}

void Sala::desenhar()
{
	mapa->desenhar();
}


void Sala::finalizar()
{
	if (mapa != NULL)
	{
		if (mapa->estaCarregado())
		{
			mapa->descarregar();
		}
	}
	int i = ataques.size();
	for (int k = 0; k < i; k++)
	{
		delete ataques[k];
	}
}

void Sala::atualizar()
{
	desenhar();
	jogador->atualizar(mapa);
	colisaoMonstros();
	colisaoBaus();
	gerenciaAtaques();
	colisaoAtaques();
}

void Sala::setPorta(Porta *p)
{
	porta = p;
}

void Sala::setJogador(Jogador* &j)
{
	jogador = j;
	mapa->getCamadaDeObjetos("Objetos")->getObjeto("Jogador")->setVisivel(true);
	mapa->getCamadaDeObjetos("Objetos")->getObjeto("Jogador")->setPosCentro(oxj1, oyj1);
	jogador->setObj(mapa->getCamadaDeObjetos("Objetos")->getObjeto("Jogador"));
	if (tipo != 3)
	{
		mapa->getCamadaDeObjetos("Objetos")->getObjeto("Jogador2")->setVisivel(false);
	}
}

void Sala::setJogadornaVolta(Jogador* &j)
{
	jogador = j;
	mapa->getCamadaDeObjetos("Objetos")->getObjeto("Jogador2")->setVisivel(true);
	mapa->getCamadaDeObjetos("Objetos")->getObjeto("Jogador2")->setPosCentro(oxj2, oyj2);
	jogador->setObj(mapa->getCamadaDeObjetos("Objetos")->getObjeto("Jogador2"));
	mapa->getCamadaDeObjetos("Objetos")->getObjeto("Jogador")->setVisivel(false);
}

bool Sala::avancou()
{
	if (tipo == 1 || tipo == 2)
	{		
			if (uniTestarColisaoRetanguloComRetangulo(jogador->getX(), jogador->getY(), 0, 1, 1, 0.5, 0.5,
				porta->getX(), porta->getY(), 0, 4, 3, 0.5, 0.5))
			{
				return true;
			}		
	}
	return false;
}

bool Sala::voltou()
{
	if (tipo == 3 || tipo == 2)
	{
		if (uniTestarColisaoRetanguloComRetangulo(jogador->getX(), jogador->getY(), 0, 1, 1, 0.5, 0.5,
			portavolta->getX(), portavolta->getY(), 0, 4, 3, 0.5, 0.5))
		{
			return true;
		}
	}
	return false;
}

void Sala::colisaoBaus()
{
	for (int i = 0; i < nbaus; i++)
	{
		if (uniTestarColisaoRetanguloComRetangulo(jogador->getX(), jogador->getY(), 0, 1, 1, 0.5, 0.5,
			baus[i]->getX(),baus[i]->getY(), 0, 1, 1, 0.5, 0.5))
		{
			if (!baus[i]->getAberto())
			{
				int aleatorio = rand() % 101;
				if (aleatorio < 40)
				{
					jogador->addItem(baus[i]->dropItem());
				}
				else
				{
					jogador->setGold(jogador->getGold() + baus[i]->dropGold());
				}
			}
		}
		baus[i]->atualizar(mapa);
	}
}

void Sala::colisaoMonstros()
{
	for (int i = 0; i < nmonstros; i++)
	{
		if (tipo==3)
		{
			if (uniTestarColisaoRetanguloComRetangulo(jogador->getX(), jogador->getY(), 0, 1, 1, 0.5, 0.5,
				monstros[i]->getX(), monstros[i]->getY(), 0, 4, 4, 0.5, 0.5))
			{
				if (monstros[i]->getVivo() && !jogador->getInvencivel())
				{
					int alea = rand() % 11 + 2;
					jogador->tomarDano(monstros[i]->getDano() + alea);
				}
			}
		}
		else
		{
			if (uniTestarColisaoRetanguloComRetangulo(jogador->getX(), jogador->getY(), 0, 1, 1, 0.5, 0.5,
				monstros[i]->getX(), monstros[i]->getY(), 0, 1, 1, 0.5, 0.5))
			{
				if (monstros[i]->getVivo() && !jogador->getInvencivel())
				{
					int alea = rand() % 11 + 2;
					jogador->tomarDano(monstros[i]->getDano() + alea);
				}
			}
		}
		monstros[i]->atualizar(mapa, jogador);
	}
}

void Sala::gerenciaAtaques()
{
	//for (int i = 0; i < ataques.size(); i++)
	//{
		//if (!ataques[i]->getAtivo())
		//{
			//ataques.pop_back();
			//break;
		//}
	//}
	if (gTeclado.pressionou[TECLA_S])
	{
		if (jogador->getPodeAtacar())
		{
			ataques.push_back(jogador->atacar());
		}
	}

	for (int i = 0; i < ataques.size(); i++)
	{
		ataques[i]->atualizar(mapa);
	}
}

void Sala::colisaoAtaques()
{
	for (int i = 0; i < ataques.size(); i++)
	{
		if (ataques[i]->getAtivo())
		{
			for (int k = 0; k < nmonstros; k++)
			{
				if (tipo == 3)
				{
					if (uniTestarColisaoRetanguloComRetangulo(ataques[i]->getX(), ataques[i]->getY(), 0, 1, 1, 0.5, 0.5,
						monstros[k]->getX(), monstros[k]->getY(), 0, 4, 4, 0.5, 0.5))
					{
						if (monstros[k]->getVivo())
						{
							int alea = rand() % 11 + 2;
							monstros[k]->tomarDano(ataques[i]->getDano() + alea);
							ataques[i]->setAtivo(false);
							jogador->setPontMonstros(jogador->getPontMonstros() + 50);
						}
					}
				}
				else
				{
					if (uniTestarColisaoRetanguloComRetangulo(ataques[i]->getX(), ataques[i]->getY(), 0, 1, 1, 0.5, 0.5,
						monstros[k]->getX(), monstros[k]->getY(), 0, 1, 1, 0.5, 0.5))
					{
						if (monstros[k]->getVivo())
						{
							int alea = rand() % 11 + 2;
							monstros[k]->tomarDano(ataques[i]->getDano() + alea);
							ataques[i]->setAtivo(false);
							jogador->setPontMonstros(jogador->getPontMonstros() + 50);
						}
					}
				}
			}
		}
	}
}

bool Sala::tudoMorto()
{
	bool morto = true;
	for (int i = 0; i < nmonstros; i++)
	{
		if (monstros[i]->getVivo())
		{
			morto = false;
		}
	}
	return morto;
}

void Sala::setMonstro(vector<Monstro*> m)
{
	monstros = m;
}

void Sala::setBau(vector<Bau *> b)
{
	baus = b;
}

void Sala::setNmonstros(int n)
{
	nmonstros = n;
}

void Sala::setNbaus(int n)
{
	nbaus = n;
}

void Sala::setTipo(int t)
{
	tipo = t;
}

void Sala::setArquivo(string a)
{
	arquivo = a;
}


void Sala::setVisitada(bool v)
{
	visitada = v;
}


void Sala::setOxj1(float x)
{
	oxj1 = x;
}
void Sala::setOyj1(float y)
{
	oyj1 = y;
}
void Sala::setOxj2(float x)
{
	oxj2 = x;
}
void Sala::setOyj2(float y)
{
	oxj2 = y;
}

Porta* Sala::getPorta()
{
	return porta;
}

Jogador* Sala::getJogador()
{
	return jogador;
}

vector<Monstro*> Sala::getMonstro()
{
	return monstros;
}

vector<Bau *> Sala::getBau()
{
	return baus;
}

int Sala::getNmonsros()
{
	return nmonstros;
}

int Sala::getNbaus()
{
	return nbaus;
}

int Sala::getTipo()
{
	return tipo;
}

string Sala::getArquivo()
{
	return arquivo;
}


bool Sala::getVisitada()
{
	return visitada;
}

float Sala::getOxj1()
{
	return oxj1;
}
float Sala::getOyj1()
{
	return oyj1;
}
float Sala::getOxj2()
{
	return oxj2;
}
float Sala::getOyj2()
{
	return oyj2;
}