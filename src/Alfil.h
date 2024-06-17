#pragma once

#include "Pieza.h"

class Alfil : public Pieza
{

public:
	//Constructor
	Alfil(Casilla* coord, Color col);

	void PosiblesMov(const std::vector<Casilla>& tab) override;

	//tester
	std::ostream& operator << (std::ostream& o) const override;
private:

};

