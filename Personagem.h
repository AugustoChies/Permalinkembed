#ifndef PERSONA_H
#define PERSONA_H
#include "Entidade.h"
class Personagem: public Entidade
{
public:
	Personagem();
	~Personagem();
	void setNome(string);
	void setHp(float);
	void setHpmax(float);
	void setVivo(bool);
	void setDano(int);
	void setDefesa(int);
	void setVelocidade(int);
	void setX(float);
	void setY(float);
	void setSprite(Sprite);
	void setObj(ObjetoTileMap*);
	void setInvencivel(bool);
	string getNome();
	float getHp();
	float getHpmax();
	bool getVivo() ;
	int getDano() ;
	int getDefesa() ;
	int getVelocidade() ;
	int getMovimento();
	int getDirecao();
	float getX();
	Sprite getSprite();
	float getY();
	float getLargura();
	float getAltura();
	ObjetoTileMap* getObj();
	bool getInvencivel();
	void tomarDano(int);
protected:
	string nome;
	float hp, maxhp;
	bool vivo,invencivel;
	int dano, defesa, velocidade,movendo,direcao, invencitime;
	ObjetoTileMap *obj;
};
#endif

