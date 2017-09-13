#include "Mapa.h"



Mapa::Mapa()
{
	nsalas = salaatual = 0;
}


Mapa::~Mapa()
{
	
}

void Mapa::inicializar()
{
	nsalas = salaatual = 0;
	int alea = rand() % 7 + 9;
	for (int i = 0; i < alea; i++)
	{
		salas.push_back(new Sala);
		nsalas++;

		if (i == 0)
		{
			salas[i]->setTipo(1);
			salas[i]->setArquivo("tilemaps/sala1.json");
		}
		else
		{
			salas[i]->setTipo(2);
			int maparand = rand() % 6;
			switch (maparand)
			{
			case 0:
				salas[i]->setArquivo("tilemaps/sala2.json");
				break;
			case 1:
				salas[i]->setArquivo("tilemaps/sala3.json");
				break;
			case 2:
				salas[i]->setArquivo("tilemaps/sala4.json");
				break;
			case 3:
				salas[i]->setArquivo("tilemaps/sala5.json");
				break;
			case 4:
				salas[i]->setArquivo("tilemaps/sala6.json");
				break;
			case 5:
				salas[i]->setArquivo("tilemaps/sala7.json");
				break;
			}
		}
	}

	bool acabou = false;

	while (!acabou)
	{
		alea = rand() % 6;
		if (alea==0)
		{
			acabou = true;
		}
		if (acabou)
		{
			salas.push_back(new Sala);
			nsalas++;
			salas[salas.size() - 1]->setTipo(3);
			salas[salas.size() - 1]->setArquivo("tilemaps/sala_chefe.json");
		}
		else
		{
			salas.push_back(new Sala);
			nsalas++;
			salas[salas.size()-1]->setTipo(2);
			int maparand = rand() % 4;
			switch (maparand)
			{
			case 0:
				salas[salas.size() - 1]->setArquivo("tilemaps/sala2.json");
				break;
			case 1:
				salas[salas.size() - 1]->setArquivo("tilemaps/sala3.json");
				break;
			case 2:
				salas[salas.size() - 1]->setArquivo("tilemaps/sala4.json");
				break;
			case 3:
				salas[salas.size() - 1]->setArquivo("tilemaps/sala5.json");
				break;
			case 4:
				salas[salas.size() - 1]->setArquivo("tilemaps/sala6.json");
				break;
			case 5:
				salas[salas.size() - 1]->setArquivo("tilemaps/sala7.json");
				break;
			}
		}
	}

	for (int i = 0; i < nsalas; i++)
	{
		salas[i]->inicializar();
	}

	salas[salaatual]->setJogador(jogador);
	salas[salaatual]->setVisitada(true);
	potential.push(salas[salaatual]);
	
}

void Mapa::inicializarload()
{
	salas[salaatual]->setJogador(jogador);
	for (int i = 0; i <= salaatual; i++)
	{
		potential.push(salas[i]);
	}
}

void Mapa::executar()
{
	potential.top()->atualizar();
	if (potential.top()->avancou())
	{
		adicionarnaPilha();
	}
	if (potential.top()->voltou())
	{
		removerdaPilha();
	}
}

void Mapa::adicionarnaPilha()
{
	salaatual++;
	salas[salaatual]->setVisitada(true);
	salas[salaatual]->setJogador(jogador);
	potential.push(salas[salaatual]);
}

void Mapa::removerdaPilha()
{
	salaatual--;
	salas[salaatual]->setJogadornaVolta(jogador);
	potential.pop();
}

void Mapa::finalizar()
{
	potential.empty();

}

void Mapa::setJogador(Jogador *j)
{
	jogador = j;
}

void Mapa::setSalas(vector<Sala *> s)
{
	salas = s;
}

void Mapa::setNsalas(int s)
{
	nsalas = s;
}

void Mapa::setSalaatual(int s)
{
	salaatual = s;
}

Jogador* Mapa::getJogador()
{
	return jogador;
}

vector<Sala *> Mapa::getSalas()
{
	return salas;
}

int Mapa::getNsalas()
{
	return nsalas;
}

int Mapa::getSalaatual()
{
	return salaatual;
}