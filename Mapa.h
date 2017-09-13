#pragma once
#include "Sala.h"
class Mapa
{
public:
	Mapa();
	~Mapa();
	void inicializar();
	void inicializarload();
	void executar();
	void adicionarnaPilha();
	void removerdaPilha();
	void finalizar();
	void setJogador(Jogador *);
	void setSalas(vector<Sala *>);
	void setNsalas(int);
	void setSalaatual(int);
	Jogador* getJogador();
	vector<Sala *> getSalas();
	int getNsalas();
	int getSalaatual();



protected:
	vector <Sala *> salas;
	stack  <Sala *> potential; 
	Jogador *jogador;
	int salaatual,nsalas;

};

