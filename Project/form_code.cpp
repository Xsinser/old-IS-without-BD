#include <string>///строки
#include "class_trip.h"///класс
#include <cstdlib>
#include <fstream>
#include <ctime>///для получения времени
#include <iostream>
#include "MyForm.h"


using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


bool float_length_test(int first, int le_ngth)
{
	if (le_ngth - first-1 <= 2)
	{
		return true;
	}
	else
	{
		return false;
	}
}


bool cena_string_test(std::string str)//проверка строки на число, если хоть одна буква есть, то строка не считается числом
{
	bool k = true;
	int dot = 0;
	for (int i = 0; i < str.length(); i++)
	{
		if ((isdigit(str[i])) || (str[i] == ','))
		{
			k = true;
			if (dot > 1)
			{
				k = false;
				break;
			}

			if (str[i] == ',')
				dot++;

			if ((str[i] == ','))
			{
				if (!(float_length_test(i, str.length())))
				{
					k = false;
					break;
				}
			}
		}
		else
		{
			k = false;
			break;
		}
	}
	return k;
}

//функция проверки всех числовых полей на 1 странице
bool Project::MyForm::firstpagetest()
{
	
	if (!((textBox1->Text == "") || (textBox2->Text == "") || (textBox4->Text == "") || (textBox5->Text == "") || (textBox3->Text == "")))//проверка на пустоту
	{
		if (textBox1->Text->Length > 8)
		{
			MessageBox::Show("Числовое значение размера группы слишком велико!");
			return false;
		}
		else if (Convert::ToInt32(textBox1->Text) > 2000000)
		{
			MessageBox::Show("Числовое значение размера группы слишком велико!");
			return false;
		}
		if (cena_string_test(stdconvert(textBox2->Text)))
		{
			if ((textBox2->Text->Length > 9))
			{
				MessageBox::Show("Числовое значение стоимости слишком велико!");
				return false;
			}
			else if (Convert::ToDouble(textBox2->Text) > 2000000)
			{
				MessageBox::Show("Числовое значение стоимости слишком велико!");
				return false;
			}
		}
		else
		{
			MessageBox::Show("Поле Стоимости имело неверный формат!");
			return false;
		}
		if (textBox4->Text->Length > 8)
		{
			MessageBox::Show("Числовое значение продолжительности слишком велико!");
			return false;
		}
		else if (Convert::ToInt32(textBox4->Text) > 2000000)
		{
			MessageBox::Show("Числовое значение продолжительности слишком велико!");
			return false;
		}
	}
	return true;
}

System::Void Project::MyForm::button1_Click(System::Object^  sender, System::EventArgs^  e)///добавление группы
{
	bool test=true;
	
	test= firstpagetest();//вызов функции для проверки полей на слишком крупные значения
	
	if (!((textBox1->Text=="") || (textBox2->Text=="")  || (textBox4->Text=="") || (textBox5->Text=="") || (textBox3->Text == ""))&&(test))//проверка на пустоту
	{


		if (countg == 0)//проверка на количество групп(нужно ли вызывать ресайз)
		{
			g[0].firstgroup(Convert::ToInt32(textBox1->Text), stdconvert(dateTimePicker1->Text), stdconvert(textBox4->Text), stdconvert(textBox5->Text), stdconvert(textBox3->Text), Convert::ToDouble(textBox2->Text));
			countg++;//увеличение кол-ва групп(счетчика)
		}
		else
		{

			resizemass();//увеличение размера массива 
			g[countg - 1].firstgroup(Convert::ToInt32(textBox1->Text), stdconvert(dateTimePicker1->Text), stdconvert(textBox4->Text), stdconvert(textBox5->Text), stdconvert(textBox3->Text), Convert::ToDouble(textBox2->Text));

		}
		//очистка полей

		
		comboBox1->Items->Clear();
		comboBox2->Items->Clear();

		for (int i = 1; i <= countg; i++)//добавление в комбобоксы порядковых номеров групп
		{
			comboBox1->Items->Add(i);
			comboBox2->Items->Add(i);
		}
	
		MessageBox::Show("Запись добавлена");
		saveThis();//метод для сохранения всех групп и их содержиого в файл
		textBox1->Clear();
		textBox2->Clear();
		textBox4->Clear();
		textBox5->Clear();
		textBox3->Clear();
	}
	else
	{
		if(test)
		MessageBox::Show("Не все поля заполнены");
	}
		//очистка полей


}

int countchar(std::string s)//проверка строки на наличие &  и вычисление их количества
{
	int i = 0;
	int k = 0;
	for (; i < s.length(); i++)
	{
		if (s[i] == '&')
		{
			k++;
		}
	}
	return k;
}

bool isdigt_string_test(std::string str)//проверка строки на число, если хоть одна буква есть, то строка не считается числом
{
	bool k = true;
	for (int i = 0; i < str.length(); i++)
	{
		if ((isdigit(str[i])))
			k = true;
	else
	{
		k = false;
		break;
	}
	}
	return k;
}



System::Void Project::MyForm::button6_Click(System::Object^  sender, System::EventArgs^  e)
{

	
	String^ str;//строка для хранения пути к файлу
	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)//открытие диолгового окна и проверка нажатия на кнопку ОК
	{
		bool tst = true;
		str = openFileDialog1->FileName;//передача пути выбраного файла в переменную
		std::ifstream file(stdconvert(str));//открытие потока чтения файла
		std::string buf;//буферный файл для прочитаной строки
		int oldsize =0;//переменная для отката содержимого групп
		getline(file, buf);//считывает строку с датой
		getline(file, buf);//чтение первой строки, после строки с датой
		while (!file.eof())//пока не конец файла
		{
			if (countchar(buf) == 5)//если в считаной строке больше 6 & 
			{
				String^ systembuf = gcnew String(buf.c_str());//преобразование std в System string 
				int index2 = systembuf->IndexOf(("&"), systembuf->IndexOf("&")+1 );//второй &  его индекс
				int index3 = systembuf->IndexOf(("&"), index2 + 1);//третий &  его индекс
				int index4 = systembuf->IndexOf(("&"), index3 + 1);//четвертый &  его индекс
				int index5 = systembuf->IndexOf(("&"), index4 + 1);// пятый &  его индекс
				tst = isdigt_string_test(stdconvert(systembuf->Substring(0, systembuf->IndexOf("&"))));
			if(tst)//проверка второго поля если первое число
				tst = cena_string_test(stdconvert(systembuf->Substring(index4+1, index5 - index4-1)));
			if (tst)
				tst = isdigt_string_test(stdconvert(systembuf->Substring(index3 + 1, index4 - index3 - 1)));
			if (!tst)
				{
					MessageBox::Show(" Файл поврежден! ");
					break;					
				}
			else	if (countg == 0)// если 0 групп, то без вызова ресйза
				{

					g[0].firstgroup(Convert::ToInt32(systembuf->Substring(0, systembuf->IndexOf("&"))), //размер
						stdconvert(systembuf->Substring(index5 + 1)),//дата
						stdconvert(systembuf->Substring(index3 + 1, index4 - index3-1)),//длительность
						stdconvert(systembuf->Substring(index2 + 1, index3 - index2-1)),//название
						stdconvert(systembuf->Substring(systembuf->IndexOf("&") + 1, index2 - systembuf->IndexOf("&")-1)),//номер
						Convert::ToDouble(systembuf->Substring(index4 + 1, index5 - index4-1)));//цена
					//вырезаются подстрочки по & , их индексы найдены выше
countg++;


				}
				else
				{
					resizemass();
					g[countg - 1].firstgroup(Convert::ToInt32(systembuf->Substring(0, systembuf->IndexOf("&"))), //размер
						stdconvert(systembuf->Substring(index5 + 1)),//дата
						stdconvert(systembuf->Substring(index3 + 1, index4 - index3 - 1)),//длительность
						stdconvert(systembuf->Substring(index2 + 1, index3 - index2 - 1)),//название
						stdconvert(systembuf->Substring(systembuf->IndexOf("&") + 1, index2 - systembuf->IndexOf("&") - 1)),//номер
						Convert::ToDouble(systembuf->Substring(index4 + 1, index5 - index4 - 1)));//цена
			//вырезаются подстрочки по & , их индексы найдены выше

				}
//очистка и перезапись порядковых номеров групп
				comboBox1->Items->Clear();
				comboBox2->Items->Clear();
				for (int i = 1; i <= countg; i++)
				{
					comboBox1->Items->Add(i);
					comboBox2->Items->Add(i);
				}
				getline(file, buf);//чтение следующей строки
			}
			
			else if(countchar(buf) ==3)//если &  больше трех то добавляем в группу
			{
				if (g[countg - 1].returnsize() < g[countg - 1].returncountp())//проерка группы на переполнение
				{
					String^ systembuf = gcnew String(buf.c_str());//буферная строка
//индексы 2 и 3 & 
					int index2 = systembuf->IndexOf(("&"), systembuf->IndexOf("&") + 1);//второй &  его индекс
					int index3 = systembuf->IndexOf(("&"), index2 + 1);//третий &  его индекс

					g[countg - 1].addpople(stdconvert(systembuf->Substring(0, systembuf->IndexOf("&"))), 
						stdconvert(systembuf->Substring(systembuf->IndexOf("&") + 1, index2 - systembuf->IndexOf("&")-1)), 
						stdconvert(systembuf->Substring(index2 + 1, index3 - index2-1)), 
						stdconvert(systembuf->Substring(index3 + 1)));//добавление в группу подстрочек
					getline(file, buf);//чтение следующие строки
				}
				else
				{
					g[countg - 1].sizetoback(oldsize);//"откат" группы, в случии переполнения
					MessageBox::Show("Недостаточно места в группе");
					break;
				}
			}

		}
		file.close();//закрытие потока
	}
	saveThis();//сохранение в файл
}

System::Void Project::MyForm::textBox1_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e)///запрет ввода не цифр в поля(событие)
{
	
	if (!((e->KeyChar >= '0') && (e->KeyChar <= '9') ||
		 (e->KeyChar == 8))) //проверка нажатой клавиши
{
		e->Handled = true;//запрет, входящей диапазон кнопки, не дописывает в конец строки  
	}
}

System::Void Project::MyForm::cenapress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) 
{

	if (!((e->KeyChar >= '0') && (e->KeyChar <= '9') ||
		(e->KeyChar == ',') || (e->KeyChar == 8) || (e->KeyChar == ','))) //проверка нажатой клавиши
	{
		e->Handled = true;//запрет, входящей диапазон кнопки, не дописывает в конец строки  
	}
}

System::Void Project::MyForm::textBox5_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e)//запрет ввода & 
{
	if ((e->KeyChar == '&')) //проверка нажатой клавиши
	{
		e->Handled = true;//запрет, входящей диапазон кнопки, не дописывает в конец строки  
	}

}

System::Void Project::MyForm::comboBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	richTextBox3->Text = gcnew String(g[Convert::ToInt32(comboBox1->Text) - 1].searchintogroup(stdconvert("")).c_str());
//если значение комбобокса меняется, выводится вся информация о группе
}

System::Void Project::MyForm::comboBox2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	int i = Convert::ToInt32(comboBox2->Text) - 1;
//вывод информации о группе
	richTextBox4->Text = ("Порядковый номер группы: " + Convert::ToString(i + 1) + " Номер группы: " + (gcnew String((g[i].returnnamber()).c_str())) + " Стоимость: " + Convert::ToString(g[i].returncena()) + " Дата тура: " + gcnew String((g[i].returndate()).c_str()) + " Продолжительность: " + gcnew String((g[i].returnhovlong()).c_str()) + " Название: " + gcnew String((g[i].returnname()).c_str()) + " Размер группы: " + Convert::ToString(g[i].returncountp()) + "\n");

}

System::Void Project::MyForm::comboBox2_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e)///запрет на ввод любых символов с клавиатуры
{
	e->Handled = true;
}

System::Void Project::MyForm::button2_Click(System::Object^  sender, System::EventArgs^  e)///поиск по фамилии
{
	if (comboBox1->Text == "")
	{
		MessageBox::Show("Выберите группу");
	}
	else
	//вызов метода для  поиска по фамилии	
	richTextBox1->Text = gcnew String(g[Convert::ToInt32(comboBox1->Text) - 1].searchintogroup(stdconvert(textBox10->Text)).c_str());
	
}

System::Void Project::MyForm::button3_Click(System::Object^  sender, System::EventArgs^  e)///добавить человека в группу
{
	if (comboBox2->Text == "")
	{
		MessageBox::Show("Выберите группу");
	}//вызов метода для добавления в группу, если возвращает false, то человек не добавлен
	else if (g[Convert::ToInt32(comboBox2->Text) - 1].addpople(stdconvert(textBox11->Text), stdconvert(textBox14->Text), stdconvert(textBox13->Text), stdconvert(dateTimePicker2->Text)))
	{
		MessageBox::Show("Человек добавлен");
		saveThis();//перезаписывает файл. По новой записывает все группы и их содержимое
	}
	else
	{
		MessageBox::Show("Нет места в группе");
	}
//очистка полей
	textBox11->Clear();
	textBox13->Clear();
	textBox14->Clear();
	if(comboBox1->Text!="")
//перевывод информации о группе
	richTextBox3->Text = gcnew String(g[Convert::ToInt32(comboBox1->Text) - 1].searchintogroup(stdconvert("")).c_str());
	saveThis();//сохранение
}

System::Void Project::MyForm::button4_Click(System::Object^  sender, System::EventArgs^  e)///удаление члена группы
{
	bool tst = true;
	/////////////////////////////////////////проверка на значения
	if (comboBox1->Text == "")
	{
		MessageBox::Show("Выберите группу");
	}
	if (textBox6->Text == "")
	{
		MessageBox::Show("Введите номер удаляемого человека");
		tst = false;
	}
	else

	{
		if ((textBox6->Text->Length > 8))
		{
			tst = false;
		}
		else if ((Convert::ToInt32(textBox6->Text) > 2000000))
		{
			tst = false;
		}
		if (!tst)
			MessageBox::Show("Слишком высокое значение!");
	}
	/////////////////////////////////////////

	//проверка группы напустоту
		if ((tst)&&(g[Convert::ToInt32(comboBox1->Text) - 1].returnsize() != 0)&&(g[Convert::ToInt32(comboBox1->Text) - 1].returnsize()>=Convert::ToInt32(textBox6->Text)) && (Convert::ToInt32(comboBox1->Text)>0))
	{//удаление человека
		if (g[Convert::ToInt32(comboBox1->Text) - 1].delpeople(Convert::ToInt32(textBox6->Text) - 1))
		{
			textBox6->Text = "";
			richTextBox1->Text = "";
			MessageBox::Show("Удалено");
			richTextBox3->Text = gcnew String(g[Convert::ToInt32(comboBox1->Text) - 1].searchintogroup(stdconvert("")).c_str());
		}
		else
			MessageBox::Show("Нельзя удалить");

	}
	else
		MessageBox::Show("Нельзя удалить");
//обновление поля списка группы
	saveThis();//сохранение


}

System::Void Project::MyForm::MyForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e)///событие до закрытия формы, чистящее память(удаление массива)
{
	delete[] g;//удаление динамического массива 
}

System::Void Project::MyForm::button7_Click(System::Object^  sender, System::EventArgs^  e)///добавление человек в группу из файла
{
	String^ str;

	if(comboBox2->Text=="")
	{ 
		MessageBox::Show("Выберите группу");
	}
	else if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{//открытие диалогого окна и получение пути файла
		str = openFileDialog1->FileName;
		std::ifstream file(stdconvert(str));//открытие  потока
		std::string buf;
		int oldsize = g[Convert::ToInt32(comboBox2->Text) - 1].returnsize();
		getline(file, buf);//чтение строки
		while (!file.eof())
		{
			if (g[Convert::ToInt32(comboBox2->Text) - 1].returnsize()<g[Convert::ToInt32(comboBox2->Text) - 1].returncountp())
			{
				String^ systembuf = gcnew String(buf.c_str());//буферная строка
															  //индексы 2 и 3 & 
				int index2 = systembuf->IndexOf(("&"), systembuf->IndexOf("&") + 1);//второй &  его индекс
				int index3 = systembuf->IndexOf(("&"), index2 + 1);//третий &  его индекс

				g[Convert::ToInt32(comboBox2->Text) - 1].addpople(stdconvert(systembuf->Substring(0, systembuf->IndexOf("&"))),
					stdconvert(systembuf->Substring(systembuf->IndexOf("&") + 1, index2 - systembuf->IndexOf("&") - 1)),
					stdconvert(systembuf->Substring(index2 + 1, index3 - index2 - 1)),
					stdconvert(systembuf->Substring(index3 + 1)));//добавление в группу подстрочек
				getline(file, buf);//чтение следующие строки
			}
			else
			{
				g[Convert::ToInt32(comboBox2->Text) - 1].sizetoback(oldsize);//отакт группы к состоянию до начала чтения в случии ошибки
				MessageBox::Show("Недостаточно места в группе");
				break;
			}
		}
		file.close();//закрытие потока
	}
	saveThis();//сохранение
	if (comboBox1->Text != "")
		richTextBox3->Text = gcnew String(g[Convert::ToInt32(comboBox1->Text) - 1].searchintogroup(stdconvert("")).c_str());

}

void Project::MyForm::resizemass()///функция для увеличения размера массива групп. 
{
	trip *d;//создание указателя типа трип
	d = new trip[countg];//выделение памяти под массив
	for (int i = 0; i < countg; i++)
	{
		d[i] = g[i];//копирование объектов массива объектов g в массив объекта d
	}
	delete[] g;//удаление массива g
	countg++;//увеличение счетчика групп
	g = new trip[countg];//выделение памяти под массив g
	for (int i = 0; i < countg - 1; i++)
	{
		g[i] = d[i];//копирование объектов массива объектов d в массив объекта g
	}
	delete[] d;//удаление d
}

std::string Project::MyForm::stdconvert(String ^s)///функция преобазования System^ String  в std::string. При помощи Marshal. Возвращает std::string 
{
	std::string os;// строка std
	using namespace Runtime::InteropServices;
	const char* chars =	(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
	os = chars;
	Marshal::FreeHGlobal(IntPtr((void*)chars));
//преобразование строки System в строку std
	return os;//возвращение строки std
}


//Дальше идет код с 4 функциями для подбора тура. Проверяется в начале > < или =, а потом только происходит проверка
/////////////////////////////////////////////////////////////////////////////////////////////////////
bool Project::MyForm::datechek(String^ s, int indexMass, String^ valueForChek)
{
	if (s == "<")
	{
		if (Convert::ToDateTime(gcnew String( g[indexMass].returndate().c_str())) < Convert::ToDateTime(valueForChek))
			return true;
		else
			return false;
	}
	else if (s == ">")
	{
		if (Convert::ToDateTime(gcnew String(g[indexMass].returndate().c_str())) > Convert::ToDateTime(valueForChek))
			return true;
		else
			return false;
	}
	else if (s == "=")
	{
		if (Convert::ToDateTime(gcnew String(g[indexMass].returndate().c_str())) == Convert::ToDateTime(valueForChek))
			return true;
		else
			return false;
	}


}

bool Project::MyForm::razmchek(String^ s, int indexMass, String^ valueForChek) 
{
	if (s == "<")
	{
		if (g[indexMass].returncountp() < Convert::ToInt32(valueForChek))
			return true;
		else
			return false;
	}
	else if (s == ">")
	{
		if (g[indexMass].returncountp()>Convert::ToInt32(valueForChek))
			return true;
		else
			return false;
	}
	else if (s == "=")
	{
		if (g[indexMass].returncountp()== Convert::ToInt32(valueForChek))
			return true;
		else
			return false;
	}

}

bool Project::MyForm::stoimchek(String^ s, int indexMass, String^ valueForChek)
{
	if (s == "<")
	{
		if (g[indexMass].returncena() < Convert::ToDouble(valueForChek))
			return true;
		else
			return false;
	}
	else if (s == ">")
	{
		if (g[indexMass].returncena()>Convert::ToDouble(valueForChek))
			return true;
		else
			return false;
	}
	else if (s == "=")
	{
		if (g[indexMass].returncena() == Convert::ToDouble(valueForChek))
			return true;
		else
			return false;
	}

}

bool Project::MyForm::prodolchek(String^ s, int indexMass, String^ valueForChek) 
{
	if (s == "<")
	{
		if (Convert::ToInt32(gcnew String(g[indexMass].returnhovlong().c_str()))< Convert::ToInt32(valueForChek))
			return true;
		else
			return false;
	}
	else if (s == ">")
	{
		if (Convert::ToInt32(gcnew String(g[indexMass].returnhovlong().c_str()))> Convert::ToInt32(valueForChek))
			return true;
		else
			return false;
	}
	else if (s == "=")
	{
		if (Convert::ToInt32(gcnew String(g[indexMass].returnhovlong().c_str()))== Convert::ToInt32(valueForChek))
			return true;
		else
			return false;
	}

}

//проверка полей 4 страницы
bool Project::MyForm::page4test()
{
	if ((comboBox10->Text == "") || (comboBox3->Text == "") || (comboBox8->Text == "") || (comboBox11->Text == "") ||
		(textBox9->Text == "") || (textBox7->Text == "") || (textBox8->Text == ""))
	{
		MessageBox::Show(" Не все поля заполнены");
		return false;
	}
	if (cena_string_test(stdconvert(textBox7->Text)))
	{
		if ((textBox7->Text->Length > 9))
		{
			MessageBox::Show("Числовое значение стоимости слишком велико!");
			return false;
		}
		else if (Convert::ToDouble(textBox7->Text) > 2000000)
		{
			MessageBox::Show("Числовое значение стоимости слишком велико!");
			return false;
		}
	}
	else
	{
		MessageBox::Show("Поле Стоимости имело не верный формат!");
		return false;
	}

	if (textBox8->Text->Length > 8)
	{
		MessageBox::Show(" Слишком высокое значение в поле Размер группы");
		return false;
	}
	else if (Convert::ToInt32(textBox8->Text) > 2000000)
	{
		MessageBox::Show(" Слишком высокое значение в поле Размер группы");
		return false;
	}

	else if (textBox9->Text->Length > 8)
	{
		return false;
		MessageBox::Show(" Слишком высокое значение в поле Продолжительность тура");
	}
	else if (Convert::ToInt32(textBox9->Text) > 2000000)
	{
		MessageBox::Show(" Слишком высокое значение в поле Продолжительность тура");
		return false;
	}
	else
		return true;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
System::Void Project::MyForm::button5_Click(System::Object^  sender, System::EventArgs^  e)///подбор группы по выбраным требованиям
{
	bool tst = true;
	//проверка полей 

	tst = page4test();

	richTextBox2->Clear();
	if(tst)//подтверждение, все ли подходит
	for (size_t i = 0; i < countg; i++)
	{

		if ((datechek(comboBox11->Text, i, dateTimePicker5->Text))&&
			(razmchek(comboBox8->Text,i,textBox8->Text))&&
			(stoimchek(comboBox3->Text,i,textBox7->Text))&&
			(prodolchek(comboBox10->Text,i,textBox9->Text))&&g[i].isfull())//если все условия подходят, то группа выводится
		{
			richTextBox2->Text = richTextBox2->Text + ("Порядковый номер группы: " + 
				Convert::ToString(i + 1) + " Номер группы: " +
				(gcnew String((g[i].returnnamber()).c_str())) + " Стоимость: " +
				Convert::ToString(g[i].returncena()) + " Дата тура: " + 
				gcnew String((g[i].returndate()).c_str()) + " Продолжительность: " + 
				gcnew String((g[i].returnhovlong()).c_str()) + " Название: " + gcnew String((g[i].returnname()).c_str()) +
				" Размер группы: " + Convert::ToString(g[i].returncountp()) + "\n");
		}
	}
}

void Project::MyForm::saveThis()//сохранение
{
	std::ofstream iu("saves.txt", std::ios_base::out | std::ios_base::trunc);//поток записи
	char *buffer = new char[80];
	time_t seconds = time(NULL);
	tm* timeinfo = localtime(&seconds);
	char* format = "%A, %B %d, %Y %I:%M:%S";
	strftime(buffer, 80, format, timeinfo);
	iu << buffer << std::endl;//запись даты и времени
	delete[] buffer;
	for (int i = 0; i < countg; i++)//перебор всех групп и запись в файл
	{
		
			String^ r;//формирование строки с информацией о группе
			r += (Convert::ToString(g[i].returncountp()) + "&");
			r += (gcnew String((g[i].returnnamber()).c_str()) + "&");
			r += (gcnew String((g[i].returnname()).c_str()) + "&");			
			r += (gcnew String((g[i].returnhovlong()).c_str()) + "&");			
			r += (Convert::ToString(g[i].returncena()) + "&");
			r += (gcnew String(g[i].returndate().c_str()));

			iu << stdconvert(r) + "\n";//запись информации о группе
			for (int i_for_p = 0; i_for_p < g[i].returnsize(); i_for_p++)//перебор членов группы и запись построчно в файл
			{
				iu << g[i].returnf(i_for_p)+"&" + g[i].returni(i_for_p)+"&"+ g[i].returno(i_for_p)+"&"+ g[i].returnd(i_for_p)+"\n";
		}
	}
	iu.close();//закрытие потока
}

System::Void Project::MyForm::button8_Click(System::Object^  sender, System::EventArgs^  e)///свободные на данный момент группы записываются в файл
{
	//то же, что и в функции выше
	std::ofstream iu("logs.txt", std::ios_base::out | std::ios_base::trunc);
	char *buffer = new char[80];
	time_t seconds = time(NULL);
	tm* timeinfo = localtime(&seconds);
	char* format = "%A, %B %d, %Y %I:%M:%S";
	strftime(buffer, 80, format, timeinfo);
	iu << buffer << std::endl;
	delete[] buffer;
	for (int i = 0; i < countg; i++)
	{//перебор групп и проверка, входит ли группа в диапазон
		if ((Convert::ToDateTime(gcnew String(g[i].returndate().c_str()))<=Convert::ToDateTime(dateTimePicker4->Text))&& (Convert::ToDateTime(gcnew String(g[i].returndate().c_str())) >= Convert::ToDateTime(dateTimePicker3->Text)))
		{
			String^ r;
			r += "Номер группы по порядку: "+(i+1)+" Номер группы: ";
			r += (gcnew String((g[i].returnnamber()).c_str()) + " Название маршрута: ");
			r += (gcnew String((g[i].returnname()).c_str()) + " Дата начала тура: ");
			r += (gcnew String(g[i].returndate().c_str()) + " Продолжительность: ");
			r += (gcnew String((g[i].returnhovlong()).c_str()) + " дней Размер группы: ");
			r += (Convert::ToString(g[i].returncountp()) + " Стоимость тура: ");
			r += (Convert::ToString(g[i].returncena()) + " рублей Свободно: ");
			r += (g[i].returncountp()- g[i].returnsize())+ " из: ";
			r += (g[i].returncountp());//формирование строки и запись
			iu << stdconvert(r) + "\n";
		}
	}
	iu.close();//закрытие потока

}

