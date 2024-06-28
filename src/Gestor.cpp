#include "Gestor.h"

Gestor::Gestor()
{

	_estado = INICIO;
}



void Gestor::teclaEspecial(unsigned char key)
{
	if (_estado == JUEGO)
	{
		if (key == GLUT_KEY_HOME)
		{
			_estado = INICIO;
			return;
		}
		_game.tecla_especial(key);
	}
}
static int counter;
void Gestor::telcla(unsigned char key)
{
	if (_estado == INICIO)
	{
		if (key > 96) key -= 32;
		switch (key)
		{
		case 'E':
		{
			AnimacionGravedad(1);
			counter = 0;
			break;
		}
		case 'I':
		{
			AnimacionGravedad(2);
			counter = 0; 
			break;
		}
		case 'S':
		{
			AnimacionGravedad(3);
			counter = 0; 
			break;
		}
		default:
			break;
		}
	}
	else if (_estado == INSTRUCCIONES)
	{
		if (key == 8)
		{
			AnimacionGravedad(0);
			counter = 0;
			_estado = INICIO;
		}
	}


	else if (_estado == JUEGO)
	{
		_game.tecla(key); 
	}
}
void Gestor::mueve(double t)
{
	if (_estado == INICIO)
	{
		_pos_peon = _pos_peon + _vel_peon * t + _accel_peon * 0.5 * t * t;
		_vel_peon = _vel_peon + _accel_peon * t;
		
		//inicio caida de texto al sobrepasar EMPEZAR [E]
		if (_pos_peon.y < 5)
		{
			counter++;
		}
		if (counter > 3)
		{
			caida++;
			counter = 0;
		}
		
		
		//comprobacion texto instrucciones alcanzado
		if (_pos_peon.y < -2 && _pos_peon.x < -5)
		{
			_estado = INSTRUCCIONES;
			AnimacionGravedad(0);
		}
		//comprobacion texto salida alcanzado
		else if (_pos_peon.y < -2 && _pos_peon.x > 5)
		{
			exit(0);
		}
		//comprobacion texto empezar alcanzado
		else if (_pos_peon.y < -2 && _pos_peon.x>-1)
		{
			_estado = JUEGO;
			AnimacionGravedad(0);
		}
	}
	else if (_estado == INSTRUCCIONES)
	{
		counter++;
		if (counter > 60 && caida < 33) 
		{
			caida++;
			counter = 0;
		}
	}
	else if (_estado == JUEGO)
	{
		_game.mover();
	}
}
void Gestor::dibuja()
{
	if (_estado == INICIO)
	{
		//AnimacionGravedad(30, 1);
		//CODIGO PARA PINTAR UNA PANTALLA NEGRA CON LETRAS 
		gluLookAt(0, 7.5, 30, // posicion del ojo 
			0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0) 
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y) 	

		//Adorno
		logopeon.setCenter(2, 0);
		logopeon.setSize(4, 6);
		logopeon.setPos(_pos_peon.x, _pos_peon.y);
		logopeon.draw();


		//color de fondo
		glBegin(GL_POLYGON);
		glColor3ub(80, 80, 0); glVertex3f(-15.0f, -5.0f, 0.0f);
		glColor3ub(150, 150, 80); glVertex3f(-15.0f, 20.0f, 0.0f);
		glColor3ub(180, 180, 100); glVertex3f(15.0f, 20.0f, 0.0f);
		glColor3ub(150, 150, 80); glVertex3f(15.0f, -5.0f, 0.0f);
		glEnd();



		//texto
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/Action Man Shaded Italic.ttf", 48);
		ETSIDI::printxy("MINICHESS", -4, 14 - (2*caida));
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/A.C.M.E. Secret Agent.ttf", 12);
		ETSIDI::printxy("EMPEZAR [E]", -1, 5 - caida);
		ETSIDI::printxy("INSTRUCCIONES [I]", -13, -2);
		ETSIDI::printxy("SALIR [S]", 11, -2);
	}
	else if (_estado == INSTRUCCIONES)
	{
		//CODIGO PARA PINTAR UNA PANTALLA NEGRA CON LETRAS 
		gluLookAt(0, 7.5, 30, // posicion del ojo 
			0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0) 
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y) 	

		//Adorno
		logopeon.setSize(8, 12);
		logopeon.setCenter(4, 6);
		logopeon.setPos(0, 7);
		logopeon.draw();

		//color de fondo
		glBegin(GL_POLYGON);
		glColor3ub(80, 80, 0); glVertex3f(-15.0f, -5.0f, 0.0f);
		glColor3ub(150, 150, 80); glVertex3f(-15.0f, 20.0f, 0.0f);
		glColor3ub(180, 180, 100); glVertex3f(15.0f, 20.0f, 0.0f);
		glColor3ub(150, 150, 80); glVertex3f(15.0f, -5.0f, 0.0f);
		glEnd();

		using ETSIDI::printxy;
		//texto
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 12);
		printxy("Bienvenido a Minichess ", -10, caida);

		printxy("En esta variante se enfrentara a una partida de ajedrez con una dificultad", -8, caida - 1);
		printxy("extra, La Gravedad. Si, ha oido bien. Tanto las piezas de su oponente como las suyas", -10, caida - 2);
		printxy("estan sometidas a una fuerza que las hara descender si no tienen algo debajo donde ", -10, caida - 3);
		printxy("soportarse.", -10, caida - 4);

		printxy("El movimiento de las piezas no ha sufrido modificaciones respecto al ajedrez", -8, caida - 8);
		printxy("clasico. En su turno podra selecionar la pieza que desee mover utilizando las flechas", -10, caida - 9);
		printxy("del teclado, esto movera una casilla iluminada que refleja la pieza que va a seleccionar.", -10, caida - 10);
		printxy("Al pulsar enter seleccionara la pieza.", -10, caida - 11);

		printxy("Una vez seleccionada, se iluminaran los posibles destinos; verde -> mover,", -8, caida - 15);
		printxy("rojo->capturar. Utilice las flechas para seleccionar el destino y enter para confirmarlo.", -10, caida - 16);
		printxy("Si desea mover otra pieza, pulse backspace y podra volver a seleccionar una.", -10, caida - 17);

		printxy("Si durante una partida desea volver al menu de inicio, pulse la tecla INICIO ", -8, caida - 20);


		printxy("Pulse BACKSPACE para regresar a la pantalla de inicio", -2, caida - 35);
	}
	else if (_estado == JUEGO)
		_game.dibujar();
}
void Gestor::Update()
{
	if (_estado == JUEGO)
	{
		_game.Stateflow();
	}
}


void Gestor::AnimacionGravedad(int destino)
{
	switch (destino)
	{
	case 1:
	{
		_vel_peon = { 0, 8 };
		_accel_peon = { 0, -9.8 };
		break;
	}
	case 2: {
		_vel_peon = { cos(60) * 8, -sin(60) * 8 };
		_accel_peon = { 0, -9.8 };
		break;
	}
	case 3:
	{
		_vel_peon = { -cos(60) * 8, -sin(60) * 8 };
		_accel_peon = { 0, -9.8 };
		break;
	}
	default:
	{
		caida = 0;
		_pos_peon = { 0,6 };
		_vel_peon = { 0,0 };
		_accel_peon = { 0, 0 };
		break;
	}
	}
}


