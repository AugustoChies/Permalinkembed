#ifndef ARQUIVO_H
#define ARQUIVO_H
#include "Mapa.h"
class Arquivo
{
public:
	Arquivo();
	~Arquivo();
	static void salvarArquivo(Mapa *,const char*);
	static Mapa* carregarArquivo(const char *);
};
#endif
