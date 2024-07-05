#pragma once
#include "Pieza.h"
class Rey :public Pieza
{
public:
	//Constructor
	Rey(Casilla* coord, Color col);

	//////////////////////////////////////////
	//					OTROS				//
	//////////////////////////////////////////

	//funcion redefinida que calcula los posibles movimientos del rey
	void PosiblesMov(const std::vector<Casilla>& tab) override;

	//////////////////////////////////////////
	//			TEST POR CONSOLA			//
	//////////////////////////////////////////

	//imprime un simbolo que indica que la pieza es un rey
	std::ostream& operator << (std::ostream& o) const override;
};

