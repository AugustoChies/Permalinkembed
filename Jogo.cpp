#include "Jogo.h"
#include "TelaMenu.h"

Jogo::Jogo()
{
	gerente = new GerentedeTelas;
}

Jogo::~Jogo()
{
}

void Jogo::inicializar()
{
	uniInicializar(1024, 768, false);
	status = sMenu;
	if (!gRecursos.carregouSpriteSheet("Aranhabo"))
	{
		gRecursos.carregarSpriteSheet("inicial", "./imagens/fundo.png", 1, 1);
		gRecursos.carregarSpriteSheet("selecao", "./imagens/selecao.png", 1, 1);
		gRecursos.carregarSpriteSheet("saves", "./imagens/saves.png", 1, 1);
		gRecursos.carregarSpriteSheet("over", "./imagens/over.png", 1, 1);
		gRecursos.carregarSpriteSheet("win", "./imagens/win.png", 1, 1);
		gRecursos.carregarSpriteSheet("menu", "./imagens/menu.png", 1, 1);
		gRecursos.carregarSpriteSheet("Aranhabo", "./imagens/aranhabo.png", 1, 2);
		gRecursos.carregarSpriteSheet("NeonWisp", "./imagens/nwisp.png", 1, 4);
		gRecursos.carregarSpriteSheet("Cyborc", "./imagens/ciborc.png", 4, 4);
		gRecursos.carregarSpriteSheet("Chefe", "./imagens/chefe.png", 1, 2);
		gRecursos.carregarSpriteSheet("muscleTonic", "./imagens/mtonic.png", 1, 1);
		gRecursos.carregarSpriteSheet("hpBooster", "./imagens/hpbooster.png", 1, 1);
		gRecursos.carregarSpriteSheet("evolveBark", "./imagens/evolveshell.png", 1, 1);
		gRecursos.carregarSpriteSheet("booster", "./imagens/booster.png", 1, 1);
		gRecursos.carregarSpriteSheet("bala", "./imagens/bala.png", 1, 1);
		gRecursos.carregarSpriteSheet("plasma", "./imagens/plasma.png", 1, 2);
		gRecursos.carregarSpriteSheet("corte", "./imagens/corte.png", 1, 3);
		gRecursos.carregarMusica("musica", "./imagens/musica.ogg");


	}
	inicial.setSpriteSheet("inicial");
	selecao.setSpriteSheet("selecao");
	mapa = new Mapa();
	botoes = new Botao();
	hud = new Hud();
	hud->inicializar();
	botoes->inicializar();

	gerente->adicionar(new TelaMenu);
	//	O resto da inicialização vem aqui!
	//	...
}

void Jogo::finalizar()
{
	//	O resto da finalização vem aqui (provavelmente, em ordem inversa a inicialização)!
	//	...

	if (mapa != NULL)
	{
		mapa->finalizar();
	}
	gRecursos.descarregarTudo();
	uniFinalizar();
}

void Jogo::executar()
{
	while(!gTeclado.soltou[TECLA_ESC] && !gEventos.sair)
	{
		uniIniciarFrame();

		//	Seu código vem aqui!
		//	...
		gerente->exibir(mapa,hud);

	
		uniTerminarFrame();
	}
}

void Jogo::emJogo()
{
	mapa->executar();
	hud->escreveItem(mapa->getJogador());
	hud->escreveStats(mapa->getJogador());
	if (gTeclado.pressionou[TECLA_V])
	{
		Arquivo::salvarArquivo(mapa,"binario.bin");
	}
}

void Jogo::menu()
{
	inicial.desenhar(512, 374);
	//botoes->atualizar(status);
	botoes->desenharSair();
	botoes->desenharNovoJogo();
	botoes->desenharLoad();

}

void Jogo::selecaoNovo()
{
	selecao.desenhar(512, 374);
	if (gTeclado.pressionou[TECLA_1])
	{
		Jogador *j=new TechnoMago();
		j->inicializar();
		mapa->setJogador(j);
		mapa->inicializar();
		status = sJogando;
	}
	if (gTeclado.pressionou[TECLA_2])
	{
		Jogador *j = new Tanker();
		j->inicializar();
		mapa->setJogador(j);
		mapa->inicializar();
		status = sJogando;
	}
	if (gTeclado.pressionou[TECLA_3])
	{
		Jogador *j = new Pistoleiro();
		j->inicializar();
		mapa->setJogador(j);
		mapa->inicializar();
		status = sJogando;
	}

}


void Jogo::loading()
{
	mapa = Arquivo::carregarArquivo("binario.bin");
	mapa->inicializarload();
	status = sJogando;
}