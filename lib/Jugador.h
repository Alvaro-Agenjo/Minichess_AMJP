#pragma once

#include"Vector2D.h"
#include"Tablero.h"
#include "Interaccion.h"

#include <vector>

// Buscar la manera de eliminar la necesidad de incluir cada tipo de pieza
#include "Peon.h"
#include "Torre.h"

class Jugador
{
private:
	Vector2D _posicion;																// almacena la posicion del indicador que se usará para seleccionar el tipo de pieza, movera de forma incremental
	std::vector<Pieza*> _misPiezas{};												// vector que contiene todas las piezas del jugador, estan en forma de puntero para poder usar métodos virtuales sobrecargados para cada pieza
	Player _jugador;																// indica el numero de jugador (blancas o negras)

	static Tablero* _tablero;

public:
	

	//Constructor - Destructor
	Jugador(Vector2D pos, Player j);												//Constructor que inicializa la posicion, el idicador de jugador y rellena el vector de piezas del jugador
	static void crearTablero(Tablero* tab);
	//Getter 
	inline std::vector<Pieza*> getMisPiezas() const { return _misPiezas; };			//getter, devuelve el vector de piezas para uso en funciones ajenas a la clase jugador
	
	//Setter


	//Gráficos


	//Otros métodos 
	void Mover();																	//Función para movimiento general,llamada a sub funciones.
	int Seleccionar_pieza();														//elige la casilla de inicio, devuelve la posición de la pieza elegida en el vector de piezas.
	void Mover_pieza(int posPieza);
};
