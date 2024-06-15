#pragma once

#include "Tablero.h"
//#include "Torre.h"

/* Test validez de clase jugdor*/
#include "Jugador.h"

enum GameState
{
	Creaccion,
	Espera_blancas,
	Espera_negras,
	Mov_blancas,
	Mov_negras,
	Gana_blancas,
	Gana_negras
};

class Ajedrez
{
public: 
	//Constructor
	Ajedrez();

	//setters

	//getters

	//tester
	//inline const Tablero& myTablero() const { return _tablero; }

	friend std::ostream& operator << (std::ostream& o, const Ajedrez& aj);
private:
	Tablero _tablero;
	Jugador _j1, _j2;
};

//tester
//std::ostream& operator << (std::ostream& o, const Ajedrez& aj);
