#pragma once

#include "Vector2D.h"

enum class Dominio {Blanca, Negra, Vacio};
class Casilla
{
public:
	static int num;
	//Constructor
	Casilla(Vector2D coord = {0,0});

	//Getters
	inline Dominio getOcupacion() const { return _ocupacion; }
	inline bool getAmenaza()const { return _amenaza; }
	inline bool getComer() const { return _comer; }
	inline bool getMover() const { return _mover; }
	inline Vector2D getPosicion() const {return _coord; }
	//Setters
	inline void setOcupacion(Dominio d) { _ocupacion= d; }
	inline void setAmenaza(bool a) { _amenaza= a; }
	inline void setComer(bool c) { _comer = c; }
	inline void setMover(bool m) { _mover = m; }
	inline void setPosicion(Vector2D newCoord) { _coord = newCoord; }
	
private:
	Vector2D _coord;
	Dominio _ocupacion;
	bool _amenaza, _mover, _comer;
};


