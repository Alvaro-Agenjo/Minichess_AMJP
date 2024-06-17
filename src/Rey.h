#pragma once
#include "Pieza.h"
class Rey :public Pieza
{
public:
	//Constructor
	Rey(Casilla* coord, Color col);

	void PosiblesMov(std::vector<Casilla> tab) override;

	//tester
	std::ostream& operator << (std::ostream& o) const override;
private:

};

