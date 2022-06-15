#pragma once
#include "Entidad.h"

class Obstaculo : public Entidad
{
public:
	Obstaculo() //No se movera. Sera aleatorio
	{
		x = rand() % 200;
		y = rand() % 200;

		Ancho = Alto = rand() % 25 + 25; // Tamaño entre 25 y 49

	}
};

class Obstaculos //Varios obstaculos
{
private:
	vector<Obstaculo*> obstaculos;

public:
	Obstaculos(int n, Rectangle obj)
	{
		for (int i = 0; i < n; i++)
		{
			Obstaculo* obs = new Obstaculo();
			if (obs->Area().IntersectsWith(obj) == false && Colision(obs->Area()) == false)
				obstaculos.push_back(obs);
			else
			{
				delete obs;
				i--;
			}
		}
	}
	~Obstaculos()
	{
		for (int i = 0; i < obstaculos.size(); i++)
			delete obstaculos.at(i);
	}

	bool Colision(Rectangle obj)
	{
		for each (Obstaculo * obs in obstaculos)
		{
			if (obs->NextArea().IntersectsWith(obj))
				return true;
		}
		return false;
	}


	void Mover (Graphics^ g)
	{
		for each (Obstaculo* obs in obstaculos) //Por cada Obstaculo obs dentro del arreglo obstaculos
		{
			obs->Mover(g); 
		}
	}
	void Mostrar(Graphics^ g)
	{
		for (Obstaculo * obs : obstaculos)
		{
			obs->Mostrar(g);
		}
	}
};