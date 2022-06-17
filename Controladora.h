#pragma once
#include "Profesor.h"
#include "Obstaculo.h"

ref class Controladora
{
private:
	Profesor* profesor;
	Obstaculos* obstaculos;

	Bitmap^ imgSapitos;

public:
	Controladora()
	{
		imgSapitos = gcnew Bitmap("Recursos/sapitos.jpg");

		profesor = new Profesor();
		obstaculos = new Obstaculos(5, profesor->Area(), imgSapitos);
	}
	~Controladora()
	{
		delete profesor, obstaculos;
		delete imgSapitos;
	}

	void MovimientoProfesor(bool accion, Keys tecla) //True: Presionar  False: Soltar
	{
		int v = 10; //Velocidad

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
		profesor->Mostrar(g, nullptr); //ninguna imagen todavia
		obstaculos->Mostrar(g, imgSapitos);

	}
};