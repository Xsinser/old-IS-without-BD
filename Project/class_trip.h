#pragma once
#include <string>
static  class  trip
{

private:
	std::string date;///дата тура
	std::string hlong;///продолжительность тура
	std::string name;///название тура
	std::string namber;///номер тура
	float cena;///стоимость тура
	int sizep = 0;///количество человек в группе в данный момент
	int countp;///максимальный размер группы

	std::string *f = new std::string[1]{ " " };///массив с фамилиями
	std::string *i = new std::string[1]{ " " };///массив с именами
	std::string *o = new std::string[1]{ " " };///массив с отчествами
	std::string *dateb = new std::string[1]{ " " };///массив с датами рождения

public:

	void firstgroup(int c, std::string d, std::string h, std::string ne, std::string nb, float cn);///метод записывающий общие свединия о группе, и выделяющий память под массивы
	
	bool delpeople(int index);///метод для удаления человека из группы

	void sizetoback(int oldsize);///метод, для изменения числности группы на данный момент

	std::string returnf(int index);///возвращает конкретную фамилию
	
	std::string returni(int index);///возвращает конкретное имя

	std::string returno(int index);///возвращает конкретное отчество

	std::string returnd(int index);///возвращает конкретную дату рождения

	std::string returnname();///возвращает название группы

	std::string returnnamber();///возвращает номер группы

	float returncena();///возвращает стоимость

	std::string returnhovlong();///возвращает продолжительность

	int returnsize();///возвращает численость группы в данный момент

	std::string returndate();///возвращает дату тура

	int returncountp();///возвращает максимальную численость группы


	
	bool isfull();///проверяет группу на наличие свободных мест

	

	std::string searchintogroup(std::string fi);///поиск в группе по фамилии

	bool addpople(std::string fp, std::string ip, std::string op, std::string db);///добавляет человека в группу

	~trip();///деструктор класса для памяти выделеной для массивов

	trip & operator=(const trip & trip);///это перегрузка оператора присваивания, необходимая для сохранения всех данных при увеличении массива группу(объектов класса)
	

};