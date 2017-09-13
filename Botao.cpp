#include "Botao.h"


Botao::Botao()
{
}


Botao::~Botao()
{
}

void Botao::inicializar()
{
	if (!gRecursos.carregouSpriteSheet("bMenu"))
	{
		gRecursos.carregarSpriteSheet("bMenu", "./imagens/botaoMenu.png", 3, 1);
		gRecursos.carregarSpriteSheet("bNovoJogo", "./imagens/botaoNovoJogo.png", 3, 1);
		gRecursos.carregarSpriteSheet("bLoad", "./imagens/botaoLoad.png", 3, 1);
		gRecursos.carregarSpriteSheet("bSair", "./imagens/botaoSair.png", 3, 1);
		gRecursos.carregarSpriteSheet("bRank", "./imagens/botaoRanking.png", 3, 1);
	}
	bNovoJogo.setSpriteSheet("bNovoJogo");
	bLoad.setSpriteSheet("bLoad");
	bMenu.setSpriteSheet("bMenu");
	bSair.setSpriteSheet("bSair");
	bRank.setSpriteSheet("bRank");

	bSair.setPos(200, 500);
	bNovoJogo.setPos(500, 500);
	bRank.setPos(500,640);
	bLoad.setPos(800, 500);
	bMenu.setPos(800, 100);


}

void Botao::desenharMenu()
{
	//bMenu.setPos(x, y);
	bMenu.desenhar();
}

void Botao::desenharRanking()
{
	bRank.desenhar();
}

void Botao::desenharNovoJogo()
{
	//bNovoJogo.setPos(x, y);
	bNovoJogo.desenhar();
}

void Botao::desenharLoad()
{
	//bLoad.setPos(x, y);
	bLoad.desenhar();
}

void Botao::desenharSair()
{
	//bSair.setPos(x, y);
	bSair.desenhar();
}

Status Botao::atualizar()
{
	bNovoJogo.atualizar();
	bMenu.atualizar();
	bLoad.atualizar();
	bSair.atualizar();
	bRank.atualizar();

	if (bNovoJogo.estaClicado())
	{
		return sNovoJogo;
	}

	if (bMenu.estaClicado())
	{
		return sMenu;
	}

	if (bLoad.estaClicado())
	{
	    return sLoad;
	}

	if (bRank.estaClicado())
	{
		return sRank;
	}

	if (bSair.estaClicado())
	{
		//; Comando inexistente na libunicorniio atual
	}
	return sMesmo;
}