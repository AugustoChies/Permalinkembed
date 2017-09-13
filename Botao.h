#ifndef BOTAO_H
#define BOTAO_H
#include "libUnicornio.h"

enum Status {sMesmo, sMenu, sNovoJogo, sLoad, sJogando,sRank };

class Botao
{
public:
	Botao();
	~Botao();
	void desenharMenu();
	void desenharNovoJogo();
	void desenharLoad();
	void desenharSair();
	void desenharRanking();
	void inicializar();
	Status atualizar();

protected:
	BotaoSprite bLoad, bSair, bNovoJogo, bMenu,bRank;
};
#endif

