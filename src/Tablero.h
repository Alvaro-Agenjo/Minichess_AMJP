#pragma once

#include <vector>
#include "Casilla.h"

constexpr int filas = 8;
constexpr int columnas = 8;

class Tablero
{
public:
	//////////////////////////////////////////////////////////////////////
	//				CONSTRUCTORES, ASIGNACIÓN Y DESTRUCTOR 				//
	//////////////////////////////////////////////////////////////////////
	Tablero();
	Tablero(const Tablero& tab);
	Tablero& operator = (const Tablero& tab);
	~Tablero();

	//////////////////////////////////////
	//				GETTERS				//
	//////////////////////////////////////
	inline std::vector<Casilla>& getTablero() { return _tablero; }
	inline std::vector<Casilla> getTableroConst() const { return _tablero; }
	std::vector<Casilla*> getCasillasOcupadas();
	
	//////////////////////////////////////
	//				SETTERS				//
	//////////////////////////////////////

	//restablece a false la amenaza de todas las casillas
	void ClearAmenazas();

	//////////////////////////////////////////
	//				GRÁFICOS				//
	//////////////////////////////////////////

	void dibujar();

private:
	//contine un vector con todas las casillas
	std::vector <Casilla> _tablero;
};

