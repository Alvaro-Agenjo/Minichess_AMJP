//#include <iostream>
//#include "Ajedrez.h"
//
//using namespace std;
//
//int main()
//{
//	// Test dupicacion de tablero y jugadores
//	Ajedrez a;
//	Tablero t, t2{ t };
//	Jugador p(t.getTablero(), Color::Blanco);
//	
//	Jugador p2(p, t2.getTablero());
//	
//	/////////////////////////////////////////////////////////////////
//	// movimiento en original,  sin fallos
//	/////////////////////////////////////////////////////////////////
//	std::ostream& o = std::cout;
//	int n = 0;
//	std::cout << std::endl;
//	std::cout << std::endl;
//	for (const Casilla& cas : t.getTableroConst())
//	{
//		if (cas.getOcupacion() == Dominio::Vacio)
//		{
//			cas.print(o);
//		}
//		else if (cas.getOcupacion() == Dominio::Blanca)
//		{
//			p.print(o, cas);
//		}
//		else p.print(o, cas);
//
//		//separacion cada 8 casillas
//		n++;
//		if (n == 8)
//		{
//			o << std::endl;
//			n = 0;
//		}
//	}
//	std::cout << std::endl;
//	n = 0;
//	for (const Casilla& cas : t2.getTableroConst())
//	{
//		if (cas.getOcupacion() == Dominio::Vacio)
//		{
//			cas.print(o);
//		}
//		else if (cas.getOcupacion() == Dominio::Blanca)
//		{
//			p2.print(o, cas);
//		}
//		else p2.print(o, cas);
//
//		//separacion cada 8 casillas
//		n++;
//		if (n == 8)
//		{
//			o << std::endl;
//			n = 0;
//		}
//	}
//	std::cout << std::endl;
//	std::cout << std::endl;
//	
//
//
//	t.ClearAmenazas();
//	p.PosiblesMov(t.getTableroConst());
//	p.ActualizarMovimiento({8,3}, t.getTablero());
//	a.AplicarGravedad(t, p, p);
//	n = 0;
//	std::cout << std::endl;
//	std::cout << std::endl;
//	for (const Casilla& cas : t.getTableroConst())
//	{
//		if (cas.getOcupacion() == Dominio::Vacio)
//		{
//			cas.print(o);
//		}
//		else if (cas.getOcupacion() == Dominio::Blanca)
//		{
//			p.print(o, cas);
//		}
//		else p.print(o, cas);
//
//		//separacion cada 8 casillas
//		n++;
//		if (n == 8)
//		{
//			o << std::endl;
//			n = 0;
//		}
//	}
//	std::cout << std::endl;
//	n = 0;
//	for (const Casilla& cas : t2.getTableroConst())
//	{
//		if (cas.getOcupacion() == Dominio::Vacio)
//		{
//			cas.print(o);
//		}
//		else if (cas.getOcupacion() == Dominio::Blanca)
//		{
//			p2.print(o, cas);
//		}
//		else p2.print(o, cas);
//
//		//separacion cada 8 casillas
//		n++;
//		if (n == 8)
//		{
//			o << std::endl;
//			n = 0;
//		}
//	}
//	std::cout << std::endl;
//	std::cout << std::endl;
//
//
//	t2.ClearAmenazas();
//	p2.PosiblesMov(t2.getTableroConst());
//	p2.ActualizarMovimiento({ 15,59 }, t2.getTablero());
//	a.AplicarGravedad(t2, p2, p2);
//	n = 0;
//	std::cout << std::endl;
//	std::cout << std::endl;
//	for (const Casilla& cas : t.getTableroConst())
//	{
//		if (cas.getOcupacion() == Dominio::Vacio)
//		{
//			cas.print(o);
//		}
//		else if (cas.getOcupacion() == Dominio::Blanca)
//		{
//			p.print(o, cas);
//		}
//		else p.print(o, cas);
//
//		//separacion cada 8 casillas
//		n++;
//		if (n == 8)
//		{
//			o << std::endl;
//			n = 0;
//		}
//	}
//	std::cout << std::endl;
//	n = 0;
//	for (const Casilla& cas : t2.getTableroConst())
//	{
//		if (cas.getOcupacion() == Dominio::Vacio)
//		{
//			cas.print(o);
//		}
//		else if (cas.getOcupacion() == Dominio::Blanca)
//		{
//			p2.print(o, cas);
//		}
//		else p2.print(o, cas);
//
//		//separacion cada 8 casillas
//		n++;
//		if (n == 8)
//		{
//			o << std::endl;
//			n = 0;
//		}
//	}
//	std::cout << std::endl;
//	std::cout << std::endl;
//
//	/*
//	// Test ajedrez
//	
//	Ajedrez game;
//	bool continuar;
//	
//	do
//	{
//		//Rellenar amenazas
//		game.Stateflow();
//		game.printTablero() << endl;
//		game.printAmenazas() << endl;
//
//		//Seleccionar movimiento
//		game.Stateflow();
//		
//		//Visualizacion movimiento
//		game.Stateflow();
//		game.printTablero() << endl;
//		
//
//		//Jaque?
//		game.Stateflow();
//
//		cout << "Desea continuar?" << endl;
//		cout << "[0] No\t[1] Si" << endl;
//		cin >> continuar;
//		cout << endl << endl << endl;
//	} while (continuar);
//	
//	return 0;
//	*/
//}