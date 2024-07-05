#pragma once
#include "Pieza.h"
class Caballo :public Pieza
{
public:
	//Constructor
	Caballo(Casilla* coord, Color col);
	
	//////////////////////////////////////////
	//					OTROS				//
	//////////////////////////////////////////

	//funcion redefinida que calcula los posibles movimientos del caballo
	void PosiblesMov(const std::vector<Casilla>& tab) override;

	//////////////////////////////////////////
	//			TEST POR CONSOLA			//
	//////////////////////////////////////////

	//imprime un simbolo que indica que la pieza es un caballo
	std::ostream& operator << (std::ostream& o) const override;
};

