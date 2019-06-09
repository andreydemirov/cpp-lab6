// cpp-lab6.cpp
//

#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Product {
	int cost;
};

struct Client {
	string name;
	string surname;
	Product product;
	int quantity_mec_client;
	int quantity_mec;
	int cost_client;
};

// ввод данных
void Init(Client* arr, const int n)
{
	cout << "ВВедите имя клиента: ";
	getline(cin, arr[i].name);
	cout << "ВВедите фимилию клиента: ";
	cin >> arr[i].surname; cin.ignore();
	cout << "ВВедите стоимость  оплаты услуг за 1 мес: ";
	cin >> arr[i].cost; cin.ignore();
	cout << "Введите кол-во месяцев за которые заплатил клиент: ";
	cin >> arr[i].quantity.mec(); cin.ignore();
	cout << "Введите кол-во месяцев за которые заплатил клиент вперед: ";
	cin >> arr[i].quantity.mec.client();
	cout << endl;
}

// вывод данных
void Print(Client* arr, const int n)
{
	cout << "\nКлиенты: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "Имя клиента: " << arr[i].name;
		cout << "Фамилия клиента: " << arr[i].surname;
		cout << "Кол-во месяцев оплаченых клиентом: " << arr[i].quantity_mec;
		cout << "Кол-во месяцев оплаченых клиентом наперед: " << arr[i].quantity_mec_client;
		cout << "-----------------------" << endl;
	}
}

void Write(Student* arr, const int n) {
	ofstream file("C:\\Users\\BOSS\\Desktop\\file.txt", ios::binary | ios::in);
	if (file.is_open()) {
		file.write((char*)& n, sizeof n);
		for (int i = 0; i < n; i++)
		{
			if (arr[i].quantity_mec_client > 3 && arr[i].quantity_mec > 3) {

				arr[i].cost_client = ((arr[i].cost * (arr[i].quantity_mec + arr[i].quantity_mec_client)) / 100) * 95;
				file.write((char*)& arr[i].name, sizeof arr[i].name);
				file.write((char*)& arr[i].surname, sizeof arr[i].surname);
				file.write((char*)& arr[i].cost, sizeof arr[i].cost);
				file.write((char*)& arr[i].quantity_mec, sizeof arr[i].quantity_mec);
				file.write((char*)& arr[i].quantity_mec_client, sizeof arr[i].quantity_mec_client);
				file.write((char*)& arr[i].cost_client, sizeof arr[i].cost_client);

			}

			else {
				file.write((char*)& arr[i].name, sizeof arr[i].name);
				file.write((char*)& arr[i].surname, sizeof arr[i].surname);
				file.write((char*)& arr[i].cost, sizeof arr[i].cost);
				file.write((char*)& arr[i].quantity_mec, sizeof arr[i].quantity_mec);
				file.write((char*)& arr[i].quantity_mec_client, sizeof arr[i].quantity_mec_client);
				file.write((char*)& arr[i].cost_client, sizeof arr[i].cost_client);
			}
		}
	}
	else {
		cout << "Ошибка открытия файла!" << endl;
	}
	file.close();
}

int main()
{
	setlocale(LC_ALL, "ru");

	int n;
	cout << "Введите кол-во клиентов: ";
	cin >> n;
	cin.ignore();

	Client* arr = new Client[n];
	Init(arr, n);
	Print(arr, n);
	Write(arr, n);
	cout << endl << "Обновленные записи" << endl;
	
	// считывание с файла

	int lenght;
	ifstream file("C:\\Users\\BOSS\\Desktop\\file.txt", ios::binary);
	file.read((char*)& length, sizeof length);
	Student* arrUpdated = new Student[length];
	if (file.is_open()) {

		for (int i = 0; i < lenght; i++) {
			file.read((char*)& arrUpdated[i].name, sizeof arrUpdated[i].name);
			file.read((char*)& arrUpdated[i].surname, sizeof arrUpdated[i].surname);
			file.read((char*)& arrUpdated[i].cost, sizeof arrUpdated[i].cost);
			file.read((char*)& arrUpdated[i].quantity_mec, sizeof arrUpdated[i].quantity_mec);
			file.read((char*)& arrUpdated[i].quantity_mec_client, sizeof arrUpdated[i].quantity_mec_client);
			file.read((char*)& arrUpdated[i].cost_client, sizeof arrUpdated[i].cost_client);
		}
	}
	else {
		cout << "Ошибка открытия!" << endl;
	}
	file.close();

	Print(arrUpdated, n);

	delete[] arr;
	delete[] arrrUpdated;
	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
