#pragma once

#include <vector>
#include "Casilla.h"

constexpr int filas = 8;
constexpr int columnas = 8;

class Tablero
{
public:
	Tablero();
	~Tablero();

//private:
	std::vector <Casilla> _tablero;
};

