#pragma once
#include "Casilla.h"
#include <vector>


constexpr Vector2D NORTE = { 0,1 };
constexpr Vector2D SUR = { 0,-1 };
constexpr Vector2D ESTE = { 1,0 };
constexpr Vector2D OESTE = { -1,0 };
constexpr Vector2D NORESTE = { 1,1 };
constexpr Vector2D NOROESTE = { -1,1 };
constexpr Vector2D SUDESTE = { 1,-1 };
constexpr Vector2D SUDOESTE = { -1,-1 };

constexpr Vector2D out_of_bounds = { -1,-1 };


enum class Color { Blanco = 1, Negro = -1 };
enum class t_pieza { PEON, TORRE, CABALLO, ALFIL, REINA, REY };


class Pieza
{
public:
	//Constructor
	Pieza(Casilla* cas, Color col, t_pieza tp);
	
	//////////////////////////////////////
	//				GETTERS				//
	//////////////////////////////////////

	inline Casilla* getCasilla() const { return _myCasilla; }
	inline Color getColor() const { return _color; }
	inline t_pieza getT_Pieza() const { return _t_pieza; }
	inline bool getEn_Mov() const { return en_mov; }
	inline int getPosMovSize() const { return _posiblesMov.size(); }
	inline bool getSelected() const { return selected; }
	//devuelve el indice de la casilla destino del movimiento indicado respecto al tablero
	int getIndiceTab(int posMov, const std::vector<Casilla>& tab);
	
	//////////////////////////////////////////////
	//					Setters					//
	//////////////////////////////////////////////
	
	//borra _posiblesMov
	inline void Clear() { _posiblesMov.clear(); }
	//borra un movimiento concreto
	void BorrarMovimiento(int movimiento);
	//modifica la casilla
	inline void setCasilla(Casilla* c) { _myCasilla = c; }
	//modifica el flag selected
	inline void setSelected(bool sel) { selected = sel; }
	
	//////////////////////////////////////
	//				OTROS				//
	//////////////////////////////////////
	
	//calcula los posibles movimientos de una pieza, redefinido para cada tipo de pieza
	virtual void PosiblesMov(const std::vector<Casilla>& tab) = 0;
	//actualiza las amenazas del tablero (todo excepto peon amenaza donde puede moverse)
	virtual void ActualizarTablero(std::vector<Casilla>& tab);
	inline virtual bool ComprobarCoronacion(int coorx) { return false; }
	//si existe devuelve la posicion respecto al tablero de la casilla con las coordenadas especificadas
	int ValidarDestino(Vector2D pos, const std::vector<Casilla>& tab);
	//actualiza la ocupacion de las casillas involucradas en el movimiento 
	//y la referencia a casilla de la pieza que se mueve.
	virtual bool ActualizarPosicion(std::vector<Casilla>& tab, int indice_c, bool sound);
	//actualiza la ocupacion de las casillas involucradas en el movimiento 
	//y la referencia a casilla de la pieza que se mueve.
	void ActualizarPosicion(Casilla* c);
	//aplica la gravedad haciendo descender a la pieza si no tiene otra pieza debajo o esta en el borde inferior del tablero
	void Gravedad(std::vector<Casilla>& tab);
	
	
	
	//////////////////////////////////////////
	//				GRÁFICOS				//
	//////////////////////////////////////////
	void mover(double t);
	void dibujar();
	
	//////////////////////////////////////////
	//			TEST POR CONSOLA			//
	//////////////////////////////////////////
	virtual std::ostream& operator << (std::ostream& o) const = 0;

protected:
	
	//indica el color de la piezas (blanco o negro)
	Color _color;
	//referencia a la casilla donde esta la pieza
	Casilla* _myCasilla;
	//vector de posibles movimientos
	std::vector<Casilla> _posiblesMov;
	//indicador tipo de pieza
	t_pieza _t_pieza;

	//////////////////////////////////////
	//				OTROS				//
	//////////////////////////////////////
	
	//devuelve true si el movimiento realizado es posible y lo añade al vetor de posibles movimientos
	bool validarCasilla(const Casilla destino);

	//////////////////////////////////////
	//				GETTERS				//
	//////////////////////////////////////

	//devuelve una copia de la casilla que se encuentra en la direccion indicada desde la casilla de origen
	Casilla getCasilla_copia(Casilla origen, Vector2D direccion, const std::vector<Casilla>& tab);
	//devuelve una referencia de la casilla que se encuentra en la direccion indicada desde la casilla de origen
	Casilla* getCasilla_ref(Casilla origen, Vector2D direccion, std::vector<Casilla>& tab);
	//devuelve el indice de la casilla en la posicion indicada respecto al tablero
	int IndiceCasilla(const Vector2D pos, const std::vector<Casilla>& tab);

	//flag indica si ha encontrado una pieza enemiga a la que puede atacar
	//por lo que no debe continuar buscando 
	static bool p1;  
	inline static void ResetP1() { p1 = false; }


	//////////////////////////////////////////
	//				GRÁFICOS				//
	//////////////////////////////////////////
	
	ETSIDI::Vector2D _posicion{};
	ETSIDI::Vector2D _velocidad{};
	ETSIDI::Vector2D _aceleracion{};
	ETSIDI::Sprite _pieza;

	//indica si la pieza ha sido seleccionada (usada para la lógic del cursor del jugador)
	bool selected = false;
	//indica si la pieza esta realizando una animación
	bool en_mov = false;
	
	//da los valores iniciales a los vectores de características cinemáticas según el escenario
	//caida o desplazamiento
	void calcularMovimiento(Vector2D inicio, Vector2D destino, bool caida = true, bool sound);
	//calcula la situación de parada de una animación (cuando esta suficientemente cerca)
	// y modifica las características cinemáticas acorde al resultado
	bool distancia();
	//selecciona la apariencia del Sprite de la pieza
	void SelectApariencia();
};
//////////////////////////////////////////
//				OPERADORES				//
//////////////////////////////////////////
bool operator == (const Dominio& d, const Color& c);
bool operator != (const Dominio& d, const Color& c);