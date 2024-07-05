#pragma once

#include "Peon.h"
#include "Torre.h"
#include "Caballo.h"
#include "Alfil.h"
#include "Reina.h"
#include "Rey.h"

#include "freeglut.h"


class Jugador
{
public:
	//////////////////////////////////////////////////////////////////////
	//				CONSTRUCTORES, ASIGNACIÓN Y DESTRUCTOR 				//
	//////////////////////////////////////////////////////////////////////
	Jugador(std::vector<Casilla>& tab, Color c);
	Jugador(const Jugador& player, std::vector<Casilla> & tab);
	Jugador& operator = (const Jugador& player);
	~Jugador();

	//////////////////////////////////////
	//				SETTERS				//
	//////////////////////////////////////
	
	//elimina la pieza cuya posicion sea la casilla introducida
	void BorrarPieza(Casilla & c);
	//elimina el movimiento indicado de la pieza indicada
	void BorrarMovimiento(int pieza, int movimiento);
	//modifica la posicion del cursor que se usa al seleccionar las piezas
	void modificarPosicion(Vector2D dir);
	inline void GRAPH_setPrimero(bool bo) { primero = bo; }
	
	//////////////////////////////////////
	//				GETTERS				//
	//////////////////////////////////////

	inline Vector2D getPosicion() const { return _pos; }
	//devuelde el índice respecto al tablero del movimiento indicado en la pieza indicada
	int getIndiceTab(int pieza, int posMov, const std::vector<Casilla>& tab);
	//devuelde el número de piezas pertenecientes al jugador
	inline int getMisPiezasSize() const { return _misPiezas.size(); }
	//devuelve el número de movimientos posibles de la pieza indicada
	inline int getPosMovSize(int pieza) const { return _misPiezas[pieza]->getPosMovSize(); }
	
	//////////////////////////////////////
	//				OTROS				//
	//////////////////////////////////////

	//calcula los posibles movimientos de todas las piezas del jugador
	void PosiblesMov( std::vector<Casilla> tab);
	//actualiza las amenazas producidas por todas sus piezas
	void ActualizarAmenazas(std::vector<Casilla>& tab);
	//realiza el proceso de selección de una pieza y su destino
	Vector2D Movimiento(const std::vector<Casilla>& tab,int &fase);
	//Actualiza la posición de la pieza y en caso de promocionar, realiza la conversion de peon a reina
	void ActualizarMovimiento(Vector2D indices, std::vector<Casilla> &tab, bool sound = true);
	//Aplica el efecto de gravedad y modifica la posicion de las piezas
	void AplicarGravedad(Casilla* cas, std::vector<Casilla>& tab);
	//indica si existe alguna pieza que este durante una animación (moviendose)
	bool HayMovimiento();
	//devuelve true si el rey esta amenazado;
	bool ComprobarJaque();

	//////////////////////////////////////////
	//				GRÁFICOS				//
	//////////////////////////////////////////
	void mover();
	void dibujar(Color c ,int tipo = 0);
	//deselecciona la pieza elegida
	void deselect(int indice_p);
	
	//////////////////////////////////////////
	//			TEST POR CONSOLA			//
	//////////////////////////////////////////
	std::ostream& print(std::ostream& o, Casilla cas) const;




private:
	//representa la posicion en el tablero del cursor de selección 
	Vector2D _pos{};
	//Vector por el cual se accede a las distintas piezas de un jugador
	std::vector<Pieza*> _misPiezas;

	//////////////////////////////////////
	//				CREACIÓN			//
	//////////////////////////////////////
	
	// añade al vector de piezas una nueva pieza del tipo y color especificado y la "coloca" en la casilla indicada
	void CrearPieza(Casilla* c, Color col, t_pieza p);
	//indica las piezas que deben crearse para cada jugador
	void CrearJugador(std::vector<Casilla> &tab, Vector2D pos_ini, Color c);

	//////////////////////////////////////
	//				SETTERS				//
	//////////////////////////////////////
	
	//cambia el puntero a casilla a otra casilla con la misma posicion pero de otro tablero
	void CambiarTablero(std::vector<Casilla>& tab);

	//////////////////////////////////////
	//				OTROS				//
	//////////////////////////////////////

	//devuelve el indice de la pieza, respecto al vector de piezas, en la posición indicada
	int ValidarPieza(Vector2D pos);
	// devuelde el indice de la casilla de destino, respecto al tablero, si esta se encuentra en el vector de posibles movimientos
	int ValidarDestino_pieza(Vector2D pos, int indice, const std::vector<Casilla>& tab);


	//////////////////////////////////////////
	//				GRÁFICOS				//
	//////////////////////////////////////////
	
	//indica si se esta seleccioando una pieza (primera fase de selección, true)
	// o un destino (segunda fse de seleción, false)
	bool primero = true;
	//dimensiones para dibujar el cursor
	float lado = 1.5;
	float espesor = 0.2;

	//dibuja el cursor dependiendo del jugador y la fase de seleccion donde se encuentre
	void dibujarCursor(Color c, bool primero = true);
};

