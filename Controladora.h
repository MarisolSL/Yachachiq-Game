#pragma once
#include "Profesor.h"
#include "Obstaculo.h"

class Controladora
{
private:
	Profesor* profesor;
	Obstaculos* obstaculos;

public:
	Controladora()
	{
		profesor = new Profesor();
		obstaculos = new Obstaculos(5, profesor->Area());
	}
	~Controladora()
	{
		delete profesor, obstaculos;
	}

	void MovimientoProfesor(bool accion, Keys tecla)
	{
		int v = 3;

		if (accion == true)
		{
			if (tecla == Keys::Up)
				profesor->SetDY(-v);
			else if (tecla == Keys::Down)
				profesor->SetDY(v);
			else if (tecla == Keys::Left)
				profesor->SetDX(-v);
			else if (tecla == Keys::Right)
				profesor->SetDX(v);
		}
		else
		{
			if (tecla == Keys::Up)
				profesor->SetDY(0);
			else if (tecla == Keys::Down)
				profesor->SetDY(0);
			else if (tecla == Keys::Left)
				profesor->SetDX(0);
			else if (tecla == Keys::Right)
				profesor->SetDX(0);
		}
	}


	void Mover(Graphics^ g)
	{
		if (obstaculos->Colision(profesor->NextArea()) == false)
			profesor->Mover(g);
		obstaculos->Mover(g);
	}
	void Mostrar(Graphics^ g)
	{
		profesor->Mostrar(g);
		obstaculos->Mostrar(g);

	}
};