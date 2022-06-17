#pragma once
#include "Entidad.h"

class Profesor : public Entidad
{
public:
	Profesor()
	{
		x = 60; y = 60;
		dx = dy = 0; //El usuario empieza a mover Profesor
		Ancho = Alto = 40; //40pixeles
	}

	void Mover (Graphics^ g)
	{
		//Si la sgt posicion es >= 0 y menor que ancho pantalla
		if (x + dx >= 0 && x + Ancho + dx < g->VisibleClipBounds.Width)
			x += dx; //Entonces me puedo mover
		//Si la sgt posicion es >= 0 y menor que alto formulario
		if (y + dy >= 0 && y + Alto + dy < g->VisibleClipBounds.Height)
			y += dy; //Entonces me puedo mover
	
	}
	void Mostrar(Graphics^ g, Bitmap^ img)
	{
		g->FillRectangle(Brushes::Green, Area());
	}
};