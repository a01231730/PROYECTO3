#pragma once
#include <iostream>
#include <string>

using namespace std;

class Fecha
{
public:
//CONSTRUCTORES
	Fecha();
	Fecha(int dd, int mm, int aa);

//SETTERS
	void setdd(int dd) { this->dd = dd; };
	void setmm(int mm) { this->mm = mm; };
	void setaa(int aa) { this->aa = aa; };

//GETTERS
	int getdd() { return dd; };
	int getmm() { return mm; };
	int getaa() { return aa; };

//EXTRAS
	void setFecha(int dd, int mm, int aa) {this->dd = dd; this->mm = mm; this->aa = aa;};

//OVERLOADED OERATORS
	Fecha operator+(int x);
	int operator>=(Fecha x);
	int operator<=(Fecha x);
	int operator==(Fecha x);
	int operator>(Fecha x);
	int operator<(Fecha x);

	friend ostream& operator<<(ostream& os, Fecha x);
	friend istream& operator>>(istream& os, Fecha &x);

//EXTRAS
	string nombreMes();

protected:
	int dd, mm, aa;
};

Fecha::Fecha()
{
	dd = 0;
	mm = 0;
	aa = 0;
}

Fecha::Fecha(int dd, int mm, int aa) 
{
	this->dd = dd;
	this->mm = mm;
	this->aa = aa;
}

Fecha Fecha :: operator+(int x)
{
	int dias = dd + x;
	if(mm == 4|| mm == 6 || mm == 9 || mm == 11)
	{
		if (dias>30)
		{
			mm++;
			dias -= 30;
		}
	}
	else if(mm == 1|| mm == 3|| mm==5 || mm == 7 || mm == 8 || mm == 10 || mm == 12)
	{
		if( dias>31)
		{
			mm++;
			dias -= 31;
		}
	}
	else if(mm == 2)
	{
		if(dias>28)
		{
			mm++;
			dias -= 29;
		}
	}
	return Fecha(dias, mm, aa);
}

int Fecha :: operator>=(Fecha x)
{
	if ((aa >= x.aa) || (aa >= x.aa && mm >= x.aa)||(aa >= x.aa && mm >= x.aa && dd >= x.dd))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int Fecha :: operator<=(Fecha x)
{
	if ((aa <= x.aa) || (aa <= x.aa && mm <= x.aa) || (aa <= x.aa && mm <= x.aa && dd <= x.dd)) 
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int Fecha :: operator==(Fecha x)
{
	if ((aa == x.aa) || (aa == x.aa && mm == x.aa) || (aa == x.aa && mm == x.aa && dd == x.dd))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int Fecha :: operator>(Fecha x)
{
	if ((aa > x.aa) || (aa > x.aa && mm > x.aa) || (aa > x.aa && mm > x.aa && dd > x.dd))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int Fecha :: operator < (Fecha x)
{
	if ((aa < x.aa) || (aa < x.aa && mm < x.aa) || (aa < x.aa && mm < x.aa && dd < x.dd))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

ostream &operator <<(ostream& os, Fecha x)
{
	os << x.dd << "/" << x.mm << "/" << x.aa;
	return os;
}

istream &operator >>(istream& os, Fecha &x)
{
	cout << "Dia: ";
	os >> x.dd; cout << endl;
	cout << "Mes: ";
	os >> x.mm; cout << endl;
	cout << "Anio: ";
	os >> x.aa;cout <<endl;
	return os;
}

string Fecha::nombreMes()
{
	switch (mm)
	{
	case  1:
		return "Ene";
		break;
	case  2:
		return "Feb";
		break;
	case  3:
		return "Mar";
		break;
	case  4:
		return "Abr";
		break;
	case  5:
		return "May";
		break;
	case  6:
		return "Jun";
		break;
	case  7:
		return "Jul";
		break;
	case  8:
		return "Ago";
		break;
	case  9:
		return "Sep";
		break;
	case 10:
		return "Oct";
		break;
	case 11:
		return "Nov";
		break;
	case 12:
		return "Dic";
		break;
	}
}