#pragma once
#include "Pieza.h"
class Reina :public Pieza
{
public:
	//Constructor
	Reina(Casilla* coord, Color col);

	//////////////////////////////////////////
	//					OTROS				//
	//////////////////////////////////////////

	//funcion redefinida que calcula los posibles movimientos de la reina
	void PosiblesMov(const std::vector<Casilla>& tab) override;

	//////////////////////////////////////////
	//			TEST POR CONSOLA			//
	//////////////////////////////////////////

	//imprime un simbolo que indica que la pieza es una reina
	std::ostream& operator << (std::ostream& o) const override;
};

