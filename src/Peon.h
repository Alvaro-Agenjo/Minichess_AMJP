#pragma once

#include "Pieza.h"

class Peon : public Pieza
{
public:
	//Constructor
	Peon(Casilla* coord, Color col);
	
	
	//getters
	
	//seters
	
	//otros
	void PosiblesMov(const std::vector<Casilla>& tab) override;
	void ActualizarTablero(std::vector<Casilla>& tab) override;

	bool ActualizarPosicion(std::vector<Casilla>& tab, int indice_c) override;
	bool ComprobarCoronacion(int coorx) override;
	//tester
	std::ostream& operator << (std::ostream& o) const override;
private:
	bool _primermov;

	void validarCasilla(Casilla c, bool com);
};
