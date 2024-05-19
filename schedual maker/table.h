#pragma once
#include<cmath>
#include<fstream>
#include <msclr/marshal_cppstd.h>
#include<string>
value struct timeBlock
{
	bool* x;
	int startH, startM;
	int finishH, finishM;
	int day;
	bool PM;
};
namespace schedualmaker {


	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for scheduelre
	/// </summary>

	public ref class scheduelre : public System::Windows::Forms::Form
	{

		int top = 0;
	public:
		scheduelre(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~scheduelre()
		{
			if (components)
			{
				delete components;
			}
		}
	
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ openToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ saveAsToolStripMenuItem;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::CheckedListBox^ checkedListBox1;
	private: System::Windows::Forms::TextBox^ Nvalves;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ time;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ saturday;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ sunday;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ monday;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ tuesday;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ wednesday;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ thursday;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ friday;
	private: System::Windows::Forms::ToolStripMenuItem^ saveToolStripMenuItem;
	private: System::Windows::Forms::Label^ statusLab;
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>

		void InitializeComponent(void)
		{
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveAsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->time = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->saturday = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->sunday = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->monday = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->tuesday = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->wednesday = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->thursday = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->friday = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->checkedListBox1 = (gcnew System::Windows::Forms::CheckedListBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->Nvalves = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->statusLab = (gcnew System::Windows::Forms::Label());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->fileToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1565, 28);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->BackColor = System::Drawing::SystemColors::ControlDark;
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->openToolStripMenuItem,
					this->saveAsToolStripMenuItem, this->saveToolStripMenuItem
			});
			this->fileToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(44, 24);
			this->fileToolStripMenuItem->Text = L"&file";
			// 
			// openToolStripMenuItem
			// 
			this->openToolStripMenuItem->Name = L"openToolStripMenuItem";
			this->openToolStripMenuItem->Size = System::Drawing::Size(224, 26);
			this->openToolStripMenuItem->Text = L"&open";
			this->openToolStripMenuItem->Click += gcnew System::EventHandler(this, &scheduelre::openToolStripMenuItem_Click);
			// 
			// saveAsToolStripMenuItem
			// 
			this->saveAsToolStripMenuItem->Name = L"saveAsToolStripMenuItem";
			this->saveAsToolStripMenuItem->Size = System::Drawing::Size(224, 26);
			this->saveAsToolStripMenuItem->Text = L"save &as";
			// 
			// saveToolStripMenuItem
			// 
			this->saveToolStripMenuItem->Name = L"saveToolStripMenuItem";
			this->saveToolStripMenuItem->Size = System::Drawing::Size(224, 26);
			this->saveToolStripMenuItem->Text = L"save";
			this->saveToolStripMenuItem->Click += gcnew System::EventHandler(this, &scheduelre::saveToolStripMenuItem_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowDrop = true;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(8) {
				this->time, this->saturday,
					this->sunday, this->monday, this->tuesday, this->wednesday, this->thursday, this->friday
			});
			this->dataGridView1->Location = System::Drawing::Point(12, 60);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(1419, 558);
			this->dataGridView1->TabIndex = 1;
			this->dataGridView1->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &scheduelre::dataGridView1_CellClick);
			this->dataGridView1->CellDoubleClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &scheduelre::dataGridView1_CellDoubleClick);
			// 
			// time
			// 
			dataGridViewCellStyle1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->time->DefaultCellStyle = dataGridViewCellStyle1;
			this->time->Frozen = true;
			this->time->HeaderText = L"time";
			this->time->MinimumWidth = 6;
			this->time->Name = L"time";
			this->time->ReadOnly = true;
			this->time->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->time->Width = 125;
			// 
			// saturday
			// 
			this->saturday->HeaderText = L"saturday";
			this->saturday->MinimumWidth = 6;
			this->saturday->Name = L"saturday";
			this->saturday->ReadOnly = true;
			this->saturday->Width = 125;
			// 
			// sunday
			// 
			this->sunday->HeaderText = L"sunday";
			this->sunday->MinimumWidth = 6;
			this->sunday->Name = L"sunday";
			this->sunday->ReadOnly = true;
			this->sunday->Width = 125;
			// 
			// monday
			// 
			this->monday->HeaderText = L"monday";
			this->monday->MinimumWidth = 6;
			this->monday->Name = L"monday";
			this->monday->ReadOnly = true;
			this->monday->Width = 125;
			// 
			// tuesday
			// 
			this->tuesday->HeaderText = L"tuesday";
			this->tuesday->MinimumWidth = 6;
			this->tuesday->Name = L"tuesday";
			this->tuesday->ReadOnly = true;
			this->tuesday->Width = 125;
			// 
			// wednesday
			// 
			this->wednesday->HeaderText = L"wednesday";
			this->wednesday->MinimumWidth = 6;
			this->wednesday->Name = L"wednesday";
			this->wednesday->ReadOnly = true;
			this->wednesday->Width = 125;
			// 
			// thursday
			// 
			this->thursday->HeaderText = L"thursday";
			this->thursday->MinimumWidth = 6;
			this->thursday->Name = L"thursday";
			this->thursday->ReadOnly = true;
			this->thursday->Width = 125;
			// 
			// friday
			// 
			this->friday->HeaderText = L"friday";
			this->friday->MinimumWidth = 6;
			this->friday->Name = L"friday";
			this->friday->ReadOnly = true;
			this->friday->Width = 125;
			// 
			// panel1
			// 
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel1->Controls->Add(this->checkedListBox1);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->textBox2);
			this->panel1->Controls->Add(this->textBox1);
			this->panel1->Controls->Add(this->button1);
			this->panel1->Location = System::Drawing::Point(297, 183);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(268, 285);
			this->panel1->TabIndex = 3;
			this->panel1->Visible = false;
			// 
			// checkedListBox1
			// 
			this->checkedListBox1->FormattingEnabled = true;
			this->checkedListBox1->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"1", L"2", L"3", L"4" });
			this->checkedListBox1->Location = System::Drawing::Point(6, 35);
			this->checkedListBox1->Name = L"checkedListBox1";
			this->checkedListBox1->Size = System::Drawing::Size(137, 225);
			this->checkedListBox1->TabIndex = 3;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(3, 63);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(65, 16);
			this->label3->TabIndex = 2;
			this->label3->Text = L"finish time";
			this->label3->Visible = false;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(3, 23);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(78, 16);
			this->label2->TabIndex = 2;
			this->label2->Text = L"starting time";
			this->label2->Visible = false;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(86, 60);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(158, 22);
			this->textBox2->TabIndex = 1;
			this->textBox2->Visible = false;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(86, 20);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(158, 22);
			this->textBox1->TabIndex = 1;
			this->textBox1->Visible = false;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(169, 237);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"save";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &scheduelre::button1_Click);
			// 
			// Nvalves
			// 
			this->Nvalves->Location = System::Drawing::Point(705, 13);
			this->Nvalves->Name = L"Nvalves";
			this->Nvalves->Size = System::Drawing::Size(100, 22);
			this->Nvalves->TabIndex = 4;
			this->Nvalves->Text = L"3";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(561, 19);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(116, 16);
			this->label4->TabIndex = 5;
			this->label4->Text = L"number of valvues";
			// 
			// statusLab
			// 
			this->statusLab->AutoSize = true;
			this->statusLab->Location = System::Drawing::Point(263, 18);
			this->statusLab->Name = L"statusLab";
			this->statusLab->Size = System::Drawing::Size(0, 16);
			this->statusLab->TabIndex = 6;
			// 
			// scheduelre
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1565, 674);
			this->Controls->Add(this->statusLab);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->Nvalves);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->menuStrip1);
			this->Name = L"scheduelre";
			this->Text = L"scheduelre";
			this->Load += gcnew System::EventHandler(this, &scheduelre::scheduelre_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		};
		private: array<timeBlock>^ allBlocks = gcnew array<timeBlock>(100);
#pragma endregion
	private: System::Void scheduelre_Load(System::Object^ sender, System::EventArgs^ e)
	{
		int x = 0;
		for (float i = 0; i < 24; i += 0.5)
		{
			dataGridView1->Rows->Add(DateTime(DateTime::Now.Year, DateTime::Now.Month, DateTime::Now.Day, (((int)i + 7) % 24), fmod(i, 1) * 60, 0).ToString("HH:mm"));
		}
	}
	private: System::Void dataGridView1_CellDoubleClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
	{
		checkedListBox1->Items->Clear();
		if (Nvalves->Text != "")
		{
			int n = Convert::ToInt16(Nvalves->Text);
			for (int i = 0; i < n; i++)
			{
				checkedListBox1->Items->Add("V" + (i + 1).ToString());
			}
		}
		//pop up panel
		panel1->Location = System::Drawing::Point(dataGridView1->SelectedCells[0]->ColumnIndex * dataGridView1->Columns[0]->Width + 180 - dataGridView1->HorizontalScrollingOffset, (dataGridView1->SelectedCells[0]->RowIndex * dataGridView1->RowTemplate->Height) - dataGridView1->VerticalScrollingOffset);
		panel1->Visible = 1;
	}
	private: System::Void dataGridView1_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
	{
		panel1->Visible = 0;
	}
	void mySwap(timeBlock %b1, timeBlock %b2)
	{
		timeBlock temp = b1;
		b1 = b2;
		b2 = temp;
	}
	void sortData(int rows) 
	{
		for (int i = 0; i <rows;i++)//buble sorting
		{
			for (int j = 0; j <rows-i-1; j++)
			{
				if(allBlocks[j+1].x != NULL)
				{
					if (allBlocks[j].day > allBlocks[j + 1].day)
						mySwap(allBlocks[j], allBlocks[j + 1]);
					else if (allBlocks[j].day == allBlocks[j + 1].day)
					{
						if (allBlocks[j].startH > allBlocks[j + 1].startH)
							mySwap(allBlocks[j], allBlocks[j + 1]);
						else if (allBlocks[j].startH == allBlocks[j + 1].startH)
							if (allBlocks[j].startM > allBlocks[j + 1].startM)
								mySwap(allBlocks[j], allBlocks[j + 1]);
					}

				}
			}
		}
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e)
	{
		timeBlock t;
		t.x = new bool[Convert::ToInt32(Nvalves->Text)];
		for (int i = 0; i < Convert::ToInt32(Nvalves->Text); i++)
			t.x[i] = 0;
		int row = dataGridView1->SelectedCells[0]->RowIndex;

		//starting if empty

		t.startH = ((safe_cast<int>(dataGridView1->Rows[row]->Cells[0]->Value->ToString()[0] * 10) % 12 + (safe_cast<int>(dataGridView1->Rows[row]->Cells[0]->Value->ToString()[1]) % 12)));
		t.startM = Convert::ToInt32(((dataGridView1->Rows[row]->Cells[0]->Value->ToString()[3].ToString()))) * 10;

		//day
		t.day = dataGridView1->SelectedCells[0]->ColumnIndex;

		//default
		t.finishM = (t.startM + 30) % 60;
		if (t.finishM == 0)
			t.finishH = t.startH + 1;
		else
			t.finishH = t.startH;
		int j = 0;
		int valves = Convert::ToInt32(Nvalves->Text);
		//for valves
		dataGridView1->SelectedCells[0]->Style->BackColor = Color::Red;
		for (int i = 0; i < valves; i++)
		{
			if (checkedListBox1->CheckedItems->Count == 0)
				break;
			if (checkedListBox1->Items[i]->ToString() == checkedListBox1->CheckedItems[j]->ToString()) {

				t.x[i] = 1;
				j++;
				//to avoid more saving after selcted finish but the original not finished
				if (j >= checkedListBox1->CheckedItems->Count)
					break;
			}
		}dataGridView1->ClearSelection();
		panel1->Hide();
		allBlocks[top] = t;
		top++;
	}
	private: void searchFor(timeBlock* tim)//rethink delete
	{
		bool off = tim->startM;
		int rowI = 2 * (tim->startH) - 2 + off;
		dataGridView1->Rows[rowI]->Cells[0];
	}
	private: System::Void openToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		OpenFileDialog^ f = gcnew OpenFileDialog();
		f->ShowDialog();
		std::ifstream file;

		//for changin system::strgin to std::string
		msclr::interop::marshal_context context;
		std::string fileName = context.marshal_as<std::string>(f->FileName);

		file.open(fileName);
		std::string x;
		getline(file, x);
		System::String^ linesss = msclr::interop::marshal_as<System::String^>(x);

		MessageBox::Show(linesss);
	}
	private: System::Void saveToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		statusLab->Text = "ok";

		sortData(top);//pronlem null reftancve

		std::fstream file("tabel1.dat", std::ios::app);

		for (int i = 0; i < top; i++)
		{
			file << allBlocks[i].day;
			file << " "; 

			if (allBlocks[i].startH <= 9)
				file << "0";
			file << allBlocks[i].startH;

			file << " "; 
			if (allBlocks[i].startM <= 9)
				file << "0";
			file << allBlocks[i].startM;
			file << " ";

			if (allBlocks[i].finishH <= 9)
				file << "0";
			file << allBlocks[i].finishH;
			file << " "; 

			if (allBlocks[i].finishM <= 9)
				file << "0";
			file << allBlocks[i].finishM;
			file << " ";
			
			for (int j = 0; j < Convert::ToInt32(Nvalves->Text); j++)
			{
				file << allBlocks[i].x[j];
				file << " ";
			}
			file << "\n";
			statusLab->Text = "saveed";
		}
}
};
}
