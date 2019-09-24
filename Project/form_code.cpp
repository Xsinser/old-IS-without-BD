#include <string>///������
#include "class_trip.h"///�����
#include <cstdlib>
#include <fstream>
#include <ctime>///��� ��������� �������
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


bool cena_string_test(std::string str)//�������� ������ �� �����, ���� ���� ���� ����� ����, �� ������ �� ��������� ������
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

//������� �������� ���� �������� ����� �� 1 ��������
bool Project::MyForm::firstpagetest()
{
	
	if (!((textBox1->Text == "") || (textBox2->Text == "") || (textBox4->Text == "") || (textBox5->Text == "") || (textBox3->Text == "")))//�������� �� �������
	{
		if (textBox1->Text->Length > 8)
		{
			MessageBox::Show("�������� �������� ������� ������ ������� ������!");
			return false;
		}
		else if (Convert::ToInt32(textBox1->Text) > 2000000)
		{
			MessageBox::Show("�������� �������� ������� ������ ������� ������!");
			return false;
		}
		if (cena_string_test(stdconvert(textBox2->Text)))
		{
			if ((textBox2->Text->Length > 9))
			{
				MessageBox::Show("�������� �������� ��������� ������� ������!");
				return false;
			}
			else if (Convert::ToDouble(textBox2->Text) > 2000000)
			{
				MessageBox::Show("�������� �������� ��������� ������� ������!");
				return false;
			}
		}
		else
		{
			MessageBox::Show("���� ��������� ����� �������� ������!");
			return false;
		}
		if (textBox4->Text->Length > 8)
		{
			MessageBox::Show("�������� �������� ����������������� ������� ������!");
			return false;
		}
		else if (Convert::ToInt32(textBox4->Text) > 2000000)
		{
			MessageBox::Show("�������� �������� ����������������� ������� ������!");
			return false;
		}
	}
	return true;
}

System::Void Project::MyForm::button1_Click(System::Object^  sender, System::EventArgs^  e)///���������� ������
{
	bool test=true;
	
	test= firstpagetest();//����� ������� ��� �������� ����� �� ������� ������� ��������
	
	if (!((textBox1->Text=="") || (textBox2->Text=="")  || (textBox4->Text=="") || (textBox5->Text=="") || (textBox3->Text == ""))&&(test))//�������� �� �������
	{


		if (countg == 0)//�������� �� ���������� �����(����� �� �������� ������)
		{
			g[0].firstgroup(Convert::ToInt32(textBox1->Text), stdconvert(dateTimePicker1->Text), stdconvert(textBox4->Text), stdconvert(textBox5->Text), stdconvert(textBox3->Text), Convert::ToDouble(textBox2->Text));
			countg++;//���������� ���-�� �����(��������)
		}
		else
		{

			resizemass();//���������� ������� ������� 
			g[countg - 1].firstgroup(Convert::ToInt32(textBox1->Text), stdconvert(dateTimePicker1->Text), stdconvert(textBox4->Text), stdconvert(textBox5->Text), stdconvert(textBox3->Text), Convert::ToDouble(textBox2->Text));

		}
		//������� �����

		
		comboBox1->Items->Clear();
		comboBox2->Items->Clear();

		for (int i = 1; i <= countg; i++)//���������� � ���������� ���������� ������� �����
		{
			comboBox1->Items->Add(i);
			comboBox2->Items->Add(i);
		}
	
		MessageBox::Show("������ ���������");
		saveThis();//����� ��� ���������� ���� ����� � �� ���������� � ����
		textBox1->Clear();
		textBox2->Clear();
		textBox4->Clear();
		textBox5->Clear();
		textBox3->Clear();
	}
	else
	{
		if(test)
		MessageBox::Show("�� ��� ���� ���������");
	}
		//������� �����


}

int countchar(std::string s)//�������� ������ �� ������� &  � ���������� �� ����������
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

bool isdigt_string_test(std::string str)//�������� ������ �� �����, ���� ���� ���� ����� ����, �� ������ �� ��������� ������
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

	
	String^ str;//������ ��� �������� ���� � �����
	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)//�������� ���������� ���� � �������� ������� �� ������ ��
	{
		bool tst = true;
		str = openFileDialog1->FileName;//�������� ���� ��������� ����� � ����������
		std::ifstream file(stdconvert(str));//�������� ������ ������ �����
		std::string buf;//�������� ���� ��� ���������� ������
		int oldsize =0;//���������� ��� ������ ����������� �����
		getline(file, buf);//��������� ������ � �����
		getline(file, buf);//������ ������ ������, ����� ������ � �����
		while (!file.eof())//���� �� ����� �����
		{
			if (countchar(buf) == 5)//���� � �������� ������ ������ 6 & 
			{
				String^ systembuf = gcnew String(buf.c_str());//�������������� std � System string 
				int index2 = systembuf->IndexOf(("&"), systembuf->IndexOf("&")+1 );//������ &  ��� ������
				int index3 = systembuf->IndexOf(("&"), index2 + 1);//������ &  ��� ������
				int index4 = systembuf->IndexOf(("&"), index3 + 1);//��������� &  ��� ������
				int index5 = systembuf->IndexOf(("&"), index4 + 1);// ����� &  ��� ������
				tst = isdigt_string_test(stdconvert(systembuf->Substring(0, systembuf->IndexOf("&"))));
			if(tst)//�������� ������� ���� ���� ������ �����
				tst = cena_string_test(stdconvert(systembuf->Substring(index4+1, index5 - index4-1)));
			if (tst)
				tst = isdigt_string_test(stdconvert(systembuf->Substring(index3 + 1, index4 - index3 - 1)));
			if (!tst)
				{
					MessageBox::Show(" ���� ���������! ");
					break;					
				}
			else	if (countg == 0)// ���� 0 �����, �� ��� ������ ������
				{

					g[0].firstgroup(Convert::ToInt32(systembuf->Substring(0, systembuf->IndexOf("&"))), //������
						stdconvert(systembuf->Substring(index5 + 1)),//����
						stdconvert(systembuf->Substring(index3 + 1, index4 - index3-1)),//������������
						stdconvert(systembuf->Substring(index2 + 1, index3 - index2-1)),//��������
						stdconvert(systembuf->Substring(systembuf->IndexOf("&") + 1, index2 - systembuf->IndexOf("&")-1)),//�����
						Convert::ToDouble(systembuf->Substring(index4 + 1, index5 - index4-1)));//����
					//���������� ���������� �� & , �� ������� ������� ����
countg++;


				}
				else
				{
					resizemass();
					g[countg - 1].firstgroup(Convert::ToInt32(systembuf->Substring(0, systembuf->IndexOf("&"))), //������
						stdconvert(systembuf->Substring(index5 + 1)),//����
						stdconvert(systembuf->Substring(index3 + 1, index4 - index3 - 1)),//������������
						stdconvert(systembuf->Substring(index2 + 1, index3 - index2 - 1)),//��������
						stdconvert(systembuf->Substring(systembuf->IndexOf("&") + 1, index2 - systembuf->IndexOf("&") - 1)),//�����
						Convert::ToDouble(systembuf->Substring(index4 + 1, index5 - index4 - 1)));//����
			//���������� ���������� �� & , �� ������� ������� ����

				}
//������� � ���������� ���������� ������� �����
				comboBox1->Items->Clear();
				comboBox2->Items->Clear();
				for (int i = 1; i <= countg; i++)
				{
					comboBox1->Items->Add(i);
					comboBox2->Items->Add(i);
				}
				getline(file, buf);//������ ��������� ������
			}
			
			else if(countchar(buf) ==3)//���� &  ������ ���� �� ��������� � ������
			{
				if (g[countg - 1].returnsize() < g[countg - 1].returncountp())//������� ������ �� ������������
				{
					String^ systembuf = gcnew String(buf.c_str());//�������� ������
//������� 2 � 3 & 
					int index2 = systembuf->IndexOf(("&"), systembuf->IndexOf("&") + 1);//������ &  ��� ������
					int index3 = systembuf->IndexOf(("&"), index2 + 1);//������ &  ��� ������

					g[countg - 1].addpople(stdconvert(systembuf->Substring(0, systembuf->IndexOf("&"))), 
						stdconvert(systembuf->Substring(systembuf->IndexOf("&") + 1, index2 - systembuf->IndexOf("&")-1)), 
						stdconvert(systembuf->Substring(index2 + 1, index3 - index2-1)), 
						stdconvert(systembuf->Substring(index3 + 1)));//���������� � ������ ����������
					getline(file, buf);//������ ��������� ������
				}
				else
				{
					g[countg - 1].sizetoback(oldsize);//"�����" ������, � ������ ������������
					MessageBox::Show("������������ ����� � ������");
					break;
				}
			}

		}
		file.close();//�������� ������
	}
	saveThis();//���������� � ����
}

System::Void Project::MyForm::textBox1_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e)///������ ����� �� ���� � ����(�������)
{
	
	if (!((e->KeyChar >= '0') && (e->KeyChar <= '9') ||
		 (e->KeyChar == 8))) //�������� ������� �������
{
		e->Handled = true;//������, �������� �������� ������, �� ���������� � ����� ������  
	}
}

System::Void Project::MyForm::cenapress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) 
{

	if (!((e->KeyChar >= '0') && (e->KeyChar <= '9') ||
		(e->KeyChar == ',') || (e->KeyChar == 8) || (e->KeyChar == ','))) //�������� ������� �������
	{
		e->Handled = true;//������, �������� �������� ������, �� ���������� � ����� ������  
	}
}

System::Void Project::MyForm::textBox5_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e)//������ ����� & 
{
	if ((e->KeyChar == '&')) //�������� ������� �������
	{
		e->Handled = true;//������, �������� �������� ������, �� ���������� � ����� ������  
	}

}

System::Void Project::MyForm::comboBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	richTextBox3->Text = gcnew String(g[Convert::ToInt32(comboBox1->Text) - 1].searchintogroup(stdconvert("")).c_str());
//���� �������� ���������� ��������, ��������� ��� ���������� � ������
}

System::Void Project::MyForm::comboBox2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	int i = Convert::ToInt32(comboBox2->Text) - 1;
//����� ���������� � ������
	richTextBox4->Text = ("���������� ����� ������: " + Convert::ToString(i + 1) + " ����� ������: " + (gcnew String((g[i].returnnamber()).c_str())) + " ���������: " + Convert::ToString(g[i].returncena()) + " ���� ����: " + gcnew String((g[i].returndate()).c_str()) + " �����������������: " + gcnew String((g[i].returnhovlong()).c_str()) + " ��������: " + gcnew String((g[i].returnname()).c_str()) + " ������ ������: " + Convert::ToString(g[i].returncountp()) + "\n");

}

System::Void Project::MyForm::comboBox2_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e)///������ �� ���� ����� �������� � ����������
{
	e->Handled = true;
}

System::Void Project::MyForm::button2_Click(System::Object^  sender, System::EventArgs^  e)///����� �� �������
{
	if (comboBox1->Text == "")
	{
		MessageBox::Show("�������� ������");
	}
	else
	//����� ������ ���  ������ �� �������	
	richTextBox1->Text = gcnew String(g[Convert::ToInt32(comboBox1->Text) - 1].searchintogroup(stdconvert(textBox10->Text)).c_str());
	
}

System::Void Project::MyForm::button3_Click(System::Object^  sender, System::EventArgs^  e)///�������� �������� � ������
{
	if (comboBox2->Text == "")
	{
		MessageBox::Show("�������� ������");
	}//����� ������ ��� ���������� � ������, ���� ���������� false, �� ������� �� ��������
	else if (g[Convert::ToInt32(comboBox2->Text) - 1].addpople(stdconvert(textBox11->Text), stdconvert(textBox14->Text), stdconvert(textBox13->Text), stdconvert(dateTimePicker2->Text)))
	{
		MessageBox::Show("������� ��������");
		saveThis();//�������������� ����. �� ����� ���������� ��� ������ � �� ����������
	}
	else
	{
		MessageBox::Show("��� ����� � ������");
	}
//������� �����
	textBox11->Clear();
	textBox13->Clear();
	textBox14->Clear();
	if(comboBox1->Text!="")
//��������� ���������� � ������
	richTextBox3->Text = gcnew String(g[Convert::ToInt32(comboBox1->Text) - 1].searchintogroup(stdconvert("")).c_str());
	saveThis();//����������
}

System::Void Project::MyForm::button4_Click(System::Object^  sender, System::EventArgs^  e)///�������� ����� ������
{
	bool tst = true;
	/////////////////////////////////////////�������� �� ��������
	if (comboBox1->Text == "")
	{
		MessageBox::Show("�������� ������");
	}
	if (textBox6->Text == "")
	{
		MessageBox::Show("������� ����� ���������� ��������");
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
			MessageBox::Show("������� ������� ��������!");
	}
	/////////////////////////////////////////

	//�������� ������ ���������
		if ((tst)&&(g[Convert::ToInt32(comboBox1->Text) - 1].returnsize() != 0)&&(g[Convert::ToInt32(comboBox1->Text) - 1].returnsize()>=Convert::ToInt32(textBox6->Text)) && (Convert::ToInt32(comboBox1->Text)>0))
	{//�������� ��������
		if (g[Convert::ToInt32(comboBox1->Text) - 1].delpeople(Convert::ToInt32(textBox6->Text) - 1))
		{
			textBox6->Text = "";
			richTextBox1->Text = "";
			MessageBox::Show("�������");
			richTextBox3->Text = gcnew String(g[Convert::ToInt32(comboBox1->Text) - 1].searchintogroup(stdconvert("")).c_str());
		}
		else
			MessageBox::Show("������ �������");

	}
	else
		MessageBox::Show("������ �������");
//���������� ���� ������ ������
	saveThis();//����������


}

System::Void Project::MyForm::MyForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e)///������� �� �������� �����, �������� ������(�������� �������)
{
	delete[] g;//�������� ������������� ������� 
}

System::Void Project::MyForm::button7_Click(System::Object^  sender, System::EventArgs^  e)///���������� ������� � ������ �� �����
{
	String^ str;

	if(comboBox2->Text=="")
	{ 
		MessageBox::Show("�������� ������");
	}
	else if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{//�������� ��������� ���� � ��������� ���� �����
		str = openFileDialog1->FileName;
		std::ifstream file(stdconvert(str));//��������  ������
		std::string buf;
		int oldsize = g[Convert::ToInt32(comboBox2->Text) - 1].returnsize();
		getline(file, buf);//������ ������
		while (!file.eof())
		{
			if (g[Convert::ToInt32(comboBox2->Text) - 1].returnsize()<g[Convert::ToInt32(comboBox2->Text) - 1].returncountp())
			{
				String^ systembuf = gcnew String(buf.c_str());//�������� ������
															  //������� 2 � 3 & 
				int index2 = systembuf->IndexOf(("&"), systembuf->IndexOf("&") + 1);//������ &  ��� ������
				int index3 = systembuf->IndexOf(("&"), index2 + 1);//������ &  ��� ������

				g[Convert::ToInt32(comboBox2->Text) - 1].addpople(stdconvert(systembuf->Substring(0, systembuf->IndexOf("&"))),
					stdconvert(systembuf->Substring(systembuf->IndexOf("&") + 1, index2 - systembuf->IndexOf("&") - 1)),
					stdconvert(systembuf->Substring(index2 + 1, index3 - index2 - 1)),
					stdconvert(systembuf->Substring(index3 + 1)));//���������� � ������ ����������
				getline(file, buf);//������ ��������� ������
			}
			else
			{
				g[Convert::ToInt32(comboBox2->Text) - 1].sizetoback(oldsize);//����� ������ � ��������� �� ������ ������ � ������ ������
				MessageBox::Show("������������ ����� � ������");
				break;
			}
		}
		file.close();//�������� ������
	}
	saveThis();//����������
	if (comboBox1->Text != "")
		richTextBox3->Text = gcnew String(g[Convert::ToInt32(comboBox1->Text) - 1].searchintogroup(stdconvert("")).c_str());

}

void Project::MyForm::resizemass()///������� ��� ���������� ������� ������� �����. 
{
	trip *d;//�������� ��������� ���� ����
	d = new trip[countg];//��������� ������ ��� ������
	for (int i = 0; i < countg; i++)
	{
		d[i] = g[i];//����������� �������� ������� �������� g � ������ ������� d
	}
	delete[] g;//�������� ������� g
	countg++;//���������� �������� �����
	g = new trip[countg];//��������� ������ ��� ������ g
	for (int i = 0; i < countg - 1; i++)
	{
		g[i] = d[i];//����������� �������� ������� �������� d � ������ ������� g
	}
	delete[] d;//�������� d
}

std::string Project::MyForm::stdconvert(String ^s)///������� ������������� System^ String  � std::string. ��� ������ Marshal. ���������� std::string 
{
	std::string os;// ������ std
	using namespace Runtime::InteropServices;
	const char* chars =	(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
	os = chars;
	Marshal::FreeHGlobal(IntPtr((void*)chars));
//�������������� ������ System � ������ std
	return os;//����������� ������ std
}


//������ ���� ��� � 4 ��������� ��� ������� ����. ����������� � ������ > < ��� =, � ����� ������ ���������� ��������
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

//�������� ����� 4 ��������
bool Project::MyForm::page4test()
{
	if ((comboBox10->Text == "") || (comboBox3->Text == "") || (comboBox8->Text == "") || (comboBox11->Text == "") ||
		(textBox9->Text == "") || (textBox7->Text == "") || (textBox8->Text == ""))
	{
		MessageBox::Show(" �� ��� ���� ���������");
		return false;
	}
	if (cena_string_test(stdconvert(textBox7->Text)))
	{
		if ((textBox7->Text->Length > 9))
		{
			MessageBox::Show("�������� �������� ��������� ������� ������!");
			return false;
		}
		else if (Convert::ToDouble(textBox7->Text) > 2000000)
		{
			MessageBox::Show("�������� �������� ��������� ������� ������!");
			return false;
		}
	}
	else
	{
		MessageBox::Show("���� ��������� ����� �� ������ ������!");
		return false;
	}

	if (textBox8->Text->Length > 8)
	{
		MessageBox::Show(" ������� ������� �������� � ���� ������ ������");
		return false;
	}
	else if (Convert::ToInt32(textBox8->Text) > 2000000)
	{
		MessageBox::Show(" ������� ������� �������� � ���� ������ ������");
		return false;
	}

	else if (textBox9->Text->Length > 8)
	{
		return false;
		MessageBox::Show(" ������� ������� �������� � ���� ����������������� ����");
	}
	else if (Convert::ToInt32(textBox9->Text) > 2000000)
	{
		MessageBox::Show(" ������� ������� �������� � ���� ����������������� ����");
		return false;
	}
	else
		return true;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
System::Void Project::MyForm::button5_Click(System::Object^  sender, System::EventArgs^  e)///������ ������ �� �������� �����������
{
	bool tst = true;
	//�������� ����� 

	tst = page4test();

	richTextBox2->Clear();
	if(tst)//�������������, ��� �� ��������
	for (size_t i = 0; i < countg; i++)
	{

		if ((datechek(comboBox11->Text, i, dateTimePicker5->Text))&&
			(razmchek(comboBox8->Text,i,textBox8->Text))&&
			(stoimchek(comboBox3->Text,i,textBox7->Text))&&
			(prodolchek(comboBox10->Text,i,textBox9->Text))&&g[i].isfull())//���� ��� ������� ��������, �� ������ ���������
		{
			richTextBox2->Text = richTextBox2->Text + ("���������� ����� ������: " + 
				Convert::ToString(i + 1) + " ����� ������: " +
				(gcnew String((g[i].returnnamber()).c_str())) + " ���������: " +
				Convert::ToString(g[i].returncena()) + " ���� ����: " + 
				gcnew String((g[i].returndate()).c_str()) + " �����������������: " + 
				gcnew String((g[i].returnhovlong()).c_str()) + " ��������: " + gcnew String((g[i].returnname()).c_str()) +
				" ������ ������: " + Convert::ToString(g[i].returncountp()) + "\n");
		}
	}
}

void Project::MyForm::saveThis()//����������
{
	std::ofstream iu("saves.txt", std::ios_base::out | std::ios_base::trunc);//����� ������
	char *buffer = new char[80];
	time_t seconds = time(NULL);
	tm* timeinfo = localtime(&seconds);
	char* format = "%A, %B %d, %Y %I:%M:%S";
	strftime(buffer, 80, format, timeinfo);
	iu << buffer << std::endl;//������ ���� � �������
	delete[] buffer;
	for (int i = 0; i < countg; i++)//������� ���� ����� � ������ � ����
	{
		
			String^ r;//������������ ������ � ����������� � ������
			r += (Convert::ToString(g[i].returncountp()) + "&");
			r += (gcnew String((g[i].returnnamber()).c_str()) + "&");
			r += (gcnew String((g[i].returnname()).c_str()) + "&");			
			r += (gcnew String((g[i].returnhovlong()).c_str()) + "&");			
			r += (Convert::ToString(g[i].returncena()) + "&");
			r += (gcnew String(g[i].returndate().c_str()));

			iu << stdconvert(r) + "\n";//������ ���������� � ������
			for (int i_for_p = 0; i_for_p < g[i].returnsize(); i_for_p++)//������� ������ ������ � ������ ��������� � ����
			{
				iu << g[i].returnf(i_for_p)+"&" + g[i].returni(i_for_p)+"&"+ g[i].returno(i_for_p)+"&"+ g[i].returnd(i_for_p)+"\n";
		}
	}
	iu.close();//�������� ������
}

System::Void Project::MyForm::button8_Click(System::Object^  sender, System::EventArgs^  e)///��������� �� ������ ������ ������ ������������ � ����
{
	//�� ��, ��� � � ������� ����
	std::ofstream iu("logs.txt", std::ios_base::out | std::ios_base::trunc);
	char *buffer = new char[80];
	time_t seconds = time(NULL);
	tm* timeinfo = localtime(&seconds);
	char* format = "%A, %B %d, %Y %I:%M:%S";
	strftime(buffer, 80, format, timeinfo);
	iu << buffer << std::endl;
	delete[] buffer;
	for (int i = 0; i < countg; i++)
	{//������� ����� � ��������, ������ �� ������ � ��������
		if ((Convert::ToDateTime(gcnew String(g[i].returndate().c_str()))<=Convert::ToDateTime(dateTimePicker4->Text))&& (Convert::ToDateTime(gcnew String(g[i].returndate().c_str())) >= Convert::ToDateTime(dateTimePicker3->Text)))
		{
			String^ r;
			r += "����� ������ �� �������: "+(i+1)+" ����� ������: ";
			r += (gcnew String((g[i].returnnamber()).c_str()) + " �������� ��������: ");
			r += (gcnew String((g[i].returnname()).c_str()) + " ���� ������ ����: ");
			r += (gcnew String(g[i].returndate().c_str()) + " �����������������: ");
			r += (gcnew String((g[i].returnhovlong()).c_str()) + " ���� ������ ������: ");
			r += (Convert::ToString(g[i].returncountp()) + " ��������� ����: ");
			r += (Convert::ToString(g[i].returncena()) + " ������ ��������: ");
			r += (g[i].returncountp()- g[i].returnsize())+ " ��: ";
			r += (g[i].returncountp());//������������ ������ � ������
			iu << stdconvert(r) + "\n";
		}
	}
	iu.close();//�������� ������

}

