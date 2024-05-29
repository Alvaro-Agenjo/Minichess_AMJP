#pragma once
#include "Casilla.h"
#include <vector>

constexpr Vector2D NORTE = { 0,1 };
constexpr Vector2D SUR = { 0,-1 };
constexpr Vector2D ESTE = { 1,0 };
constexpr Vector2D OESTE = { -1,0 };
constexpr Vector2D NORESTE = { 1,1 };
constexpr Vector2D NOROESTE = { -1,1 };
constexpr Vector2D SUDESTE = { 1,-1 };
constexpr Vector2D SUDOESTE = { -1,-1 };

enum class Color {Blanco, Negro};


class Pieza
{
public:
	//Constructor
	Pieza(Casilla* cas, Color col);

	//Getters

	//Setters

	//Otros
	virtual void PosiblesMov(std::vector<Casilla> tab)=0;

	
protected:
	//Atributos
	const Color _color;
	Casilla* _myCasilla;
	std::vector<Casilla> _posiblesMov;

	//Metodos
	Casilla getCasilla( Casilla origen, Vector2D direccion, const std::vector<Casilla> tab);
	int IndiceCasilla(const Casilla c, const std::vector<Casilla> tab);
	bool validarCasilla(const Casilla destino);
	 
};

bool operator == (const Dominio& d, const Color& c);
bool operator != (const Dominio& d, const Color& c);