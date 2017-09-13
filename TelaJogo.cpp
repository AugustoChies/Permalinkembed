#include "TelaJogo.h"
#include "TelaOver.h"
#include "TelaWin.h"
#include "TelaMenu.h"

TelaJogo::TelaJogo()
{
}


TelaJogo::~TelaJogo()
{
}

Tela* TelaJogo::executar(Mapa * &mapa, Hud *hud)
{
		mapa->executar();
		hud->escreverGeral(mapa->getJogador());
		if (!gMusica.estaTocando())
		{
			gMusica.tocar("musica", true);
		}

		if (gTeclado.pressionou[TECLA_V])
		{
			Arquivo::salvarArquivo(mapa,"binario.bin");
		}
		if (gTeclado.pressionou[TECLA_B])
		{
			Arquivo::salvarArquivo(mapa, "binario1.bin");
		}
		if (gTeclado.pressionou[TECLA_N])
		{
			Arquivo::salvarArquivo(mapa, "binario2.bin");
		}

		if (gTeclado.pressionou[TECLA_0])
		{
			gMusica.parar();
			return new TelaMenu();
		}
		if (!mapa->getJogador()->getVivo())
		{
			gMusica.parar();
			return new TelaOver();
		}
		if (mapa->getSalas()[mapa->getSalas().size() -1]->tudoMorto())
		{
			gMusica.parar();
			return new TelaWin();
		}
		return 0;
}
