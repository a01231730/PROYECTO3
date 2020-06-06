#pragma once
#include <iostream>
#include <string>
#include "Fecha.h"
using namespace std;

class Reserva : public Fecha
{
public:
//CONSTRUCTORES
	Reserva();
	Reserva(int idMaterial, int idCliente, Fecha fechaReservacion);

//SETTERS
	void setidMaterial(int idMaterial) { this->idMaterial = idMaterial; };
	void setidCliente(int idCliente) { this->idCliente = idCliente; };
	void setfechaReservacion(Fecha fechaReservacion) { this->fechaReservacion = fechaReservacion; };

//GETTERS
	int getidMaterial() { return idMaterial; };
	int getidCliente() { return idCliente; };
	Fecha getfechaReservacion() { return fechaReservacion; };

//EXTRAS
	Fecha calculaFechaFinReserva(int cantDias);

private:
	int idMaterial, idCliente;
	Fecha fechaReservacion;
};

Reserva::Reserva() : Fecha()
{
	idMaterial = 0;
	idCliente = 0;
	Fecha fecha(0, 0, 0);
	fechaReservacion = fecha;
}

Reserva::Reserva(int idMaterial, int idCliente, Fecha fechaReservacion) : Fecha(dd, mm, aa)
{
	this->idMaterial = idMaterial; 
	this->idCliente = idCliente;
	this->fechaReservacion = fechaReservacion;
}

Fecha Reserva :: calculaFechaFinReserva(int cantDias)
{
	return fechaReservacion + cantDias;
}