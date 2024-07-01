#pragma once

#include "Ajedrez.h"



class Gestor
{
public:
	Gestor();


	void teclaEspecial(unsigned char key);
	void telcla(unsigned char key);
	void mueve(double t);
	void dibuja();
	void Update();


protected:
	Ajedrez _game;
	enum ChessState { INICIO, INSTRUCCIONES, EXIT, JUEGO, BWIN, NWIN };
	ChessState _estado;

private:
	void AnimacionGravedad(int destino);


	ETSIDI::Sprite logopeon{ "imagenes/logo peon.png", 5 };
	ETSIDI::Vector2D _pos_peon{ 0,6 }, _vel_peon{}, _accel_peon{};
	int caida = 0;
};

