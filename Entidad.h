#pragma once
#include "Dependencias.h"

class Entidad
{
protected: //Atributos
	int x, y; //Posicion
	int dx, dy;  //Direccion
	int Ancho, Alto; //Dimensiones

public: //Metodos
	Entidad() 
	{
		x = y = 0;
		dx = dy = 0;
		Ancho = Alto = 0;
	}

	void SetDX(int value)
	{
		dx = value;
	}
	void SetDY(int value)
	{
		dy = value;
	}

	Rectangle Area ()
	{
		return Rectangle(x, y, Ancho, Alto);
	}

	Rectangle NextArea() //Area sigueinte posicion que va a tener Retangle en el tiempo
	{
		return Rectangle(x + dx, y + dy, Ancho, Alto);
	}

	//Metodo mover
	virtual void Mover(Graphics^ g) //Parametros 
	{
		x += dx;
		y += dy;

	}
	//Metodo mostrar - Dibujar
	virtual void Mostrar(Graphics^ g)
	{
		g->FillRectangle(Brushes::Black, Area());
	}
};