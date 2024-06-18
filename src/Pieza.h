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

enum class Color {Blanco=1, Negro=-1};


class Pieza
{
public:
	//Constructor
	Pieza(Casilla* cas, Color col);

	//Getters
	inline Casilla* getCasilla() const { return _myCasilla; }

	//Setters
	inline void Clear() { _posiblesMov.clear(); }
	
	//Otros
	virtual void PosiblesMov(const std::vector<Casilla> &tab)=0;
	virtual void ActualizarTablero(std::vector<Casilla> & tab);
	
	virtual int ValidarDestino(Vector2D pos);
	
	void ActualizarPosicion(std::vector<Casilla>& tab, int indice_c);
	
	//tester
	virtual std::ostream& operator << (std::ostream& o) const  =0;
	
protected:
	//Atributos
	const Color _color;
	Casilla* _myCasilla;
	std::vector<Casilla> _posiblesMov;

	//Metodos
	Casilla getCasilla( Casilla origen, Vector2D direccion, const std::vector<Casilla>& tab);
	int IndiceCasilla(const Vector2D pos, const std::vector<Casilla>& tab);
	bool validarCasilla(const Casilla destino);
	 
};

bool operator == (const Dominio& d, const Color& c);
bool operator != (const Dominio& d, const Color& c);