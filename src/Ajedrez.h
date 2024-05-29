#pragma once

#include "Tablero.h"
#include "Torre.h"

enum GameState
{
	Espera_blancas,
	Espera_negras,
	Mov_blancas,
	Mov_negras,
	Gana_blancas,
	Gana_negras
};

class Ajedrez
{
	Tablero _tablero;
};

