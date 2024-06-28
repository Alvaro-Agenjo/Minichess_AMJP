#pragma once

#include "Peon.h"
#include "Torre.h"
#include "Caballo.h"
#include "Alfil.h"
#include "Reina.h"
#include "Rey.h"

#include "freeglut.h"


constexpr Vector2D go_back{ -1,-1 };

class Jugador
{
public:
	//Constructor
	Jugador(std::vector<Casilla>& tab, Color c);
	Jugador(const Jugador& player, std::vector<Casilla> & tab);
	Jugador& operator = (const Jugador& player);
	~Jugador();

	//setters
	void BorrarPieza(Casilla & c);
	void CambiarTablero( std::vector<Casilla>& tab);
	void modificarPosicion(Vector2D dir);
	inline void GRAPH_setPripero(bool bo) { primero = bo; }
	//getters
	inline Vector2D getPosicion() const { return _pos; }
	inline std::vector<Pieza*> getPiezas() { return _misPiezas; }
	//otros
	void PosiblesMov( std::vector<Casilla> tab);
	void ActualizarAmenazas(std::vector<Casilla>& tab);

	Vector2D Movimiento(const std::vector<Casilla>& tab,int &fase);
	int ValidarPieza(Vector2D pos);
	int ValidarDestino_pieza(Vector2D pos, int indice, const std::vector<Casilla>& tab);
	
	void ActualizarMovimiento(Vector2D indices, std::vector<Casilla> &tab);
	void AplicarGravedad(Casilla* cas, std::vector<Casilla>& tab);

	bool HayMovimiento();
	bool ComprobarJaque();
	
	//Gr�ficos
	void mover();
	void dibujar(Color c ,int tipo = 0);
	//tester
	std::ostream& print(std::ostream& o, Casilla cas) const;

private:
	Vector2D _pos{};
	std::vector<Pieza*> _misPiezas;

	//Creaccion piezas
	void CrearPieza(Casilla* c, Color col, t_pieza p);
	void CrearJugador(std::vector<Casilla> &tab, Vector2D pos_ini, Color c);

	//--------------------------------------->>>>> rellenar
	//graficos
	bool primero = true;
	float lado = 1.5;
	float espesor = 0.2;
	void dibujarCursor(Color c, bool primero = true);
	//ETSIDI::Sprite _cursor;
	//--------------------------------------->>>>> fin
};

