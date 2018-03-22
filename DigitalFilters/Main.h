#pragma once

#include "Filters.h"

namespace DigitalFilters {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Main
	/// </summary>
	public ref class Main : public System::Windows::Forms::Form
	{
	public:
		Main(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		
	private: System::Windows::Forms::Button^  btnBrowse;
	private: System::Windows::Forms::OpenFileDialog^  FileDialog;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::Button^  button8;

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Main()
		{
			if (components)
			{
				delete components;
			}
		}

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

			this->components = gcnew System::ComponentModel::Container();
			this->Size = System::Drawing::Size(300,300);
			this->Text = L"Main";
			this->Padding = System::Windows::Forms::Padding(0);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;


			this->btnBrowse = (gcnew System::Windows::Forms::Button());
			this->FileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// btnBrowse
			// 
			this->btnBrowse->Location = System::Drawing::Point(12, 12);
			this->btnBrowse->Name = L"btnBrowse";
			this->btnBrowse->Size = System::Drawing::Size(113, 28);
			this->btnBrowse->TabIndex = 0;
			this->btnBrowse->Text = L"Αναζήτηση ...";
			this->btnBrowse->UseVisualStyleBackColor = true;
			this->btnBrowse->Click += gcnew System::EventHandler(this, &Main::btnBrowse_Click);
			// 
			// FileDialog
			// 
			this->FileDialog->FileName = L"dsfsdf";
			this->FileDialog->Filter = L"Αρχεία εικόνων|*.BMP;*.GIF;*.JPG;*.JPEG;*.PNG;*.TIFF|Όλα τα αρχεία|*.*";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(12, 46);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(600, 450);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(12, 516);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(94, 27);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Gaussian Noise";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Main::button1_Click);
			// 
			// pictureBox2
			// 
			this->pictureBox2->Location = System::Drawing::Point(627, 46);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(600, 450);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox2->TabIndex = 3;
			this->pictureBox2->TabStop = false;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(112, 516);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(94, 27);
			this->button2->TabIndex = 4;
			this->button2->Text = L"Average blur";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Main::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(627, 12);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(105, 27);
			this->button3->TabIndex = 5;
			this->button3->Text = L"Στην Αρχική";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Main::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(212, 516);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(121, 27);
			this->button4->TabIndex = 6;
			this->button4->Text = L"Salt/Pepper noise";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Main::button4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(339, 516);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(121, 27);
			this->button5->TabIndex = 7;
			this->button5->Text = L"Edge detection sobel";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &Main::button5_Click);
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(466, 516);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(121, 27);
			this->button6->TabIndex = 8;
			this->button6->Text = L"Edge detection prewitt";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &Main::button6_Click);
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(593, 516);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(121, 27);
			this->button7->TabIndex = 9;
			this->button7->Text = L"Adaptive Tresholding";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &Main::button7_Click);
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(720, 516);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(131, 27);
			this->button8->TabIndex = 10;
			this->button8->Text = L"Anisotropic Difussion";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &Main::button8_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1291, 617);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->btnBrowse);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion


	private: System::String^ _filename;
	private: Bitmap^ _currentImage;
	private: Bitmap^ _alteredImage;

	private: System::Void btnBrowse_Click(System::Object^  sender, System::EventArgs^  e) {
		System::Windows::Forms::DialogResult res = this->FileDialog->ShowDialog();
		if (res == System::Windows::Forms::DialogResult::OK)
		{
			_filename = FileDialog->FileName;
			ShowImage(_filename);
		}
	}

	private:	 void ShowImage(System::String^ fileName)
	{
		_currentImage = (Bitmap^)Image::FromFile(fileName);
		pictureBox1->Image = _currentImage;
		pictureBox1->Refresh();
	}


	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		_alteredImage = Filters::GaussianNoise(_currentImage, 0, 30);
		pictureBox2->Image = _alteredImage;
	}

	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		_alteredImage = Filters::Average(_currentImage, 3);
		pictureBox2->Image = _alteredImage;
		pictureBox2->Refresh();
	}
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
		_currentImage = _alteredImage;
		pictureBox1->Image = _currentImage;
	}
	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
		_alteredImage = Filters::SaltPepper(_currentImage, 0.1);
		pictureBox2->Image = _alteredImage;
		pictureBox2->Refresh();

	}
	private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
		_alteredImage = Filters::Sobel(_currentImage);
		pictureBox2->Image = _alteredImage;
		pictureBox2->Refresh();

	}
	private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
		_alteredImage = Filters::Prewitt(_currentImage);
		pictureBox2->Image = _alteredImage;
		pictureBox2->Refresh();

	}
	private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e) {
		_alteredImage = Filters::AdaptiveThresholing(_currentImage, 9);
		pictureBox2->Image = _alteredImage;
		pictureBox2->Refresh();
	}
	private: System::Void button8_Click(System::Object^  sender, System::EventArgs^  e) {
		_alteredImage = Filters::AnisotropicDifussion(_currentImage, 10, 20, 0.5);
		pictureBox2->Image = _alteredImage;
		pictureBox2->Refresh();
	}





	};
}
