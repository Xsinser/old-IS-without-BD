#include <string>
#include "class_trip.h"

void trip::firstgroup(int c, std::string d, std::string h, std::string ne, std::string nb, float cn)
{//������������ ���������� �����, ������������ � ����� ��������
	date = d;
	hlong = h;
	name = ne;
	namber = nb;

	cena = cn;
	countp = c;
	//�������� ��������, �� ��� 
	delete[]f;
	delete[]o;
	delete[]i;
	delete[]dateb;
	//�������� �������� ����������� �������
	f = new std::string[c];
	i = new std::string[c];
	o = new std::string[c];
	dateb = new std::string[c];
}

bool trip::delpeople(int index)
{
	if( (index < countp)||(index>=0))//�������� ������� �� ������
	{
		//������ ���������� �������� �� ��������� ������� � ���������� �������� ��������� �� 1
		f[index] = f[sizep - 1];
		i[index] = i[sizep - 1];
		o[index] = o[sizep - 1];
		dateb[index] = dateb[sizep - 1];
		sizep--;
		return true;
	}
	else
	{
		return false;
	}
}
//������ ������������ ��������
void trip::sizetoback(int oldsize)
{
	sizep = oldsize;
}

std::string trip::returni(int index)
{
	return i[index];
}

std::string trip::returno(int index)
{
	return o[index];
}

std::string trip::returnname()
{
	return name;
}

std::string trip::returnnamber()
{
	return namber;
}

int trip::returncountp()
{
	return countp;
}

float trip::returncena()
{
	return cena;
}

std::string trip::returnhovlong()
{
	return hlong;
}

std::string trip::returndate()
{
	return date;
}

int trip::returnsize()
{
	return sizep;
}

//�������� ������ �� ������������
bool trip::isfull()
{
	if ((countp - sizep) > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

std::string trip::returnf(int index)
{
	return f[index];
}

std::string trip::returnd(int index)
{
	return dateb[index];
}

//����� �� �������, ���� ���������� ������, ����������� ������ �� ���� ����������� � ���� ������ ����, ����� ������ � ���������� ��� ������
std::string trip::searchintogroup(std::string fi)
{
	int w;
	std::string s;
	if (fi == "")
	{
		for (w = 0; w < sizep; w++)
		{
			
			
				s = s + ("����� � ������: " + std::to_string(w + 1) + " �������: " + f[w] + " ���: " + i[w] + " ��������: " + o[w] + " ���� ��������: " + dateb[w] + "\n");

			
		}
	}
	else
	{
		for (w = 0; w < sizep; w++)
		{
			if ((fi == f[w]))
			{
				s = s + ("����� � ������: " + std::to_string(w + 1) + " �������: " + f[w] + " ���: " + i[w] + " ��������: " + o[w] + " ���� ��������: " + dateb[w] + "\n");

			}
		}
	}
	return s;
}
//���������� �������� � ���������� ��������, ���� ������ �� ������
bool trip::addpople(std::string fp, std::string ip, std::string op, std::string db)
{
	if (sizep < countp)
	{
		f[sizep] = fp;
		i[sizep] = ip;
		o[sizep] = op;
		dateb[sizep] = db;
		sizep++;
		return true;
	}
	else
		return false;
}
//���������� ��������� ������������
trip & trip::operator=(const trip & trip) 
{
		//������������� ������� ��������, ��������������
	//� � ��� ��������� �������� �� �������������� ��������
	//���������� ������ �������������
	//����� ���� �������������� �������������
	delete[]f;
	delete[]o;
	delete[]i;
	delete[]dateb;

		sizep = trip.sizep;
		hlong = trip.hlong;
		namber = trip.namber;
		name = trip.name;
		countp = trip.countp;
		cena = trip.cena;
		date = trip.date;
		f = new std::string[countp];
		o = new std::string[countp];
		i = new std::string[countp];
		dateb = new std::string[countp];
		for (int in = 0; in < countp; in++)
		{
			f[in] = trip.f[in];
			o[in] = trip.o[in];
			i[in] = trip.i[in];
			dateb[in] = trip.dateb[in];
		}
		//�������� ������������ ������ ������ ���������� ������ �� ������
	return *this;
}
//���������� ��������� ������
trip::~trip() 
{
	delete[]f;
	delete[]o;
	delete[]i;
	delete[]dateb;
}
