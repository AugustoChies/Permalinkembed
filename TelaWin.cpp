#include "TelaWin.h"
#include "TelaMenu.h"


TelaWin::TelaWin()
{
	inicial.setSpriteSheet("win");
	botoes = new Botao;
	botoes->inicializar();
	once = true;
}


TelaWin::~TelaWin()
{
}

Tela* TelaWin::executar(Mapa * &mapa, Hud *hud)
{
	int *nhigh = new int[5];
	int index, scoredescend, scoredescendresto;
	inicial.desenhar(512, 374);
	botoes->desenharMenu();

	if (once)
	{
		ofstream pontsai("pontuacao.txt");
		for (int i = 0; i < 5; i++)
		{
			if (mapa->getJogador()->getPonttotal() > nhigh[i])
			{
				scoredescend = nhigh[i];
				nhigh[i] = mapa->getJogador()->getPonttotal();
				index = i + 1;
				break;
			}
		}
		for (int i = index; i < 5; i++)
		{
			scoredescendresto = nhigh[i];
			nhigh[i] = scoredescend;
			scoredescend = scoredescendresto;
		}
		for (int i = 0; i < 5; i++)
		{
			pontsai << nhigh[i] << endl;
		}
		pontsai.close();
		once = false;
	}

	Status status = botoes->atualizar();
	switch (status)
	{
	case sMenu:
		return new TelaMenu;
		break;
	}
	return 0;
}
