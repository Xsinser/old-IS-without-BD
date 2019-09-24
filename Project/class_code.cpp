#include <string>
#include "class_trip.h"

void trip::firstgroup(int c, std::string d, std::string h, std::string ne, std::string nb, float cn)
{//присваивание переменным класс, передаваемые в метод значения
	date = d;
	hlong = h;
	name = ne;
	namber = nb;

	cena = cn;
	countp = c;
	//удаление массивов, тк они 
	delete[]f;
	delete[]o;
	delete[]i;
	delete[]dateb;
	//создание массивов нормального размера
	f = new std::string[c];
	i = new std::string[c];
	o = new std::string[c];
	dateb = new std::string[c];
}

bool trip::delpeople(int index)
{
	if( (index < countp)||(index>=0))//проверки лишними не бывают
	{
		//замена удаляемого элемента на последний элемент и уменьшение счетчика элементов на 1
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
//методы возвращающие значение
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

//проверка группы на заполненость
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

//поиск по фамилии, если передается ничего, формируется строка со всей информацией о всех членах тура, иначе только о подходящем под подбор
std::string trip::searchintogroup(std::string fi)
{
	int w;
	std::string s;
	if (fi == "")
	{
		for (w = 0; w < sizep; w++)
		{
			
			
				s = s + ("Номер в группе: " + std::to_string(w + 1) + " Фамилия: " + f[w] + " Имя: " + i[w] + " Отчество: " + o[w] + " Дата рождения: " + dateb[w] + "\n");

			
		}
	}
	else
	{
		for (w = 0; w < sizep; w++)
		{
			if ((fi == f[w]))
			{
				s = s + ("Номер в группе: " + std::to_string(w + 1) + " Фамилия: " + f[w] + " Имя: " + i[w] + " Отчество: " + o[w] + " Дата рождения: " + dateb[w] + "\n");

			}
		}
	}
	return s;
}
//добавление человека и увеличение счетчика, если группа не полная
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
//перегрузка оператора присваивания
trip & trip::operator=(const trip & trip) 
{
		//левосторонние массивы чистятся, перевыделяются
	//и в них переходят значения из правосторонних массивов
	//переменный просто присваиваются
	//после чего правосторонние освобождаются
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
		//оператор присваивания всегда доджен возвращать ссылку на объект
	return *this;
}
//деструктор очищающий память
trip::~trip() 
{
	delete[]f;
	delete[]o;
	delete[]i;
	delete[]dateb;
}
