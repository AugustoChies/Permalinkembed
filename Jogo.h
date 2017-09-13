#pragma once
#include "GerentedeTelas.h"
class Jogo
{
public:
	Jogo();
	~Jogo();

	void inicializar();
	void finalizar();

	void executar();
	void emJogo();
	void menu();
	void selecaoNovo();
	void loading();
private:
	Mapa *mapa;
	Hud *hud;
	Botao *botoes;
	Status status;
	Sprite inicial, selecao;
	GerentedeTelas *gerente;
};

