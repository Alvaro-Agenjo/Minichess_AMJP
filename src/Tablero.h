#pragma once

#include <vector>
#include "Casilla.h"

constexpr int filas = 8;
constexpr int columnas = 8;

class Tablero
{
public:
	//Constructor
	Tablero();
	~Tablero();

	//getters
	inline std::vector<Casilla>& getTablero() { return _tablero; }
	inline std::vector<Casilla> getTableroConst() const { return _tablero; }

	//setters
	void ClearAmenazas();
	//testers

private:
	std::vector <Casilla> _tablero;
};

