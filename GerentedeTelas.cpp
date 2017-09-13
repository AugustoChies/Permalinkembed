#include "GerentedeTelas.h"



GerentedeTelas::GerentedeTelas()
{
}


GerentedeTelas::~GerentedeTelas()
{
}

void GerentedeTelas::adicionar(Tela * t)
{
	telas.push(t);
}

void GerentedeTelas::remover()
{
	telas.pop();
}

void GerentedeTelas::exibir(Mapa * &mapa, Hud *hud)
{
	Tela * nt = telas.top()->executar(mapa, hud);
	if (nt != NULL)
	{
		adicionar(nt);
	}
}