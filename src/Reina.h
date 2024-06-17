#pragma once
#include "Pieza.h"
class Reina :public Pieza
{
public:
	//Constructor
	Reina(Casilla* coord, Color col);

	void PosiblesMov(std::vector<Casilla> tab) override;

	//tester
	std::ostream& operator << (std::ostream& o) const override;
private:

};

