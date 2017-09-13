#ifndef SALA_H
#define SALA_H
#include "libUnicornio.h"
#include "Porta.h"
#include "TechnoMago.h"
#include "Tanker.h"
#include "Pistoleiro.h"
#include "Aranha.h"
#include "Wisp.h"
#include "Cyborc.h"
#include "Chefe.h"
#include "Bau.h"
#include "Bala.h"
#include <vector>
class Sala
{
	const int CIMA = 1;
	const int DIREITA = 2;
	const int BAIXO = 3;
	const int ESQUERDA = 4;

public:
	Sala();
	~Sala();
	void inicializar();
	void inicializarLoad();
	void desenhar();
	void finalizar();
	void atualizar();
	void setPorta(Porta*);
	void setJogador(Jogador* &j);
	void setJogadornaVolta(Jogador* &j);
	void setMonstro(vector<Monstro*>);
	void setBau(vector<Bau *>);
	void setNmonstros(int);
	void setNbaus(int);
	void setTipo(int);
	void setArquivo(string a);
	void setVisitada(bool);
	void setOxj1(float);
	void setOyj1(float);
	void setOxj2(float);
	void setOyj2(float);
	Porta* getPorta();
	Jogador* getJogador();
	vector<Monstro*> getMonstro();
	vector<Bau *> getBau();
	int getNmonsros();
	int getNbaus();
	int getTipo();
	string getArquivo();
	bool getVisitada();
	float getOxj1();
	float getOyj1();
	float getOxj2();
	float getOyj2();
	bool avancou();
	bool voltou();
	void colisaoBaus();
	void colisaoMonstros();
	bool tudoMorto();
	void gerenciaAtaques();
	void colisaoAtaques();
protected:
	TileMap *mapa;
	Porta *porta, *portavolta;
	Jogador *jogador;
	vector<Monstro*>  monstros;
	vector<Bau *> baus;
	vector<Ataque *> ataques;
	int nmonstros,nbaus,tipo;
	string arquivo;
	bool visitada;
	float oxj1, oyj1, oxj2, oyj2;
};
#endif

