#pragma once
#include <math.h>
#include <vector>
double func(double x) {
    double f = 2 * pow(x, 3) + 9 * pow(x, 2) - 10;
    return f;
}
double BisectionMethod(double a, double b, double e, double* x, double len, int* k) {
    double fx = func(*x);
    while (len > e) {
        double y = a + len / 4;
        double z = b - len / 4;
        double fy = func(y);
        double fz = func(z);
        if (fy < fx) {
            b = *x;
            *x = y;
        }
        else {
            if (fz < fx) {
                a = *x;
                *x = z;
            }
            else {
                a = y;
                b = z;
            }
        }
        *k += 1;
        len = fabs(b - a);
    }
    return fx = func(*x);
}

double MaxBisectionMethod(double a, double b, double e, double* x, double len, int* k) {
    double fx = func(*x);
    while (len > e) {
        double y = a + len / 4;
        double z = b - len / 4;
        double fy = func(y);
        double fz = func(z);
        if (fy > fx) {
            b = *x;
            *x = y;
        }
        else {
            if (fz > fx) {
                a = *x;
                *x = z;
            }
            else {
                a = y;
                b = z;
            }
        }
        *k += 1;
        len = fabs(b - a);
    }
    return fx = func(*x);
}

double GoldensectionMethod(double a, double b, double e, double* x, double len, int* k) {
    double y = a + ((3 - sqrt(5)) / 2) * (b - a);
    double z = a + b - y;
    //len = abs(a - b);
    do {
        double fy = func(y);
        double fz = func(z);
        if (fy <= fz) {
            b = z;
            z = y;
            y = a + b - y;

        }
        else {

            a = y;
            y = z;
            z = a + b - z;
        }
        *k += 1;
        len = abs(a - b);
    } while (len > e);
    *x = (a + b) / 2;
    double fx = func(*x);
    return fx;
}

double MaxGoldensectionMethod(double a, double b, double e, double* x, double len, int* k) {
    double y = a + ((3 - sqrt(5)) / 2) * (b - a);
    double z = a + b - y;
    //len = abs(a - b);
    do {
        double fy = func(y);
        double fz = func(z);
        if (fy >= fz) {
            b = z;
            z = y;
            y = a + b - y;

        }
        else {

            a = y;
            y = z;
            z = a + b - z;
        }
        *k += 1;
        len = abs(a - b);
    } while (len > e);
    *x = (a + b) / 2;
    double fx = func(*x);
    return fx;
}

int NumsFibonacci(double N, std::vector<double>& nums) {

    if (N < 1)
        nums.push_back(1);
    else {
        nums.push_back(1);
        nums.push_back(1);


        for (int i = 2; i < N; i++) {
            nums.push_back(nums[i - 2] + nums[i - 1]);
        }
    }
    return nums.size() - 1;
    /*for (int i = 0; i < N; i++)
        std::cout << nums[i]<<" ";*/
}

double FibonacciMethod(double a, double b, double e, double* x, double len, int* k) {
    std::vector<double> fibnums;
    double l = 2 * e;
    double fn = len / l;
    double N = NumsFibonacci(fn, fibnums);
    double y = a + (fibnums[N - 2] / fibnums[N]) * (b - a);
    double z = a + (fibnums[N - 1] / fibnums[N]) * (b - a);
    while (*k != N - 3) {
        double fy = func(y);
        double fz = func(z);
        if (fy <= fz) {

            b = z;
            z = y;
            y = a + (fibnums[N - *k - 3] / fibnums[N - *k - 1]) * (b - a);
        }
        else {
            a = y;
            y = z;
            z = a + (fibnums[N - *k - 2] / fibnums[N - *k - 1]) * (b - a);
        }
        *k += 1;
    }
    y = (a + b) / 2;
    z = y + e;
    double fy = func(y);
    double fz = func(z);
    if (fy > fz)
        a = y;
    else
        b = z;
    *x = (a + b) / 2;
    double fx = func(*x);
    return fx;
}

double MaxFibonacciMethod(double a, double b, double e, double* x, double len, int* k) {
    std::vector<double> fibnums;
    double l = 2 * e;
    double fn = len / l;
    double N = NumsFibonacci(fn, fibnums);
    double y = a + (fibnums[N - 2] / fibnums[N]) * (b - a);
    double z = a + (fibnums[N - 1] / fibnums[N]) * (b - a);
    while (*k != N - 3) {
        double fy = func(y);
        double fz = func(z);
        if (fy >= fz) {

            b = z;
            z = y;
            y = a + (fibnums[N - *k - 3] / fibnums[N - *k - 1]) * (b - a);
        }
        else {
            a = y;
            y = z;
            z = a + (fibnums[N - *k - 2] / fibnums[N - *k - 1]) * (b - a);
        }
        *k += 1;
    }
    y = (a + b) / 2;
    z = y + e;
    double fy = func(y);
    double fz = func(z);
    if (fy < fz)
        a = y;
    else
        b = z;
    *x = (a + b) / 2;
    double fx = func(*x);
    return fx;
}



namespace molab {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ button1;
    private: System::Windows::Forms::TextBox^ textBox3;






	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->textBox1 = (gcnew System::Windows::Forms::TextBox());
            this->textBox2 = (gcnew System::Windows::Forms::TextBox());
            this->label4 = (gcnew System::Windows::Forms::Label());
            this->button1 = (gcnew System::Windows::Forms::Button());
            this->textBox3 = (gcnew System::Windows::Forms::TextBox());
            this->SuspendLayout();
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->LiveSetting = System::Windows::Forms::Automation::AutomationLiveSetting::Polite;
            this->label1->Location = System::Drawing::Point(40, 27);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(479, 80);
            this->label1->TabIndex = 0;
            this->label1->Text = L"Выберите способ, которым хотите найти экстремум функции:\n1-Метод половинного деле"
                L"ния\n2-Метод \"золотого\" cечения\n3-Метод чисел Фибоначчи ";
            // 
            // label2
            // 
            this->label2->Location = System::Drawing::Point(40, 163);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(233, 67);
            this->label2->TabIndex = 1;
            this->label2->Text = L"Выберите что хотите найти:\n1-Минимум\n2-Максимум ";
            // 
            // textBox1
            // 
            this->textBox1->Location = System::Drawing::Point(316, 81);
            this->textBox1->Name = L"textBox1";
            this->textBox1->Size = System::Drawing::Size(100, 26);
            this->textBox1->TabIndex = 2;
            // 
            // textBox2
            // 
            this->textBox2->Location = System::Drawing::Point(316, 193);
            this->textBox2->Name = L"textBox2";
            this->textBox2->Size = System::Drawing::Size(100, 26);
            this->textBox2->TabIndex = 3;
            this->textBox2->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox2_TextChanged);
            // 
            // label4
            // 
            this->label4->AutoSize = true;
            this->label4->Location = System::Drawing::Point(713, 36);
            this->label4->Name = L"label4";
            this->label4->Size = System::Drawing::Size(263, 60);
            this->label4->TabIndex = 5;
            this->label4->Text = L"Дано:\nФункция: 2x^3 + 9x^2 - 10\nПромежуток: [-1;1],  Эпсилон = 0.2";
            // 
            // button1
            // 
            this->button1->Location = System::Drawing::Point(53, 252);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(110, 51);
            this->button1->TabIndex = 6;
            this->button1->Text = L"Pacчитать";
            this->button1->UseVisualStyleBackColor = true;
            this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
            // 
            // textBox3
            // 
            this->textBox3->Location = System::Drawing::Point(240, 264);
            this->textBox3->Name = L"textBox3";
            this->textBox3->Size = System::Drawing::Size(506, 26);
            this->textBox3->TabIndex = 7;
           
            // 
            // MyForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(1317, 577);
            this->Controls->Add(this->textBox3);
            this->Controls->Add(this->button1);
            this->Controls->Add(this->label4);
            this->Controls->Add(this->textBox2);
            this->Controls->Add(this->textBox1);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->label1);
            this->Name = L"MyForm";
            this->Text = L"MyForm";
            this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	
	private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
    private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
    }


private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	int val = System::Convert::ToInt32(textBox1->Text);
	int ext = System::Convert::ToInt32(textBox2->Text);
	int k = 0;
	double a = -1;
	double b = 1;
	double eps = 0.2;
	double x = (a + b) / 2;
	double len = fabs(b - a);
	double f;

    if (ext == 1) {
        switch (val) {
        case 1: f = BisectionMethod(a, b, eps, &x, len, &k); break;

        case 2: f = GoldensectionMethod(a, b, eps, &x, len, &k); break;

        case 3: f = FibonacciMethod(a, b, eps, &x, len, &k); break;

        }
    }

    if (ext == 2) {
        switch (val) {

        case 1: f = MaxBisectionMethod(a, b, eps, &x, len, &k); break;

        case 2: f = MaxGoldensectionMethod(a, b, eps, &x, len, &k); break;

        case 3: f = MaxFibonacciMethod(a, b, eps, &x, len, &k); break;
        }
    }
     textBox3->Text = "x: " + x.ToString("F2") +"  "+"f(x): "+ f.ToString("F2") +"  " + "k: " + (k+1).ToString("F0");
}
      


};
}
