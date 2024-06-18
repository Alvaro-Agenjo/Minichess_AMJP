#pragma once

#include "Tablero.h"
#include "Jugador.h"

enum GameState
{
	Creaccion,
	B_Actualizar_Amenazas,
	B_Espera,
	B_Mov,
};

class Ajedrez
{
public: 
	//Constructor
	Ajedrez();

	//setters

	//getters
	inline GameState getEstado() const { return _estado; }
	
	//otros
	void Stateflow();
	//tester
	std::ostream& printTablero (std::ostream& o = std::cout);
	std::ostream& printAmenazas (std::ostream& o = std::cout);

private:
	GameState _estado;
	Tablero _tablero;
	Jugador _j1, _j2;
};

//tester
std::ostream& operator << (std::ostream& o, const Ajedrez& aj);
