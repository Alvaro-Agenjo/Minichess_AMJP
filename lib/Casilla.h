#pragma once

#include"Vector2D.h"

class Casilla
{
private:
	Vector2D _posicion{};																	//almacena coordenadas x,y de la posicion de la casilla
	int _ocupacion;																		// puntero a la pieza que se halla sobre la casilla (nullprt si esta vacia)
	bool _atacada;																			//indicador de casilla amenazada encontrar piezas clavadas o de movimiento inválido
	bool _puede_mover;																	// admite que una pieza se mueva a la casilla
public:
	//Constructor - Destructor
	Casilla() { _posicion = { 0,0 }; _ocupacion = 0; _atacada = false; _puede_mover = false; }				//Constructor por defecto

	//Setter
	inline void setPosicion(Vector2D coord) { _posicion = coord; }							//setter de coordenadas de casilla, utilizado para inicializar valor debido a que se crearon en conjunto
	inline void setOcupacion(int ocupa) { _ocupacion = ocupa; }							//setter para moficiar la pieza que se halla en la casilla
	inline void setAtacada(bool attack) { _atacada = attack; }
	inline void setPuedeMover(bool mov) { _puede_mover = mov; }
	//Getter
	inline int getOcupacion() { return _ocupacion; };											//getter devuelde la pieza que está en la casilla
	inline Vector2D getPosicion() { return _posicion; }
	inline bool getAtacada() {return _atacada; }
	inline bool getPuedeMover() { return _puede_mover; }
	// Otros métodos 
	void clearCasilla();																	//restaura los valores predeterminados de la casilla (libre y sin ser atacada)
	
	//Métodos gráficos 
	void dibujar();																			//sin implementar por ahora


	/************************************************************************************
	*								visualizacion tests									*
	************************************************************************************/

	void verPiezas();

};
