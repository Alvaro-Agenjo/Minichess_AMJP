#pragma once

#include "Torre.h"
#include "Caballo.h"
#include "Alfil.h"
#include "Reina.h"
#include "Rey.h"


enum class t_pieza {PEON, TORRE, CABALLO, ALFIL, REINA, REY};
class Jugador
{
public:
	//Constructor
	Jugador(std::vector<Casilla>& tab, Color c);

	//setters
	void BorrarPieza(Casilla & c);
<<<<<<< Updated upstream
	//getters

=======
	void CambiarTablero( std::vector<Casilla>& tab);

	//getters const std::vector<std::unique_ptr<SomeOtherClass>>&
	inline std::vector<Pieza*> getPiezas() { return _misPiezas; }
>>>>>>> Stashed changes
	//otros
	void PosiblesMov( std::vector<Casilla> tab);
	void ActualizarAmenazas(std::vector<Casilla>& tab);

	Vector2D Movimiento(const std::vector<Casilla>& tab);
	int ValidarPieza(Vector2D pos);
	int ValidarDestino_pieza(Vector2D pos, int indice, const std::vector<Casilla>& tab);
	
	void ActualizarMovimiento(Vector2D indices, std::vector<Casilla> &tab);
	void AplicarGravedad(Casilla* cas, std::vector<Casilla>& tab);
	//tester
	std::ostream& print(std::ostream& o, Casilla cas) const;

private:
	Vector2D _pos{};
	std::vector<Pieza*> _misPiezas;

	//Creaccion piezas
	void CrearPieza(Casilla* c, Color col, t_pieza p);
	void CrearJugador(std::vector<Casilla> &tab, Vector2D pos_ini, Color c);

};

