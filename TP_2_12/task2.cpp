#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>
#include "streamswork.h"

using namespace std;

int process_choice(int min_range, int max_range)
{
	string str;
	while (1)
	{
		cin >> str;
		if (str.find_first_not_of("0123456789", 0) == string::npos)
		{
			int choice = stoi(str);
			if (choice < min_range || choice > max_range)
				cout << "Некорректный ввод. Попробуйте еще раз: " << endl;
			else
				return choice;
		}
		else
			cout << "Некорректный ввод. Попробуйте еще раз: " << endl;
	}
}

void print_main_menu()
{
	cout << "Главное меню работы с файловыми и строковоми потоками." << endl;
	cout << "Выберите действие: " << endl;
	cout << "1. Считать файл." << endl;
	cout << "2. Вывести на экран предложения, начинающиеся с тире (-)." << endl;
	cout << "3. Показать текст файла." << endl;
	cout << "0. Завершить работу." << endl;
}

string s = "";
string out = "";

void menu_selection(int number)
{
	system("cls");
	
	string str;
	switch (number)
	{
	case 1:
		s = file_load();
		break;
	case 2:
		out = find_dash_sentences(s);
		cout << "Предложения с тире:\n" << out.c_str() << endl;
		break;
	case 3: 
		cout << "Текст из файла: \n" << s << endl;;
		break;
	case 0:
		exit(0);
		break;
	default:
		cout << "Выбран неверный пункт меню. Попробуйте еще раз." << endl;
		break;
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	while (1)
	{
		print_main_menu();
		int choice = process_choice(0, 3);
		menu_selection(choice);
	}
}