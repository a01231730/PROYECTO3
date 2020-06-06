#pragma once
#include <iostream>
#include <string>
#include "Material.h"

using namespace std;

class Software : public Material

{
public:

//CONSTRUCTORES
	Software();
	Software(int Version, string SO);

//SETTERS
	void setVersion(int Version) { this->Version = Version; };
	void setSO(string SO) { this->SO = SO; };

//GETTERS
	int getVersion() { return Version; };
	string getSO() { return SO; };

//VIRTUALES
	void muestraDatos();
	int cantidadDiasPrestamo();

private:
	int Version;
	string SO;
};

Software::Software():Material()
{
	Version = 0;
	SO = "micro";
}

Software::Software(int Version, string SO):Material(idMaterial, titulo)
{
	this->Version = Version;
	this->SO = SO;
}

void Software::muestraDatos()
{
	cout << "Version: " << Version<<endl;
	cout << "SO: " << SO << endl;
}

int Software::cantidadDiasPrestamo()
{
	return 2;
}
