#include "TelaMenu.h"
#include "TelaLoad.h"
#include "TelaSelecao.h"
#include "TelaRank.h"


TelaMenu::TelaMenu()
{
	inicial.setSpriteSheet("menu");
	botoes = new Botao;
	botoes->inicializar();
}


TelaMenu::~TelaMenu()
{
}

Tela* TelaMenu::executar(Mapa * &mapa, Hud *hud)
{
	inicial.desenhar(512, 374);
	botoes->desenharSair();
	botoes->desenharNovoJogo();
	botoes->desenharLoad();
	botoes->desenharRanking();
	Status status=botoes->atualizar();
	
	switch (status)
	{
	case sNovoJogo:
		return new TelaSelecao;
		break;
	case sLoad:
		return new TelaLoad;
		break;

		case sRank:
			return new TelaRank();
			break;
	}

	return 0;
}
