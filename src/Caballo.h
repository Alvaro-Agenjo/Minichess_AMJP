#pragma once
#include "Pieza.h"
class Caballo :public Pieza
{
public:
	//Constructor
	Caballo(Casilla* coord, Color col);
	
	void PosiblesMov(const std::vector<Casilla> &tab) override;

	//tester
	std::ostream& operator << (std::ostream& o) const override;
private:

};

