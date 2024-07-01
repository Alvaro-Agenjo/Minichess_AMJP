#pragma once

#include <vector>
#include "Casilla.h"
//#include "ETSIDI.h"

constexpr int filas = 8;
constexpr int columnas = 8;

class Tablero
{
public:
	//Constructor
	Tablero();
	Tablero(const Tablero& tab);
	Tablero& operator = (const Tablero& tab);
	~Tablero();

	//getters
	inline std::vector<Casilla>& getTablero() { return _tablero; }
	inline std::vector<Casilla> getTableroConst() const { return _tablero; }
	std::vector<Casilla*> getCasillasOcupadas();
	//setters
	void ClearAmenazas();

	//graficos
	void dibujar();
	//testers

private:
	std::vector <Casilla> _tablero;
};

