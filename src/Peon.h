#pragma once

#include "Pieza.h"

class Peon : public Pieza
{
public:
	//Constructor
	Peon(Casilla* coord, Color col);
	
	//////////////////////////////////////////
	//					OTROS				//
	//////////////////////////////////////////

	//funcion redefinida que calcula los posibles movimientos del caballo
	void PosiblesMov(const std::vector<Casilla>& tab) override;
	//actualiza el atributo amenazada de las casillas del tablero, solo aquellas donde puede comer
	void ActualizarTablero(std::vector<Casilla>& tab) override;
	//modifica el estado de primermov, la ocupacion y casillas (igual que el metodo del que deriva)
	//y comprueba si esta ante una situacion de promoción
	bool ActualizarPosicion(std::vector<Casilla>& tab, int indice_c, bool sound) override;
	//Comprueba si esta ante una situacion de promoción
	bool ComprobarCoronacion(int coorx) override;

	//////////////////////////////////////////
	//			TEST POR CONSOLA			//
	//////////////////////////////////////////

	//imprime un simbolo que indica que la pieza es un peon
	std::ostream& operator << (std::ostream& o) const override;

private:
	// indica si el peon no se ha movido y por tanto puede avanzar dos casillas hacia delante
	bool _primermov;
	//valida el movimiento a la casilla indicada
	bool validarCasilla(Casilla c, bool com);
};
