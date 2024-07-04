#include "Gestor.h"

Gestor::Gestor()
{
	ETSIDI::playMusica("sonidos/INICIO.mp3", true);
	Sleep(60);
	_estado = INICIO;
}



void Gestor::teclaEspecial(unsigned char key)
{
	if (_estado == JUEGO)
	{
		if (key == GLUT_KEY_HOME)
		{
			ETSIDI::stopMusica();
			ETSIDI::playMusica("sonidos/INICIO.mp3", true);
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
		
		// dedur ir a exit
		case 'F':
		{
			ETSIDI::stopMusica();
			ETSIDI::playMusica("sonidos/EXIT.mp3", true);
			_estado = EXIT;
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
			ETSIDI::stopMusica();
			ETSIDI::playMusica("sonidos/INICIO.mp3", true);
			Sleep(60);
			AnimacionGravedad(0);
			counter = 0;
			_estado = INICIO;

		}
	}
	else if (_estado == EXIT)
	{
		exit(0);
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
		_pos_cursor = _pos_cursor + _vel_cursor * t + _accel_cursor * 0.5 * t * t;
		_vel_cursor = _vel_cursor + _accel_cursor * t;

		//inicio caida de texto al sobrepasar EMPEZAR [E]
		if (_pos_cursor.y < 5)
		{
			counter++;
		}
		if (counter > 3)
		{
			caida++;
			counter = 0;
		}


		//comprobacion texto instrucciones alcanzado
		if (_pos_cursor.y < -2 && _pos_cursor.x < -5)
		{
			ETSIDI::stopMusica();
			ETSIDI::playMusica("sonidos/INSTRUCCIONES.mp3", true);
			ETSIDI::play("sonidos/poner_pieza.wav");
			//Sleep(60);
			_estado = INSTRUCCIONES;
			AnimacionGravedad(0);

		}
		//comprobacion texto salida alcanzado
		else if (_pos_cursor.y < -2 && _pos_cursor.x > 5)
		{
			ETSIDI::play("sonidos/poner_pieza.wav");
			Sleep(200);
			exit(0);
		}
		//comprobacion texto empezar alcanzado
		else if (_pos_cursor.y < -2 && _pos_cursor.x>-1)
		{
			ETSIDI::play("sonidos/poner_pieza.wav");
			ETSIDI::stopMusica();
			ETSIDI::playMusica("sonidos/JUEGO1.mp3", false);
			_estado = JUEGO;
			AnimacionGravedad(0);
			Sleep(60);
		}
	}
	else if (_estado == INSTRUCCIONES || _estado == EXIT)
	{
		counter++;
		if (counter > 60 && caida < 34)
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
		//CODIGO PARA PINTAR UNA PANTALLA NEGRA CON LETRAS 
		gluLookAt(0, 7.5, 30, // posicion del ojo 
			0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0) 
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y) 	

		//Adorno
		cursor.setCenter(2, 0);
		cursor.setSize(4, 6);
		cursor.setPos(_pos_cursor.x, _pos_cursor.y);
		cursor.draw();


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
		ETSIDI::printxy("MINICHESS", -4, 14 - (2 * caida));
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
		cursor.setSize(8, 12);
		cursor.setCenter(4, 6);
		cursor.setPos(0, 7);
		cursor.draw();

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

		printxy("Una vez seleccionada, el indicador se volvera mas claro y se iluminaran los", -8, caida - 15);
		printxy("posibles destinos; verde -> mover, azul -> capturar. Utilice las flechas para seleccionar", -10, caida - 16);
		printxy("el destino y enter para confirmarlo. Si desea mover otra pieza, pulse backspace y podra", -10, caida - 17);
		printxy("volver a seleccionar una.", -10, caida - 18);

		printxy("Si durante una partida desea volver al menu de inicio, pulse la tecla INICIO ", -8, caida - 21);


		printxy("Pulse BACKSPACE para regresar a la pantalla de inicio", -2, caida - 36);
		
	}
	else if (_estado == JUEGO)
		_game.dibujar();
	else if (_estado == EXIT)
	{
		//CODIGO PARA PINTAR UNA PANTALLA NEGRA CON LETRAS 
		gluLookAt(0, 7.5, 30, // posicion del ojo 
			0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0) 
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y) 	

		//Adorno
		cursor.setSize(8, 12);
		cursor.setCenter(4, 6);
		cursor.setPos(0, 7);
		cursor.draw();

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
		ETSIDI::setFont("fuentes/Action Man Shaded Italic.ttf", 48);
		printxy("MINICHESS", -5, caida);

		ETSIDI::setFont("fuentes/A Yummy Apology.ttf", 26);
		printxy("Habeis completado una partida de minichess, enhorabuena!!", -10, caida - 4);
		printxy("Esperamos que hayais disfrutado de la experiencia JcJ de esta variante del ", -12, caida - 5);
		printxy("clasico juego del ajedrez.", -4, caida - 6);


		printxy("Hemos estado trabajando simpre con el", -6, caida - 10);
		printxy("objetivo de crear un juego diferente, que fuera un desafio", -9, caida - 11);
		printxy("para los jugadores, algo ", -4, caida - 12);
		printxy("original. ", -1, caida - 13);


		printxy("Recientemente, hemos comenzado a trabajar para", -7, caida - 17);
		printxy("añadir la modalidad de JcE devido a los", -6, caida - 18);
		printxy("apoyos que hemos recibido de vosotros, los jugadores.", -8, caida - 19);
		printxy("Os iremos informando de nuestros progresos por los canales habituales.", -10, caida - 20);
		printxy("Gracias por elegirnos", -3, caida - 24);
		//idza
		printxy("El equipo:", -10, caida - 28);
		printxy("-Alvaro Agenjo Ortiz.", -10, caida - 29);
		printxy("-Pablo Martínez-Conde Albizu", -10, caida - 30);
		printxy("-Manuel Arteche Herrera", -10, caida - 31);

		printxy("Pulse cualquier tecla para salir", -5, caida - 36);
	}
}
void Gestor::Update()
{
	if (_estado == JUEGO)
	{
		_game.Stateflow();
		cambiarMusica();

		if (!_game.getWait() && (_game.getEstado() == B_Win || _game.getEstado() == N_Win))
		{
			_estado = EXIT;
			ETSIDI::playMusica("sonidos/EXIT.mp3", true);
		}
	}
}

void Gestor::cambiarMusica()
{
	static bool track;
	static long tiempo_inicio = 0, tiempo_actual = 0;
	tiempo_actual = ETSIDI::getMillis();

	if (tiempo_actual - tiempo_inicio > 300000)	//han pasado mas de 2 min
	{
		ETSIDI::stopMusica();
		if (track)
			ETSIDI::playMusica("sonidos/JUEGO2.mp3", false);
		else
			ETSIDI::playMusica("sonidos/JUEGO1.mp3", false);
		tiempo_inicio = tiempo_actual;
		track = !track;
	}
}


void Gestor::AnimacionGravedad(int destino)
{
	switch (destino)
	{
	case 1:
	{
		ETSIDI::play("sonidos/salto.wav");
		_vel_cursor = { 0, 8 };
		_accel_cursor = { 0, -9.8 };
		break;
	}
	case 2: {
		ETSIDI::play("sonidos/salto.wav");
		_vel_cursor = { cos(60) * 8, -sin(60) * 8 };
		_accel_cursor = { 0, -9.8 };
		break;
	}
	case 3:
	{
		ETSIDI::play("sonidos/salto.wav");
		_vel_cursor = { -cos(60) * 8, -sin(60) * 8 };
		_accel_cursor = { 0, -9.8 };
		break;
	}
	default:
	{
		caida = 0;
		_pos_cursor = { 0,6 };
		_vel_cursor = { 0,0 };
		_accel_cursor = { 0, 0 };
		break;
	}
	}
}

