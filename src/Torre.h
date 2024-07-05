#pragma once

#include "Pieza.h"

class Torre : public Pieza
{
public:
	//Constructor
	Torre(Casilla* coord, Color col);

	//////////////////////////////////////////
	//					OTROS				//
	//////////////////////////////////////////

	//funcion redefinida que calcula los posibles movimientos de la torre
	void PosiblesMov(const std::vector<Casilla>& tab) override;

	//////////////////////////////////////////
	//			TEST POR CONSOLA			//
	//////////////////////////////////////////

	//imprime un simbolo que indica que la pieza es una torre
	std::ostream& operator << (std::ostream& o) const override;
};
