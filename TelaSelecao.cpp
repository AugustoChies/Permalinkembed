#include "TelaSelecao.h"
#include "TelaJogo.h"


TelaSelecao::TelaSelecao()
{
	selecao.setSpriteSheet("selecao");
}


TelaSelecao::~TelaSelecao()
{
}

Tela* TelaSelecao::executar(Mapa * &mapa, Hud *hud)
{
	selecao.desenhar(512, 374);
	Status status;
	status = sMesmo;
	if (gTeclado.pressionou[TECLA_1])
	{
		Jogador *j = new TechnoMago();
		j->inicializar();
		mapa = new Mapa();
		mapa->setJogador(j);
		mapa->inicializar();
		status = sJogando;
	}
	if (gTeclado.pressionou[TECLA_2])
	{
		Jogador *j = new Tanker();
		mapa = new Mapa();
		j->inicializar();
		mapa->setJogador(j);
		mapa->inicializar();
		status = sJogando;
	}
	if (gTeclado.pressionou[TECLA_3])
	{
		Jogador *j = new Pistoleiro();
		mapa = new Mapa();
		j->inicializar();
		mapa->setJogador(j);
		mapa->inicializar();
		status = sJogando;
	}
	
	if (status == sJogando)
	{
		return new TelaJogo;
	}
	return 0;
}
