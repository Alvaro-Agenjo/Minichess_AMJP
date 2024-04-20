#include "Interaccion.h"

void Interaccion::almacenarEnTablero(const Pieza& p, Tablero *t)
{
    t->_tablero[p._posicion.y][p._posicion.x].setOcupacion(p._tpieza);
}
