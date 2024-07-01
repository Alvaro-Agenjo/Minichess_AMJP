#pragma once

#include "Tablero.h"
#include "Jugador.h"


enum GameState
{
	Creaccion,
	B_Actualizar_Amenazas,
	B_Comprobar_Jaques,
	B_Espera,
	B_CompMov,
	B_Mov,
	N_Actualizar_Amenazas,
	N_Comprobar_Jaques,
	N_Espera,
	N_CompMov,
	N_Mov,
	B_Win,
	N_Win,
};

class Ajedrez
{
public: 
	//Constructor
	Ajedrez();

	//setters

	//getters
	inline GameState getEstado() const { return _estado; }
	
	//otros
	void Stateflow();
	void AplicarGravedad();
	bool jaquemate();
	int jaque();
	// Graficos
	void tecla_especial(unsigned char key);
	void tecla(unsigned char key);
	void dibujar();
	void mover();
	
	
	//tester
	std::ostream& printTablero (std::ostream& o = std::cout);
	std::ostream& printAmenazas (std::ostream& o = std::cout);

private:
	GameState _estado;
	Tablero _tablero;
	Jugador _j1, _j2;

	//gr�ficos
	bool HayMovimiento();
};

//tester
std::ostream& operator << (std::ostream& o, const Ajedrez& aj);
