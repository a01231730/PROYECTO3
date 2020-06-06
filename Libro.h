#pragma once
#include <iostream>
#include <string>
#include "Material.h"

using namespace std;

class Libro :public Material
{
public:	
	
//CONSTRUCTORES
	Libro();
	Libro(int numPag, string Autor);

//SETTERS
	void setnumPag(int numPag) { this->numPag = numPag; };
	void setAutor(string Autor) { this->Autor = Autor; };

//GETTERS
	int getnumPag() { return numPag; };
	string getAutor() { return Autor; };

//VIRTUALES
	void muestraDatos();
	int cantidadDiasPrestamo();

private:
	int numPag;
	string Autor;
};

Libro::Libro():Material()
{
	numPag = 0;
	Autor = "Juna";
}

Libro::Libro(int numPag, string Autor):Material(idMaterial, titulo)
{
	this->numPag = numPag;
	this->Autor = Autor;
}

void Libro::muestraDatos()
{
	cout << "Numero Pag: " << numPag << endl;
	cout << "Autor: " << Autor << endl;
}

int Libro::cantidadDiasPrestamo()
{
	return 7;
}
