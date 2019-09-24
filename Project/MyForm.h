#pragma once
#include <string>
#include "class_trip.h"
#include <cstdlib>
#include <fstream>
#include <iostream>

namespace Project {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>

	static	trip *g;///массив, содержащий в себе группы

	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			g = new trip[1];///инициализация массива групп

		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TabControl^  tabControl1;
	protected:
	private: System::Windows::Forms::TabPage^  tabPage1;

	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::TextBox^  textBox4;

	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Button^  add_g;

	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TabPage^  tabPage2;
	private: System::Windows::Forms::TabPage^  tabPage3;
	private: System::Windows::Forms::TabPage^  tabPage4;
	private: System::Windows::Forms::RichTextBox^  richTextBox1;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::TextBox^  textBox10;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::Label^  label15;
	private: System::Windows::Forms::Label^  label16;
	private: System::Windows::Forms::Label^  label17;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::ComboBox^  comboBox2;
	private: System::Windows::Forms::TextBox^  textBox11;

	private: System::Windows::Forms::TextBox^  textBox13;
	private: System::Windows::Forms::TextBox^  textBox14;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::TabPage^  tabPage5;
	private: System::Windows::Forms::Button^  button8;














	private: System::Windows::Forms::Button^  button5;

	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::TextBox^  textBox6;
	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::RichTextBox^  richTextBox2;
	private: System::Windows::Forms::Label^  label5;


	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::DateTimePicker^  dateTimePicker1;
	private: System::Windows::Forms::DateTimePicker^  dateTimePicker2;
	private: System::Windows::Forms::RichTextBox^  richTextBox3;
	private: System::Windows::Forms::TextBox^  textBox7;

	private: System::Windows::Forms::ComboBox^  comboBox3;
	private: System::Windows::Forms::RichTextBox^  richTextBox4;
	private: System::Windows::Forms::DateTimePicker^  dateTimePicker5;
	private: System::Windows::Forms::DateTimePicker^  dateTimePicker4;
	private: System::Windows::Forms::DateTimePicker^  dateTimePicker3;

	private: System::Windows::Forms::ComboBox^  comboBox11;
	private: System::Windows::Forms::TextBox^  textBox9;

	private: System::Windows::Forms::ComboBox^  comboBox10;
	private: System::Windows::Forms::TextBox^  textBox8;

	private: System::Windows::Forms::ComboBox^  comboBox8;
	private: System::Windows::Forms::Label^  label22;
	private: System::Windows::Forms::Label^  label21;
	private: System::Windows::Forms::Label^  label20;
	private: System::Windows::Forms::Label^  label19;
	private: System::Windows::Forms::Label^  label18;
	private: System::Windows::Forms::Label^  label11;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->add_g = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->richTextBox4 = (gcnew System::Windows::Forms::RichTextBox());
			this->dateTimePicker2 = (gcnew System::Windows::Forms::DateTimePicker());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->textBox11 = (gcnew System::Windows::Forms::TextBox());
			this->textBox13 = (gcnew System::Windows::Forms::TextBox());
			this->textBox14 = (gcnew System::Windows::Forms::TextBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->richTextBox3 = (gcnew System::Windows::Forms::RichTextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->textBox10 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->tabPage5 = (gcnew System::Windows::Forms::TabPage());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->dateTimePicker5 = (gcnew System::Windows::Forms::DateTimePicker());
			this->dateTimePicker4 = (gcnew System::Windows::Forms::DateTimePicker());
			this->dateTimePicker3 = (gcnew System::Windows::Forms::DateTimePicker());
			this->comboBox11 = (gcnew System::Windows::Forms::ComboBox());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			this->comboBox10 = (gcnew System::Windows::Forms::ComboBox());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->comboBox8 = (gcnew System::Windows::Forms::ComboBox());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->comboBox3 = (gcnew System::Windows::Forms::ComboBox());
			this->richTextBox2 = (gcnew System::Windows::Forms::RichTextBox());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->tabPage4 = (gcnew System::Windows::Forms::TabPage());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			this->tabPage3->SuspendLayout();
			this->tabPage5->SuspendLayout();
			this->SuspendLayout();
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Controls->Add(this->tabPage5);
			this->tabControl1->Location = System::Drawing::Point(1, 7);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(1061, 221);
			this->tabControl1->TabIndex = 0;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->dateTimePicker1);
			this->tabPage1->Controls->Add(this->label9);
			this->tabPage1->Controls->Add(this->textBox3);
			this->tabPage1->Controls->Add(this->button6);
			this->tabPage1->Controls->Add(this->label8);
			this->tabPage1->Controls->Add(this->label7);
			this->tabPage1->Controls->Add(this->label6);
			this->tabPage1->Controls->Add(this->label4);
			this->tabPage1->Controls->Add(this->label3);
			this->tabPage1->Controls->Add(this->label2);
			this->tabPage1->Controls->Add(this->label1);
			this->tabPage1->Controls->Add(this->textBox5);
			this->tabPage1->Controls->Add(this->textBox4);
			this->tabPage1->Controls->Add(this->textBox2);
			this->tabPage1->Controls->Add(this->add_g);
			this->tabPage1->Controls->Add(this->textBox1);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(1053, 195);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Добавление групп";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->Location = System::Drawing::Point(10, 132);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(200, 20);
			this->dateTimePicker1->TabIndex = 83;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(267, 26);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(80, 13);
			this->label9->TabIndex = 82;
			this->label9->Text = L"Номер группы";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(270, 42);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(100, 20);
			this->textBox3->TabIndex = 81;
			this->textBox3->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::textBox5_KeyPress);
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(440, 80);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(131, 69);
			this->button6->TabIndex = 80;
			this->button6->Text = L"Загрузить предыдущую сессию";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(376, 132);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(42, 13);
			this->label8->TabIndex = 79;
			this->label8->Text = L"рублей";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(116, 93);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(31, 13);
			this->label7->TabIndex = 78;
			this->label7->Text = L"дней";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(267, 71);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(85, 13);
			this->label6->TabIndex = 76;
			this->label6->Text = L"Размер группы";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(7, 26);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(218, 13);
			this->label4->TabIndex = 74;
			this->label4->Text = L"Наименование турестического маршрута";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(7, 71);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(136, 13);
			this->label3->TabIndex = 73;
			this->label3->Text = L"Продолжительность тура";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(7, 116);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(96, 13);
			this->label2->TabIndex = 72;
			this->label2->Text = L"Дата начала тура";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(267, 110);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(87, 13);
			this->label1->TabIndex = 71;
			this->label1->Text = L"Стоимость тура";
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(10, 45);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(100, 20);
			this->textBox5->TabIndex = 69;
			this->textBox5->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::textBox5_KeyPress);
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(10, 90);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(100, 20);
			this->textBox4->TabIndex = 68;
			this->textBox4->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::textBox1_KeyPress);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(270, 129);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 20);
			this->textBox2->TabIndex = 66;
			this->textBox2->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::cenapress);
			// 
			// add_g
			// 
			this->add_g->Location = System::Drawing::Point(440, 42);
			this->add_g->Name = L"add_g";
			this->add_g->Size = System::Drawing::Size(131, 23);
			this->add_g->TabIndex = 65;
			this->add_g->Text = L"Добавить группу";
			this->add_g->UseVisualStyleBackColor = true;
			this->add_g->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(270, 87);
			this->textBox1->MaxLength = 32765;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 64;
			this->textBox1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::textBox1_KeyPress);
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->richTextBox4);
			this->tabPage2->Controls->Add(this->dateTimePicker2);
			this->tabPage2->Controls->Add(this->button7);
			this->tabPage2->Controls->Add(this->label14);
			this->tabPage2->Controls->Add(this->label15);
			this->tabPage2->Controls->Add(this->label16);
			this->tabPage2->Controls->Add(this->label17);
			this->tabPage2->Controls->Add(this->label13);
			this->tabPage2->Controls->Add(this->comboBox2);
			this->tabPage2->Controls->Add(this->textBox11);
			this->tabPage2->Controls->Add(this->textBox13);
			this->tabPage2->Controls->Add(this->textBox14);
			this->tabPage2->Controls->Add(this->button3);
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(1053, 195);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Добавление в группу";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// richTextBox4
			// 
			this->richTextBox4->Location = System::Drawing::Point(6, 52);
			this->richTextBox4->Name = L"richTextBox4";
			this->richTextBox4->Size = System::Drawing::Size(666, 138);
			this->richTextBox4->TabIndex = 85;
			this->richTextBox4->Text = L"";
			// 
			// dateTimePicker2
			// 
			this->dateTimePicker2->Location = System::Drawing::Point(472, 24);
			this->dateTimePicker2->Name = L"dateTimePicker2";
			this->dateTimePicker2->Size = System::Drawing::Size(200, 20);
			this->dateTimePicker2->TabIndex = 84;
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(897, 15);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(131, 36);
			this->button7->TabIndex = 78;
			this->button7->Text = L"Добавить в группу из файла";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &MyForm::button7_Click);
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(469, 8);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(86, 13);
			this->label14->TabIndex = 53;
			this->label14->Text = L"Дата рождения";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(366, 8);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(54, 13);
			this->label15->TabIndex = 52;
			this->label15->Text = L"Отчество";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(260, 8);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(29, 13);
			this->label16->TabIndex = 51;
			this->label16->Text = L"Имя";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(151, 8);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(56, 13);
			this->label17->TabIndex = 50;
			this->label17->Text = L"Фамилия";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(3, 9);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(145, 13);
			this->label13->TabIndex = 49;
			this->label13->Text = L"Порядковый номер группы";
			// 
			// comboBox2
			// 
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Location = System::Drawing::Point(6, 25);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(121, 21);
			this->comboBox2->TabIndex = 48;
			this->comboBox2->TextChanged += gcnew System::EventHandler(this, &MyForm::comboBox2_TextChanged);
			this->comboBox2->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::comboBox2_KeyPress);
			// 
			// textBox11
			// 
			this->textBox11->Location = System::Drawing::Point(154, 24);
			this->textBox11->Name = L"textBox11";
			this->textBox11->Size = System::Drawing::Size(100, 20);
			this->textBox11->TabIndex = 47;
			this->textBox11->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::textBox5_KeyPress);
			// 
			// textBox13
			// 
			this->textBox13->Location = System::Drawing::Point(366, 24);
			this->textBox13->Name = L"textBox13";
			this->textBox13->Size = System::Drawing::Size(100, 20);
			this->textBox13->TabIndex = 45;
			this->textBox13->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::textBox5_KeyPress);
			// 
			// textBox14
			// 
			this->textBox14->Location = System::Drawing::Point(260, 24);
			this->textBox14->Name = L"textBox14";
			this->textBox14->Size = System::Drawing::Size(100, 20);
			this->textBox14->TabIndex = 44;
			this->textBox14->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::textBox5_KeyPress);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(728, 21);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(131, 23);
			this->button3->TabIndex = 43;
			this->button3->Text = L"Добавить в группу";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// tabPage3
			// 
			this->tabPage3->Controls->Add(this->richTextBox3);
			this->tabPage3->Controls->Add(this->label5);
			this->tabPage3->Controls->Add(this->textBox6);
			this->tabPage3->Controls->Add(this->richTextBox1);
			this->tabPage3->Controls->Add(this->label10);
			this->tabPage3->Controls->Add(this->label12);
			this->tabPage3->Controls->Add(this->comboBox1);
			this->tabPage3->Controls->Add(this->button4);
			this->tabPage3->Controls->Add(this->textBox10);
			this->tabPage3->Controls->Add(this->button2);
			this->tabPage3->Location = System::Drawing::Point(4, 22);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Size = System::Drawing::Size(1053, 195);
			this->tabPage3->TabIndex = 0;
			this->tabPage3->Text = L"Поиск/удаление из группы";
			// 
			// richTextBox3
			// 
			this->richTextBox3->Location = System::Drawing::Point(12, 57);
			this->richTextBox3->Name = L"richTextBox3";
			this->richTextBox3->Size = System::Drawing::Size(458, 129);
			this->richTextBox3->TabIndex = 44;
			this->richTextBox3->Text = L"";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(476, 12);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(154, 13);
			this->label5->TabIndex = 43;
			this->label5->Text = L"Номер удаляемого человека";
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(476, 28);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(154, 20);
			this->textBox6->TabIndex = 42;
			this->textBox6->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::textBox1_KeyPress);
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(476, 57);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(570, 129);
			this->richTextBox1->TabIndex = 41;
			this->richTextBox1->Text = L"";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(182, 13);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(56, 13);
			this->label10->TabIndex = 40;
			this->label10->Text = L"Фамилия";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(9, 12);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(145, 13);
			this->label12->TabIndex = 39;
			this->label12->Text = L"Порядковый номер группы";
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(12, 28);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 21);
			this->comboBox1->TabIndex = 38;
			this->comboBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::comboBox1_TextChanged);
			this->comboBox1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::comboBox2_KeyPress);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(648, 29);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(154, 19);
			this->button4->TabIndex = 37;
			this->button4->Text = L"Удалить выбраного";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// textBox10
			// 
			this->textBox10->Location = System::Drawing::Point(185, 29);
			this->textBox10->Name = L"textBox10";
			this->textBox10->Size = System::Drawing::Size(121, 20);
			this->textBox10->TabIndex = 36;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(339, 28);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(131, 23);
			this->button2->TabIndex = 35;
			this->button2->Text = L"Поиск по фамилии";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// tabPage5
			// 
			this->tabPage5->Controls->Add(this->label22);
			this->tabPage5->Controls->Add(this->label21);
			this->tabPage5->Controls->Add(this->label20);
			this->tabPage5->Controls->Add(this->label19);
			this->tabPage5->Controls->Add(this->label18);
			this->tabPage5->Controls->Add(this->label11);
			this->tabPage5->Controls->Add(this->dateTimePicker5);
			this->tabPage5->Controls->Add(this->dateTimePicker4);
			this->tabPage5->Controls->Add(this->dateTimePicker3);
			this->tabPage5->Controls->Add(this->comboBox11);
			this->tabPage5->Controls->Add(this->textBox9);
			this->tabPage5->Controls->Add(this->comboBox10);
			this->tabPage5->Controls->Add(this->textBox8);
			this->tabPage5->Controls->Add(this->comboBox8);
			this->tabPage5->Controls->Add(this->textBox7);
			this->tabPage5->Controls->Add(this->comboBox3);
			this->tabPage5->Controls->Add(this->richTextBox2);
			this->tabPage5->Controls->Add(this->button8);
			this->tabPage5->Controls->Add(this->button5);
			this->tabPage5->Location = System::Drawing::Point(4, 22);
			this->tabPage5->Name = L"tabPage5";
			this->tabPage5->Size = System::Drawing::Size(1053, 195);
			this->tabPage5->TabIndex = 2;
			this->tabPage5->Text = L"Подбор";
			this->tabPage5->UseVisualStyleBackColor = true;
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->Location = System::Drawing::Point(80, 162);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(20, 13);
			this->label22->TabIndex = 102;
			this->label22->Text = L"От";
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Location = System::Drawing::Point(349, 162);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(22, 13);
			this->label21->TabIndex = 101;
			this->label21->Text = L"До";
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Location = System::Drawing::Point(328, 6);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(87, 13);
			this->label20->TabIndex = 100;
			this->label20->Text = L"Стоимость тура";
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Location = System::Drawing::Point(557, 7);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(85, 13);
			this->label19->TabIndex = 99;
			this->label19->Text = L"Размер группы";
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Location = System::Drawing::Point(815, 6);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(96, 13);
			this->label18->TabIndex = 98;
			this->label18->Text = L"Дата начала тура";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(101, 8);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(136, 13);
			this->label11->TabIndex = 97;
			this->label11->Text = L"Продолжительность тура";
			// 
			// dateTimePicker5
			// 
			this->dateTimePicker5->Location = System::Drawing::Point(845, 23);
			this->dateTimePicker5->Name = L"dateTimePicker5";
			this->dateTimePicker5->Size = System::Drawing::Size(200, 20);
			this->dateTimePicker5->TabIndex = 96;
			// 
			// dateTimePicker4
			// 
			this->dateTimePicker4->Location = System::Drawing::Point(405, 155);
			this->dateTimePicker4->Name = L"dateTimePicker4";
			this->dateTimePicker4->Size = System::Drawing::Size(200, 20);
			this->dateTimePicker4->TabIndex = 95;
			// 
			// dateTimePicker3
			// 
			this->dateTimePicker3->Location = System::Drawing::Point(125, 156);
			this->dateTimePicker3->Name = L"dateTimePicker3";
			this->dateTimePicker3->Size = System::Drawing::Size(200, 20);
			this->dateTimePicker3->TabIndex = 94;
			// 
			// comboBox11
			// 
			this->comboBox11->FormattingEnabled = true;
			this->comboBox11->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L">", L"<", L"=" });
			this->comboBox11->Location = System::Drawing::Point(718, 22);
			this->comboBox11->Name = L"comboBox11";
			this->comboBox11->Size = System::Drawing::Size(121, 21);
			this->comboBox11->TabIndex = 91;
			this->comboBox11->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::comboBox2_KeyPress);
			// 
			// textBox9
			// 
			this->textBox9->Location = System::Drawing::Point(137, 24);
			this->textBox9->Name = L"textBox9";
			this->textBox9->Size = System::Drawing::Size(100, 20);
			this->textBox9->TabIndex = 90;
			this->textBox9->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::textBox1_KeyPress);
			// 
			// comboBox10
			// 
			this->comboBox10->FormattingEnabled = true;
			this->comboBox10->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L">", L"<", L"=" });
			this->comboBox10->Location = System::Drawing::Point(9, 24);
			this->comboBox10->Name = L"comboBox10";
			this->comboBox10->Size = System::Drawing::Size(121, 21);
			this->comboBox10->TabIndex = 88;
			this->comboBox10->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::comboBox2_KeyPress);
			// 
			// textBox8
			// 
			this->textBox8->Location = System::Drawing::Point(612, 23);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(100, 20);
			this->textBox8->TabIndex = 87;
			this->textBox8->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::textBox1_KeyPress);
			// 
			// comboBox8
			// 
			this->comboBox8->FormattingEnabled = true;
			this->comboBox8->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L">", L"<", L"=" });
			this->comboBox8->Location = System::Drawing::Point(484, 23);
			this->comboBox8->Name = L"comboBox8";
			this->comboBox8->Size = System::Drawing::Size(121, 21);
			this->comboBox8->TabIndex = 85;
			this->comboBox8->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::comboBox2_KeyPress);
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(378, 24);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(100, 20);
			this->textBox7->TabIndex = 84;
			this->textBox7->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::cenapress);
			// 
			// comboBox3
			// 
			this->comboBox3->FormattingEnabled = true;
			this->comboBox3->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L">", L"<", L"=" });
			this->comboBox3->Location = System::Drawing::Point(250, 24);
			this->comboBox3->Name = L"comboBox3";
			this->comboBox3->Size = System::Drawing::Size(121, 21);
			this->comboBox3->TabIndex = 82;
			this->comboBox3->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::comboBox2_KeyPress);
			// 
			// richTextBox2
			// 
			this->richTextBox2->Location = System::Drawing::Point(9, 48);
			this->richTextBox2->Name = L"richTextBox2";
			this->richTextBox2->Size = System::Drawing::Size(883, 96);
			this->richTextBox2->TabIndex = 81;
			this->richTextBox2->Text = L"";
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(682, 150);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(317, 37);
			this->button8->TabIndex = 80;
			this->button8->Text = L"Вывести информацию о свободных группах в диапазоне дат в файл\r\n\r\n";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &MyForm::button8_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(898, 46);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(131, 23);
			this->button5->TabIndex = 65;
			this->button5->Text = L"Подбор";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// tabPage4
			// 
			this->tabPage4->Location = System::Drawing::Point(0, 0);
			this->tabPage4->Name = L"tabPage4";
			this->tabPage4->Size = System::Drawing::Size(200, 100);
			this->tabPage4->TabIndex = 0;
			this->tabPage4->Text = L"tabPage4";
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1063, 227);
			this->Controls->Add(this->tabControl1);
			this->Name = L"MyForm";
			this->Text = L"Программа";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MyForm::MyForm_FormClosing);
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			this->tabPage2->ResumeLayout(false);
			this->tabPage2->PerformLayout();
			this->tabPage3->ResumeLayout(false);
			this->tabPage3->PerformLayout();
			this->tabPage5->ResumeLayout(false);
			this->tabPage5->PerformLayout();
			this->ResumeLayout(false);

		}


		int countg = 0;///количество групп

		std::string stdconvert(String ^s);///функция преобазования System^ String  в std::string. При помощи Marshal. Возвращает std::string 

		void resizemass();///функция для увеличения размера массива групп. 

		void saveThis();//сохранение

		bool datechek(String^ s, int indexMass, String^ valueForChek);

		bool razmchek(String^ s, int indexMass, String^ valueForChek);

		bool stoimchek(String^ s, int indexMass, String^ valueForChek);

		bool prodolchek(String^ s, int indexMass, String^ valueForChek);

		bool firstpagetest();

		bool page4test();

#pragma endregion

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e);///добавление группы

	private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e);///добавление человек в группу из файла

	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e);///поиск по фамилии

	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e);///удаление члена группы

	private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e);///подбор группы по выбраным требованиям

	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e);///добавить человека в группу

	private: System::Void button8_Click(System::Object^  sender, System::EventArgs^  e);///свободные на данный момент группы записываются в файл 

	private: System::Void MyForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e);///событие до закрытия формы, чистящее память(удаление массива)

	private: System::Void textBox1_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e);///запрет ввода не цифр в поля(событие)

	private: System::Void comboBox2_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e);///запрет на ввод любых символов с клавиатуры

			 ///для своевременного обновления информации в ричбоксах
	private: System::Void comboBox1_TextChanged(System::Object^  sender, System::EventArgs^  e);

	private: System::Void comboBox2_TextChanged(System::Object^  sender, System::EventArgs^  e);

	private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e);//загрузка предыдущей сессии

	private: System::Void textBox5_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e);

	private: System::Void cenapress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e);
}
	; }
