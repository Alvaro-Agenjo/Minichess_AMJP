#pragma once

#include "Torre.h"
#include "Caballo.h"
#include "Alfil.h"
#include "Reina.h"
#include "Rey.h"


enum class t_pieza {PEON, TORRE, CABALLO, ALFIL, REINA, REY};
class Jugador
{
public:
	//Constructor
	Jugador(std::vector<Casilla>& tab, Color c);

	//setters

	//getters

	//tester
	std::ostream& print(std::ostream& o, Casilla cas) const;

private:
	Vector2D _pos{};
	std::vector<Pieza*> _misPiezas;

	//Creaccion piezas
	void CrearPieza(Casilla* c, Color col, t_pieza p);
	void CrearJugador(std::vector<Casilla> &tab, Vector2D pos_ini, Color c);

};

