#pragma once

#include "Pieza.h"

class Alfil : public Pieza
{

public:
	//Constructor
	Alfil(Casilla* coord, Color col);

	//////////////////////////////////////////
	//					OTROS				//
	//////////////////////////////////////////

	//funcion redefinida que calcula los posibles movimientos del afil
	void PosiblesMov(const std::vector<Casilla>& tab) override;

	//////////////////////////////////////////
	//			TEST POR CONSOLA			//
	//////////////////////////////////////////

	//imprime un simbolo que indica que la pieza es un alfil
	std::ostream& operator << (std::ostream& o) const override;
};

