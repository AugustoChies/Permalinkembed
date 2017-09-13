#include "TelaOver.h"
#include "TelaMenu.h"



TelaOver::TelaOver()
{
	inicial.setSpriteSheet("over");
	botoes = new Botao;
	botoes->inicializar();
}


TelaOver::~TelaOver()
{
}

Tela* TelaOver::executar(Mapa * &mapa, Hud *hud)
{
	inicial.desenhar(512, 374);
	botoes->desenharMenu();
	Status status = botoes->atualizar();
	switch (status)
	{
	case sMenu:
		return new TelaMenu;
		break;
	}
	return 0;
}