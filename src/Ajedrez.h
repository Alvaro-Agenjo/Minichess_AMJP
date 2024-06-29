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

	//gráficos
	bool HayMovimiento();

	//?¿?¿
	Vector2D _indices{};
};

//tester
std::ostream& operator << (std::ostream& o, const Ajedrez& aj);
