#pragma once
#include <iostream>
#include <string>
#include "Material.h"
using namespace std;

class Disco : public Material
{
public:

//CONSTRUCTORES
	Disco();
	Disco(int duracion, string genero);

//SETTERS
	void setDuracion(int duracion) { this->duracion = duracion; };
	void setGenero(string Genero) { this->Genero = Genero; };

//GETTERS
	int getDuracion() { return duracion; };
	string getGenero() { return Genero; };

//VIRTUALES
	void muestraDatos();
	int cantidadDiasPrestamo();

private:
	int duracion;
	string Genero;
};

Disco::Disco():Material()
{
	duracion = 0;
	Genero = "nada";
}

Disco::Disco(int duracion, string genero):Material(idMaterial, titulo)
{
	this->duracion = duracion;
	this->Genero = Genero;
}

void Disco::muestraDatos()
{
	cout << "Duracion: " << duracion<< endl;
	cout << "Genero: " << Genero<<endl;
	cout << endl;
}

int Disco::cantidadDiasPrestamo()
{
	return 1;
}