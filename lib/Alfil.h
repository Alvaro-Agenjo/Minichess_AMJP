#pragma once

#include "Pieza.h"
class Alfil : public Pieza  //Alfil es heredero de Pieza
{
private:


public:

	//Constructor - Destructor
	Alfil(Vector2D pos, Player j);			//Constructor de la pieza Alfil, accede al constructor de pieza 

	//setter

	//getter
	inline int getTipoPieza() override { return _tpieza; }
	//otros metodos
	void reglasMovimiento() override;
	//gráficos
};

//class Alfil : public Pieza
//{
//private:
//
//
//public:
//
//	//Constructor - Destructor
//	Alfil(Vector2D pos, Player j);			//Constructor de la pieza peon, accede al constructor de pieza 
//
//	//setter
//
//	//getter
//	inline int getTipoPieza() override { return _tpieza; }
//	//otros metodos
//
//	void ver_opciones(Pieza* a_mover) {
//		int n = a_mover->_posicion.x;
//		int m = a_mover->_posicion.y;
//
//		bool rep;
//		//angulo de 45º
//		do {
//			int aux = _tablero[n+1][m+1].getOcupacion();	// obtiene el puntero a pieza almacenado en cada casilla
//			n += 1;
//			if (aux != 0) {
//				std::cout << "La casilla (" << n<<"," << n << ") está vacía\n";
//			}
//			n++;
//		} while (rep);
//		//angulo de 135º
//		int n = 1;
//		do {
//			rep = validarCasillas(dim, tab, _coordX - n, _coordY + n);
//			n++;
//		} while (rep);
//		//angulo de 225º
//		int n = 1;
//		do {
//			rep = validarCasillas(dim, tab, _coordX - n, _coordY - n);
//			n++;
//		} while (rep);
//		//angulo de 315º
//		int n = 1;
//		do {
//			rep = validarCasillas(dim, tab, _coordX + n, _coordY - n);
//			n++;
//		} while (rep);
//	}
//	//gráficos
//};
//
