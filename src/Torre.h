#pragma once

#include "Pieza.h"

class Torre :   public Pieza
{
public:
	//Constructor
	Torre(Casilla* coord, Color col);

	void PosiblesMov(std::vector<Casilla> tab) override;

private:

};

