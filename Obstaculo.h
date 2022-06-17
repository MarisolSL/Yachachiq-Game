#pragma once
#include "Entidad.h"

class Obstaculo : public Entidad
{
public:
	Obstaculo(Bitmap^ img) //No se movera. Sera aleatorio
	{
		x = rand() % 200;
		y = rand() % 200;

		Ancho = img->Width;
		Alto = img->Height; // Tamaño entre 25 y 49

	}
	void Mostrar(Graphics^ g, Bitmap^ img)
	{
		g->DrawImage(img, Area());
	}

};

class Obstaculos
{
private:
	vector<Obstaculo*> obstaculos;

public:
	Obstaculos(int n, Rectangle obj, Bitmap^ img)  //Rectangle obj para que el personaje no spawn
	{
		for (int i = 0; i < n; i++)
		{
			Obstaculo* obs = new Obstaculo(img); //Obstaculo no aparece en Personaje ni otros obs
			if (obs->Area().IntersectsWith(obj) == false && Colision(obs->Area()) == false)
				obstaculos.push_back(obs);
			else
			{
				delete obs;
				i--; //Se queda en la posicion actual
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
			if (obs->NextArea().IntersectsWith(obj)) //Intersecta con Rectangle obj
				return true; //Area() obj quietos //NetArea() obj movimiento
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
	void Mostrar(Graphics^ g, Bitmap^ img)
	{
		for (Obstaculo * obs : obstaculos)
		{
			obs->Mostrar(g, img);
		}
	}
};