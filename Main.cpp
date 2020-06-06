#pragma once
#include <iostream>
#include <fstream>

#include "Reserva.h"
#include "libro.h"
#include "Disco.h"
#include "Software.h"
#include "Source.h"

using namespace std;

int main()
{
    Material* Materiales[30];
    Libro Libros[30];
    Disco Discos[30];
    Software Softwares[30];
    Reserva Reservaciones[60];

    ifstream archivoE1("Material.txt");
    ifstream archivoE2("Reserva.txt");
    int idmaterial, idcliente,version;//variables integer 
    int l = 0, s = 0, d = 0, x = 0, pos = 0;//Contadores
    int idM, nP, dur, dia, mes, ani, idC;//variables cortas integer
    char letra, op;
    string titulo, autor, genero, os;



    while (archivoE1 >> idmaterial >> titulo >> letra)
    {
        if (letra == 'L' || letra == 'l')
        {
            archivoE1 >> nP >> autor;
            Libros[l].setidMaterial(idmaterial);
            Libros[l].settitulo(titulo);
            Libros[l].setnumPag(nP);
            Libros[l].setAutor(autor);
            Materiales[x] = &Libros[l];
            l++;
        }
        else if (letra == 'D' || letra == 'd')
        {
            archivoE1 >> dur >> genero;
            Discos[d].setidMaterial(idmaterial);
            Discos[d].settitulo(titulo);
            Discos[d].setDuracion(dur);
            Discos[d].setGenero(genero);
            Materiales[x] = &Discos[d];
            d++;
        }
        else if (letra == 'S' || letra == 's')
        {
            archivoE1 >> version >> os;
            Softwares[s].setidMaterial(idmaterial);
            Softwares[s].settitulo(titulo);
            Softwares[s].setVersion(version);
            Softwares[s].setSO(os);
            Materiales[x] = &Softwares[s];
            s++;
        }
        x++;
    }

    while(archivoE2>>dia>>mes>>ani>>idmaterial>>idcliente)
    {
        Fecha A(dia, mes, ani);
        Reservaciones[pos].setfechaReservacion(A);
        Reservaciones[pos].setaa(ani);
        Reservaciones[pos].setdd(dia);
        Reservaciones[pos].setmm(mes);
        Reservaciones[pos].setidMaterial(idmaterial);
        Reservaciones[pos].setidCliente(idcliente);
        pos++;
    }

    cout << "A) Consultar la lista de Materiales\nB) Consultar la lista de reservaciones\nC) Consultar las reservaciones de un material dado\nD) Consultar las reservaciones de una fecha dada\nE)Hacer una reservación\nF)Terminar" << endl;
    cout << "Consultar: ";
    cin >> op;

    while (op == 'A' || op == 'a' || op == 'B' || op == 'b' || op == 'C' || op == 'c' || op == 'D' || op == 'd' || op == 'E' || op == 'e'|| op != 'f' || op != 'F') {
        //Consultar la lista de Materiales
        if (op == 'A' || op == 'a')
        {
            for (int j = 0; j < x; j++)
            {
                cout << "Material numero " << j << ": ";
                Materiales[j]->muestraDatos();
                cout << endl;
            }
        }

        //Consultar la lista de reservaciones
        else if (op == 'B' || op == 'b')
        {
            for (int j = 0; j < pos; j++)
            {
                Fecha A;
                A = Reservaciones[j].calculaFechaFinReserva(Materiales[j]->cantidadDiasPrestamo());

                cout << "Inicio De Reservacion: " << Reservaciones[j].getfechaReservacion() << endl;
                cout << "Final De Reservacion: "<<A<<endl;
                cout << "Id De Cliente: " << Reservaciones[j].getidCliente() << endl;
                cout << "Id De Materiales: " << Reservaciones[j].getidMaterial() << endl;
                cout << endl; cout << endl;
            }
        }

        //Consultar las reservaciones de un material dado
        else if (op == 'C' || op == 'c')
        {
            cout << "\nId De Material: ";
            cin >> idM;

            for (int j = 0; j < pos; j++)
            {
                if (Materiales[j]->getidMaterial() == idM)
                {
                    cout << "\nsNombre De Material: " << Materiales[j]->gettitulo() << endl;
                    cout << "Inicio De Reservacion: " << Reservaciones[j].getfechaReservacion() << endl;
                    cout << "Final De Reservacion: "<<Reservaciones[j].calculaFechaFinReserva(Materiales[j]->cantidadDiasPrestamo());
                    cout << endl; cout << endl;
                }
            }
            exit(0);
        }

        //Consultar las reservaciones de una fecha dada
        else if (op == 'D' || op == 'd')
        {
            cout << "Dia: ";
            cin >> dia;
            cout << "Mes: ";
            cin >> mes;
            cout << "Anio: ";
            cin >> ani;

            if (dia >= 1 && dia <= 31)
            {
                if (mes >= 1 && mes <= 12)
                {
                    Fecha Inicio(dia, mes, ani);
                    for (int j = 0; j < pos; j++)
                    {
                        if (Inicio >= Reservaciones[j] && Inicio <= Reservaciones[j].calculaFechaFinReserva(Materiales[j]->cantidadDiasPrestamo()))
                        {
                            cout << "Id De Materiales: " << Reservaciones[j].getidMaterial() << endl;
                            cout << "Id De Cliente: " << Reservaciones[j].getidCliente() << endl;
                            cout << endl;
                        }
                    }
                }
            }

        }

        //Hacer una reservación
        else if (op == 'E' || op == 'e')
        {
            cout << "\nId Del Cliente: ";
            cin >> idC;
            cout << "\nId De Materiale: ";
            cin >> idM;
            for (int j = 0; j < x; j++)
            {
                if (Reservaciones[j].getidCliente() == idC)
                {
                    while (Reservaciones[j].getidMaterial() != idM)
                    {
                        cout << "El Id No Es Valido" << endl;
                        cout << "Id de Material: ";
                        cin >> idM;
                    }
                    if (Reservaciones[j].getidMaterial() == idM)
                    {
                        ////////////////////////////PENDING
                        cout << endl; cout << endl;
                    }
                }
            }
        }
        // Terminar
        else if (op == 'f' || op == 'F')
        {
            exit(0);
        }

        else if(!(op == 'A' || op == 'a' || op == 'B' || op == 'b' || op == 'C' || op == 'c' || op == 'D' || op == 'd' || op == 'E' || op == 'e'|| op == 'f' || op == 'F'))
        {
            cout << "opcion invalida" << endl;
            cout << "Consultar: ";
            cin >> op;
        }
        cout << "A) Consultar la lista de Materiales\nB) Consultar la lista de reservaciones\nC) Consultar las reservaciones de un material dado\nD) Consultar las reservaciones de una fecha dada\nE)Hacer una reservación\nF)Terminar" << endl;
        cout << "Consultar: ";
        cin >> op;
    }
    cout << endl;
    cout << "Gracias por su consulta";
    archivoE1.close();
    archivoE2.close();

}