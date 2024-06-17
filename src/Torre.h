#pragma once

#include "Pieza.h"

class Torre : public Pieza
{
public:
	//Constructor
	Torre(Casilla* coord, Color col);

	void PosiblesMov(std::vector<Casilla> tab) override;

	//tester
	std::ostream& operator << (std::ostream& o) const override;
private:

};
