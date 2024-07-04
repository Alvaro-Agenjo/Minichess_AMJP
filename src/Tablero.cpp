#include "Tablero.h"

Tablero::Tablero()
{
	for (int y = 0; y < filas; y++)
	{
		for (int x = 0; x < columnas; x++)
		{
			_tablero.push_back(*new Casilla({ x, y }));
		}
	}

	std::cout << "Tablero creado" << std::endl;
}

Tablero::Tablero(const Tablero& tab)
{
	*this = tab;
}

Tablero& Tablero::operator=(const Tablero& tab)
{
	if (this != &tab)
	{
		for (int n = 0; n < tab._tablero.size(); n++)
		{
			Casilla* aux = new Casilla();
			*aux = tab._tablero[n];
			_tablero.push_back(*aux);
		}
	}
	return *this;
}

Tablero::~Tablero()
{
	_tablero.clear();
}

std::vector<Casilla*> Tablero::getCasillasOcupadas()
{
	std::vector<Casilla*> cas;
	for (Casilla& c : _tablero)
	{
		if (c.getOcupacion() != Dominio::Vacio)
			cas.push_back(&c);
	}
	return cas;
}

void Tablero::ClearAmenazas()
{
	for (auto& c : _tablero)
	{
		c.ClearCasilla();
	}
}

void Tablero::dibujar()
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/Tablero.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1); glVertex3d(9, 14.8,0);
	glTexCoord2d(1, 1); glVertex3d(-6.9, 14.8,0);
	glTexCoord2d(1, 0); glVertex3d(-6.9,-1, 0);
	glTexCoord2d(0, 0); glVertex3d(9,-1,  0);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
}

