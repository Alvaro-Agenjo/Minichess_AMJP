#pragma once
#include "Vector2D.h"

enum class Dominio {Vacio, Blanca, Negra=-1};

constexpr float correccion_tam = 2;
constexpr Vector2D offset_izda = { 3,0 };


class Casilla
{
public:
	
	//Constructor
	Casilla(Vector2D coord = {-1,-1});

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
	
	void ClearCasilla();

	//graficos
	void HighlightCasilla();

	//testers
	std::ostream& print (std::ostream& o) const;

private:
	Vector2D _coord;
	Dominio _ocupacion;
	bool _amenaza;			// indica que el enemigo puede comer en esta casilla
	bool _mover, _comer;	//indica que el propio juador puede comer o mover sus piezas

	//graficos
	float lado = 0.6;
};

//testers
bool operator == (const Casilla& c1, const Casilla& c2);

