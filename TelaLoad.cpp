#include "TelaLoad.h"
#include "TelaJogo.h"



TelaLoad::TelaLoad()
{
	selecao.setSpriteSheet("saves");
}


TelaLoad::~TelaLoad()
{
}

Tela* TelaLoad::executar(Mapa * &mapa, Hud *hud)
{
	selecao.desenhar(512, 374);
	Status status;
	status = sMesmo;
	if (gTeclado.pressionou[TECLA_1])
	{
		mapa = Arquivo::carregarArquivo("binario.bin");
		mapa->inicializarload();
		status = sJogando;
	}
	if (gTeclado.pressionou[TECLA_2])
	{
		mapa = Arquivo::carregarArquivo("binario1.bin");
		mapa->inicializarload();
		status = sJogando;
	}
	if (gTeclado.pressionou[TECLA_3])
	{
		mapa = Arquivo::carregarArquivo("binario2.bin");
		mapa->inicializarload();
		status = sJogando;
	}

	if (status == sJogando)
	{
		return new TelaJogo;
	}
	return 0;
}