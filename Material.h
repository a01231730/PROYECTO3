#pragma once

#include <iostream>
#include <string>

using namespace std;

class Material
{
public:
//CONSTRUCTORES
	Material();
	Material(int idMAterial, string titulo);

//SETTERS
	void setidMaterial(int idMaterial) { this->idMaterial = idMaterial; };
	void settitulo(string titulo) { this->titulo = titulo; };

//GETTERS
	int getidMaterial() { return idMaterial; };
	string gettitulo() { return titulo; };

//ABSTRACTAS
	virtual void muestraDatos()=0;
	virtual int cantidadDiasPrestamo()=0;
	
protected:
	int idMaterial;
	string titulo;
};

Material::Material()
{
	titulo = "string";
	idMaterial = 0;
}

Material::Material(int idMaterial, string titulo)
{
	this->idMaterial = idMaterial;
	this->titulo = titulo;
}