#include "TelaRank.h"
#include "TelaMenu.h"
#include <fstream>

TelaRank::TelaRank()
{
	inicial.setSpriteSheet("inicial");
	botoes = new Botao;
	botoes->inicializar();
	once = true;
	tpontuacao.setFonte("fonte");
}


TelaRank::~TelaRank()
{
}

Tela* TelaRank::executar(Mapa * &mapa, Hud *hud)
{
	int *highscores = new int[5];
	inicial.desenhar(512, 374);
	botoes->desenharMenu();
	

	if (once)
	{
		ifstream pontentra("pontuacao.txt");
		if (pontentra.is_open())
		{
			for (int i = 0; i < 5; i++)
			{
				pontentra >> highscores[i];
			}
		}
		pontentra.close();
		text = "Rank:";
		for (int i = 0; i < 5; i++)
		{
			text= text + "\n" + to_string(highscores[i]);
		}
		once = false;
		tpontuacao.setString(text);
	}

	tpontuacao.desenhar(400, 200);

	Status status = botoes->atualizar();

	switch (status)
	{
	case sMenu:
		return new TelaMenu;
		break;
	}
	return 0;
}
