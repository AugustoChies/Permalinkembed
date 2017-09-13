#include "Hud.h"



Hud::Hud()
{
}


Hud::~Hud()
{
}

void Hud::inicializar()
{
	gRecursos.carregarFonte("fonte", "./fonte_padrao.ttf",20);
	tgold.setFonte("fonte");
	tstats.setFonte("fonte");
	titem.setFonte("fonte");
	tgold.setCor(0, 0, 0);
	tstats.setCor(0, 0, 0);
	titem.setCor(0, 0, 0);
}

void Hud::escreveStats(Jogador* j)
{
	string txt;
	txt= txt+ "Hp: ";
	int hpint= j->getHp();
	txt= txt + to_string(hpint);
	int tipo = j->getTipoclasse();
	switch (tipo)
	{
	case(1) :
		txt = txt + "\nMana: ";
		break;
	case(2) :
		txt = txt + "\nRage: ";
		break;
	case(3) :
		txt = txt + "\nAmmo: ";
		break;
	}
	txt=txt + to_string(j->getEnergia());
	txt=txt + "\nAtaque: ";
	txt=txt + to_string(j->getDano());
	txt=txt + "\nDefesa: ";
	txt=txt + to_string(j->getDefesa());
	tstats.setString(txt);
	tstats.desenhar(100, 75);
}

void Hud::escreveGold(Jogador* j)
{
	string txt;
	txt ="Gold: ";
	txt=txt +  to_string(j->getGold()) + "\n";
	txt = txt + "Pontos: ";
	txt = txt + to_string(j->getPontMonstros());
	tgold.setString(txt);
	tgold.desenhar(900, 75);
}

void Hud::escreveItem(Jogador* j)
{
	if (j->getInventario()->getTam() > 0)
	{
		item = j->getInventario()->localizarItem(j->getItematual());
		item->setX(810);
		item->setY(700);
		item->desenhar();
		titem.setString(item->getNome());
		titem.desenhar(900, 700);
	}
}

void Hud::escreverGeral(Jogador* j)
{
	escreveGold(j);
	escreveStats(j);
	escreveItem(j);
}
