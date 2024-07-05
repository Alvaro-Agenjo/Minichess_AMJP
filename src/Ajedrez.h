#pragma once

#include "Tablero.h"
#include "Jugador.h"


enum GameState
{
	Creaccion,
	B_Actualizar_Amenazas,
	B_Espera,
	B_Mov,
	B_Comprobar_Jaques,
	N_Actualizar_Amenazas,
	N_Espera,
	N_Mov,
	N_Comprobar_Jaques,
	B_Win,
	N_Win,
};

class Ajedrez
{
public: 
	//Constructor
	Ajedrez();

	//////////////////////////////////////
	//				GETTERS				//
	//////////////////////////////////////
	inline GameState getEstado() const { return _estado; }
	inline bool getWait() const { return wait; }
	
	//////////////////////////////////////////
	//					OTROS				//
	//////////////////////////////////////////

	// avanza el ciclo de estados del ajedrez
	void Stateflow();

	//////////////////////////////////////////
	//				GRÁFICOS				//
	//////////////////////////////////////////
	void tecla_especial(unsigned char key);
	void tecla(unsigned char key);
	void mover(); 
	void dibujar();
	
	//////////////////////////////////////////
	//			TEST POR CONSOLA			//
	//////////////////////////////////////////
	std::ostream& printTablero (std::ostream& o = std::cout);
	std::ostream& printAmenazas (std::ostream& o = std::cout);

private:
	GameState _estado;
	Tablero _tablero;
	Jugador _j1, _j2;

	//Aplica la gravedad a las piezas de los jugadores blancas y negras sobre el tablero tab
	void AplicarGravedad(Tablero& tab, Jugador& blancas, Jugador& negras);
	//devuelve true si es jaque mate. lo comprueva mediante un tablero fantasma
	bool jaquemate();
	//devuelve un numero que indica el resultado de comprobar el jaque.
	// 1 si no hay jaque, 2 si solo hay jaque, 3 si es jaquemate
	int jaque();

	//hace la comprobacion mediante tablero fantasma y elimina aquellos movimientos que resultan en jaque
	bool ValidarMovimientos(Jugador& blancas, Jugador& negras);

	//////////////////////////////////////////
	//				GRÁFICOS				//
	//////////////////////////////////////////
	
	//flag que marca la espera hasta la desaparición del mensaje de jaque mate
	bool wait = false;
	
	// devuelve true si hay alguna pieza que no ha finalizado su animacion, es decir, está en movimiento
	bool HayMovimiento();
	//imprime la notificacion en glut de jaque y jaque mate
	void Notificacion(Color col, bool mate, int& tempo);
};

//////////////////////////////////////////
//			TEST POR CONSOLA			//
//////////////////////////////////////////

//imprime el estado del ajedrez
std::ostream& operator << (std::ostream& o, const Ajedrez& aj);
