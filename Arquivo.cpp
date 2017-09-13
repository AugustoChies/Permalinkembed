#include "Arquivo.h"



Arquivo::Arquivo()
{
}


Arquivo::~Arquivo()
{
}

void Arquivo::salvarArquivo(Mapa * m,const char* nome)
{
	string text;
	int valorint;
	bool valorbool;
	ofstream arq(nome, ios::binary);

	//JOOGADOR
	valorint= m->getJogador()->getTipoclasse();
	arq.write(reinterpret_cast<const char*> (&valorint), sizeof(int));
	text = m->getJogador()->getNome();
	valorint = text.size();
	arq.write(reinterpret_cast<const char*> (&valorint), sizeof(int));
	arq.write(text.c_str(), valorint);
	valorint= m->getJogador()->getHpmax();
	arq.write(reinterpret_cast<const char*> (&valorint), sizeof(int));
	valorint = m->getJogador()->getHp();
	arq.write(reinterpret_cast<const char*> (&valorint), sizeof(int));
	valorint = m->getJogador()->getMaxenergia();
	arq.write(reinterpret_cast<const char*> (&valorint), sizeof(int));
	valorint = m->getJogador()->getEnergia();
	arq.write(reinterpret_cast<const char*> (&valorint), sizeof(int));
	valorint = m->getJogador()->getDano();
	arq.write(reinterpret_cast<const char*> (&valorint), sizeof(int));
	valorint = m->getJogador()->getDefesa();
	arq.write(reinterpret_cast<const char*> (&valorint), sizeof(int));
	valorint = m->getJogador()->getGold();
	arq.write(reinterpret_cast<const char*> (&valorint), sizeof(int));
	valorint = m->getJogador()->getPontMonstros();
	arq.write(reinterpret_cast<const char*> (&valorint), sizeof(int));

	//INVENTARIO
	valorint = m->getJogador()->getInventario()->getTam();
	arq.write(reinterpret_cast<const char*> (&valorint), sizeof(int));
	int tamanho = valorint;
	Item *token = NULL;
	if (tamanho > 0)
	{
		for (int i = 0; i < tamanho; i++)
		{
			token = (m->getJogador()->getInventario()->localizarItem(i));
			text = token->getNome();
			valorint = text.size();
			arq.write(reinterpret_cast<const char*> (&valorint), sizeof(int));
			arq.write(text.c_str(), valorint);
			valorint = token->getAtbonus();
			arq.write(reinterpret_cast<const char*> (&valorint), sizeof(int));
			valorint = token->getDefbonus();
			arq.write(reinterpret_cast<const char*> (&valorint), sizeof(int));
			valorint = token->getHpbonus();
			arq.write(reinterpret_cast<const char*> (&valorint), sizeof(int));
		}
	}
	//SALAS
	valorint = m->getSalaatual();
	arq.write(reinterpret_cast<const char*> (&valorint), sizeof(int));
	int tamsalas = m->getNsalas();
	arq.write(reinterpret_cast<const char*> (&tamsalas), sizeof(int));

	vector<Sala *>arqsalas = m->getSalas();
	for (int k = 0; k < tamsalas; k++)
	{
		valorint = arqsalas[k]->getTipo();
		arq.write(reinterpret_cast<const char*> (&valorint), sizeof(int));
		text = arqsalas[k]->getArquivo();
		valorint = text.size();
		arq.write(reinterpret_cast<const char*> (&valorint), sizeof(int));
		arq.write(text.c_str(), valorint);
		valorbool = arqsalas[k]->getVisitada();
		arq.write(reinterpret_cast<const char*> (&valorbool), sizeof(bool));
		//BAUS
		tamanho = arqsalas[k]->getNbaus();
		arq.write(reinterpret_cast<const char*> (&tamanho), sizeof(int));
		vector<Bau*>arqbaus = arqsalas[k]->getBau();
		if (tamanho > 0)
		{
			for (int i = 0; i < tamanho; i++)
			{
				valorint = arqbaus[i]->getX();
				arq.write(reinterpret_cast<const char*> (&valorint), sizeof(int));
				valorint = arqbaus[i]->getY();
				arq.write(reinterpret_cast<const char*> (&valorint), sizeof(int));
				valorbool = arqbaus[i]->getAberto();
				arq.write(reinterpret_cast<const char*> (&valorbool), sizeof(bool));
			}
		}
		//MONSTROS
		tamanho = arqsalas[k]->getNmonsros();
		arq.write(reinterpret_cast<const char*> (&tamanho), sizeof(int));
		vector <Monstro *>arqmonstros = arqsalas[k]->getMonstro();
		if (tamanho > 0)
		{
			for (int i = 0; i < tamanho; i++)
			{
				valorint = arqmonstros[i]->getId();
				arq.write(reinterpret_cast<const char*> (&valorint), sizeof(int));
				text = arqmonstros[i]->getNome();
				valorint = text.size();
				arq.write(reinterpret_cast<const char*> (&valorint), sizeof(int));
				arq.write(text.c_str(), valorint);
				valorint = arqmonstros[i]->getDano();
				arq.write(reinterpret_cast<const char*> (&valorint), sizeof(int));
				valorint = arqmonstros[i]->getDefesa();
				arq.write(reinterpret_cast<const char*> (&valorint), sizeof(int));
				valorint = arqmonstros[i]->getHpmax();
				arq.write(reinterpret_cast<const char*> (&valorint), sizeof(int));
				valorint = arqmonstros[i]->getHp();
				arq.write(reinterpret_cast<const char*> (&valorint), sizeof(int));
				valorint = arqmonstros[i]->getX();
				arq.write(reinterpret_cast<const char*> (&valorint), sizeof(int));
				valorint = arqmonstros[i]->getY();
				arq.write(reinterpret_cast<const char*> (&valorint), sizeof(int));
				valorbool = arqmonstros[i]->getVivo();
				arq.write(reinterpret_cast<const char*> (&valorbool), sizeof(bool));
			}
		}
	}

	arq.close();
}

Mapa* Arquivo::carregarArquivo(const char * nome)
{
	Mapa *mapa=new Mapa;

	char *buf;
	int valorint;
	bool valorbool;
	ifstream arq(nome, ios::binary);
	//JOGADOR
	Jogador  *j;
	arq.read(reinterpret_cast<char*> (&valorint), sizeof(int));
	switch (valorint)
	{
	case 1:
		j = new TechnoMago();
		break;

	case 2:
		j = new Tanker();
		break;

	case 3:
		j = new Pistoleiro();
		break;

	}

	arq.read(reinterpret_cast<char*> (&valorint), sizeof(int));
	buf = new char[valorint];
	arq.read(buf, valorint);
	string s(buf, valorint);
	j->setNome(s);
	arq.read(reinterpret_cast<char*> (&valorint), sizeof(int));
	j->setHpmax(valorint);
	arq.read(reinterpret_cast<char*> (&valorint), sizeof(int));
	j->setHp(valorint);
	arq.read(reinterpret_cast<char*> (&valorint), sizeof(int));
	j->setMaxenergia(valorint);
	arq.read(reinterpret_cast<char*> (&valorint), sizeof(int));
	j->setEnergia(valorint);
	arq.read(reinterpret_cast<char*> (&valorint), sizeof(int));
	j->setDano(valorint);
	arq.read(reinterpret_cast<char*> (&valorint), sizeof(int));
	j->setDefesa(valorint);
	arq.read(reinterpret_cast<char*> (&valorint), sizeof(int));
	j->setGold(valorint);
	arq.read(reinterpret_cast<char*> (&valorint), sizeof(int));
	j->setPontMonstros(valorint);
	//INVENTARIO
	Inventario *invent = new Inventario();
	int tamanho;
	arq.read(reinterpret_cast<char*> (&tamanho), sizeof(int));
	if (tamanho > 0)
	{
		for (int i = 0; i < tamanho; i++)
		{
			Item *tempi = new Item();
			arq.read(reinterpret_cast<char*> (&valorint), sizeof(int));
			buf = new char[valorint];
			arq.read(buf, valorint);
			string s(buf, valorint);
			tempi->setNome(s);
			arq.read(reinterpret_cast<char*> (&valorint), sizeof(int));
			tempi->setAtbonus(valorint);
			arq.read(reinterpret_cast<char*> (&valorint), sizeof(int));
			tempi->setDefbonus(valorint);
			arq.read(reinterpret_cast<char*> (&valorint), sizeof(int));
			tempi->setHpbonus(valorint);
			tempi->inicializarLoad();
			invent->adicionarItem(tempi);
		}
	}
	j->setInventario(invent);
	j->inicializarLoad();
	mapa->setJogador(j);
	//SALAS
	arq.read(reinterpret_cast<char*> (&valorint), sizeof(int));
	mapa->setSalaatual(valorint);
	int tamsalas;
	arq.read(reinterpret_cast<char*> (&tamsalas), sizeof(int));
	mapa->setNsalas(tamsalas);
	vector<Sala *> salas;
	for (int k = 0; k < tamsalas; k++)
	{
		salas.push_back(new Sala);
		arq.read(reinterpret_cast<char*> (&valorint), sizeof(int));
		salas[k]->setTipo(valorint);
		arq.read(reinterpret_cast<char*> (&valorint), sizeof(int));
		buf = new char[valorint];
		arq.read(buf, valorint);
		string arquivo(buf, valorint);
		salas[k]->setArquivo(arquivo);
		arq.read(reinterpret_cast<char*> (&valorbool), sizeof(bool));
		salas[k]->setVisitada(valorbool);
		//BAUS
		vector<Bau *> baus;
		arq.read(reinterpret_cast<char*> (&tamanho), sizeof(int));
		salas[k]->setNbaus(tamanho);
		if (tamanho > 0)
		{
			for (int i = 0; i < tamanho; i++)
			{
				baus.push_back(new Bau);
				arq.read(reinterpret_cast<char*> (&valorint), sizeof(int));
				baus[i]->setX(valorint);
				arq.read(reinterpret_cast<char*> (&valorint), sizeof(int));
				baus[i]->setY(valorint);
				arq.read(reinterpret_cast<char*> (&valorbool), sizeof(bool));
				baus[i]->setAberto(valorbool);
				baus[i]->inicializar();
			}
		}
		salas[k]->setBau(baus);
		//MONSTROS
		arq.read(reinterpret_cast<char*> (&tamanho), sizeof(int));
		salas[k]->setNmonstros(tamanho);
		vector<Monstro * > monstros;
		if (tamanho > 0)
		{
			for (int i = 0; i < tamanho; i++)
			{
				arq.read(reinterpret_cast<char*> (&valorint), sizeof(int));

				switch (valorint)
				{
				case 0:
					monstros.push_back(new Aranha);
					monstros[i]->setId(valorint);
					break;

				case 1:
					monstros.push_back(new Wisp);
					monstros[i]->setId(valorint);
					break;
				case 2:
					monstros.push_back(new Cyborc);
					monstros[i]->setId(valorint);
					break;
				case 3:
					monstros.push_back(new Chefe);
					monstros[i]->setId(valorint);
					break;

				default:
					break;
				}
				arq.read(reinterpret_cast<char*> (&valorint), sizeof(int));
				buf = new char[valorint];
				arq.read(buf, valorint);
				string s(buf, valorint);
				monstros[i]->setNome(s);
				arq.read(reinterpret_cast<char*> (&valorint), sizeof(int));
				monstros[i]->setDano(valorint);
				arq.read(reinterpret_cast<char*> (&valorint), sizeof(int));
				monstros[i]->setDefesa(valorint);
				arq.read(reinterpret_cast<char*> (&valorint), sizeof(int));
				monstros[i]->setHpmax(valorint);
				arq.read(reinterpret_cast<char*> (&valorint), sizeof(int));
				monstros[i]->setHp(valorint);
				arq.read(reinterpret_cast<char*> (&valorint), sizeof(int));
				monstros[i]->setX(valorint);
				arq.read(reinterpret_cast<char*> (&valorint), sizeof(int));
				monstros[i]->setY(valorint);
				arq.read(reinterpret_cast<char*> (&valorbool), sizeof(bool));
				monstros[i]->setVivo(valorbool);
				monstros[i]->inicializarLoad();
			}
		}
		salas[k]->setMonstro(monstros);

		salas[k]->inicializarLoad();
	}

	mapa->setSalas(salas);

	arq.close();
	return mapa;
}
