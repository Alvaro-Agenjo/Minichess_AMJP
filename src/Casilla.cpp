#include "Casilla.h"

using namespace std;

Casilla::Casilla(Vector2D coord) :
	_ocupacion(Dominio::Vacio),
	_amenaza(false),
	_comer(false),
	_mover(false),
	_coord(coord)
{}

void Casilla::ClearCasilla()
{
	_amenaza = false;
}

void Casilla::HighlightCasilla()
{
	ETSIDI::Vector2D graf_pos = (ETSIDI::Vector2D)(_coord - offset_izda) * correccion_tam;
	glDisable(GL_LIGHTING);
	if (_comer) glColor3ub(32, 153, 248);
	else if (_mover)  glColor3ub(58, 248, 32);

	glBegin(GL_QUADS);

	glVertex3f(graf_pos.x - (lado / 2.0), graf_pos.y - (lado / 2.0), 0);
	glVertex3f(graf_pos.x - (lado / 2.0), graf_pos.y + (lado / 2.0), 0);
	glVertex3f(graf_pos.x + (lado / 2.0), graf_pos.y + (lado / 2.0), 0);
	glVertex3f(graf_pos.x + (lado / 2.0), graf_pos.y - (lado / 2.0), 0);

	glEnd();
	glEnable(GL_LIGHTING);

}

std::ostream& Casilla::print(std::ostream& o) const
{
	o << (int)_ocupacion << " ";
	return o;
}

bool operator==(const Casilla& c1, const Casilla& c2)
{
	return (c1.getPosicion() == c2.getPosicion());
}
