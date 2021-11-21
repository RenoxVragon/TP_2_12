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
				cout << "������������ ����. ���������� ��� ���: " << endl;
			else
				return choice;
		}
		else
			cout << "������������ ����. ���������� ��� ���: " << endl;
	}
}

void print_main_menu()
{
	cout << "������� ���� ������ � ��������� � ���������� ��������." << endl;
	cout << "�������� ��������: " << endl;
	cout << "1. ������� ����." << endl;
	cout << "2. ������� �� ����� �����������, ������������ � ���� (-)." << endl;
	cout << "3. �������� ����� �����." << endl;
	cout << "0. ��������� ������." << endl;
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
		cout << "����������� � ����:\n" << out.c_str() << endl;
		break;
	case 3: 
		cout << "����� �� �����: \n" << s << endl;;
		break;
	case 0:
		exit(0);
		break;
	default:
		cout << "������ �������� ����� ����. ���������� ��� ���." << endl;
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