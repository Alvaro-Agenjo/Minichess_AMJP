#pragma once

#include "Ajedrez.h"
#include "ETSIDI.h"
#include "freeglut.h"

class Gestor
{
public:
	Gestor();
	

	void teclaEspecial(unsigned char key);
	void telcla(unsigned char key);
	void mueve();
	void dibuja();

protected:
	Ajedrez _game;
	enum ChessState {INICIO,INSTRUCCIONES, JUEGO, BWIN, NWIN};
	ChessState _estado;

private:
	ETSIDI::Sprite logopeon{ "imagenes/logo peon.png",5 };
	int caida = 0;
};

