#pragma once
#include <string>
static  class  trip
{

private:
	std::string date;///���� ����
	std::string hlong;///����������������� ����
	std::string name;///�������� ����
	std::string namber;///����� ����
	float cena;///��������� ����
	int sizep = 0;///���������� ������� � ������ � ������ ������
	int countp;///������������ ������ ������

	std::string *f = new std::string[1]{ " " };///������ � ���������
	std::string *i = new std::string[1]{ " " };///������ � �������
	std::string *o = new std::string[1]{ " " };///������ � ����������
	std::string *dateb = new std::string[1]{ " " };///������ � ������ ��������

public:

	void firstgroup(int c, std::string d, std::string h, std::string ne, std::string nb, float cn);///����� ������������ ����� �������� � ������, � ���������� ������ ��� �������
	
	bool delpeople(int index);///����� ��� �������� �������� �� ������

	void sizetoback(int oldsize);///�����, ��� ��������� ��������� ������ �� ������ ������

	std::string returnf(int index);///���������� ���������� �������
	
	std::string returni(int index);///���������� ���������� ���

	std::string returno(int index);///���������� ���������� ��������

	std::string returnd(int index);///���������� ���������� ���� ��������

	std::string returnname();///���������� �������� ������

	std::string returnnamber();///���������� ����� ������

	float returncena();///���������� ���������

	std::string returnhovlong();///���������� �����������������

	int returnsize();///���������� ���������� ������ � ������ ������

	std::string returndate();///���������� ���� ����

	int returncountp();///���������� ������������ ���������� ������


	
	bool isfull();///��������� ������ �� ������� ��������� ����

	

	std::string searchintogroup(std::string fi);///����� � ������ �� �������

	bool addpople(std::string fp, std::string ip, std::string op, std::string db);///��������� �������� � ������

	~trip();///���������� ������ ��� ������ ��������� ��� ��������

	trip & operator=(const trip & trip);///��� ���������� ��������� ������������, ����������� ��� ���������� ���� ������ ��� ���������� ������� ������(�������� ������)
	

};