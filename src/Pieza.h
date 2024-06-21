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

constexpr Vector2D out_of_bounds = { -1,-1 };

enum class Color { Blanco = 1, Negro = -1 };

enum class t_pieza { PEON, TORRE, CABALLO, ALFIL, REINA, REY };

class Pieza
{
public:
	//Constructor
	Pieza(Casilla* cas, Color col, t_pieza tp);
	
	
	//Getters
	inline Casilla* getCasilla() const { return _myCasilla; }
	inline Color getColor() const { return _color; }
	inline t_pieza getT_Pieza() const { return _t_pieza; }
	//Setters
	inline void Clear() { _posiblesMov.clear(); }
	inline void setCasilla(Casilla * c) { _myCasilla = c; }
	//Otros
	virtual void PosiblesMov(const std::vector<Casilla>& tab) = 0;
	virtual void ActualizarTablero(std::vector<Casilla>& tab);

	inline virtual bool ComprobarCoronacion(int coorx) { return false; }
	int ValidarDestino(Vector2D pos, const std::vector<Casilla>& tab);

	virtual bool ActualizarPosicion(std::vector<Casilla>& tab, int indice_c);
	void ActualizarPosicion(Casilla* c);
	void Gravedad(std::vector<Casilla>& tab);

	

	//tester
	virtual std::ostream& operator << (std::ostream& o) const = 0;

protected:
	//Atributos
	Color _color;
	Casilla* _myCasilla;
	std::vector<Casilla> _posiblesMov;

	t_pieza _t_pieza;
	//Metodos
	Casilla getCasilla_copia(Casilla origen, Vector2D direccion, const std::vector<Casilla>& tab);
	Casilla* getCasilla_ref(Casilla origen, Vector2D direccion, std::vector<Casilla>& tab);
	int IndiceCasilla(const Vector2D pos, const std::vector<Casilla>& tab);
	bool validarCasilla(const Casilla destino);

	static bool p1;  //flag indica si ha encontrado una pieza enemiga a la que puede atacar
	inline static void ResetP1() { p1 = false; }
};

bool operator == (const Dominio& d, const Color& c);
bool operator != (const Dominio& d, const Color& c);