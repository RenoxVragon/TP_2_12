//#define _CRT_SECURE_NO_WARNINGS 
//#include <iostream>
//#include <windows.h>
//#include "note.h";
//#include "keeper.h"
//using namespace std;
//
//Keeper<Note> keeper;
//
//int process_choice(int min_range, int max_range)
//{
//	string str;
//	while (1)
//	{
//		cin >> str;
//		if (str.find_first_not_of("0123456789", 0) == string::npos)
//		{
//			int choice = stoi(str);
//			if (choice < min_range || choice > max_range)
//				cout << "������������ ����. ���������� ��� ���: " << endl;
//			else
//				return choice;
//		}
//		else
//			cout << "������������ ����. ���������� ��� ���: " << endl;
//	}
//}
//
//void print_main_menu()
//{
//	cout << "������� ���� ������ � ���������������� ������� Keeper � ������� Note." << endl;
//	cout << "�������� ��������: " << endl;
//	cout << "1. �������� ��������." << endl;
//	cout << "2. ������� ��������." << endl;
//	cout << "3. �������� ��������." << endl;
//	cout << "4. �������� ���������� ������." << endl;
//	cout << "5. ����� �������� �� ������." << endl;
//	cout << "6. ��������� ������� ������ � �����." << endl;
//	cout << "7. ��������� ������ ������ �� �����." << endl;
//	cout << "0. ��������� ������." << endl;
//}
//
//Note n;
//
//void menu_selection(int number)
//{
//	system("cls");
//	int date[3];
//	int index = -1;
//	int flag = 1;
//	string str;
//	switch (number)
//	{
//	case 1:
//		cin.ignore();
//		n.set_info();
//		keeper += n;
//		break;
//	case 2:
//		if (keeper.get_size() > 0)
//		{
//			for (int i = 0; i < keeper.get_size(); i++)
//			{
//				cout << "������ �������: " << i << endl;
//				keeper[i].print_info();
//				cout << "\n" << endl;
//			}
//			cout << "�������� ������ �������, ������� ������ �������: " << endl;
//			index = process_choice(0, keeper.get_size() - 1);
//			keeper -= index;
//		}
//		else
//			cout << "������ ����, ������ �������." << endl;
//		break;
//	case 3:
//		if (keeper.get_size() > 0)
//		{
//			for (int i = 0; i < keeper.get_size(); i++)
//			{
//				cout << "������ �������: " << i << endl;
//				keeper[i].print_info();
//				cout << "\n" << endl;
//			}
//			cout << "�������� ������ �������, ������� ������ ��������: " << endl;
//			index = process_choice(0, keeper.get_size() - 1);
//			keeper[index].change_info();
//		}
//		else
//			cout << "������ ����, ������ �������." << endl;
//		break;
//	case 4:
//		if (keeper.get_size() > 0)
//		{
//			keeper.date_sort();
//			for (int i = 0; i < keeper.get_size(); i++)
//			{
//				cout << "������ �������: " << i << endl;
//				keeper[i].print_info();
//				cout << "\n" << endl;
//			}
//		}
//		else
//			cout << "������ ������." << endl;
//		break;
//	case 5:
//		cout << "������� ���������� ����� ��������, ������� � ���� +7: " << endl;
//		while (flag)
//		{
//			cin >> str;
//			if (str.find_first_not_of("+0123456789", 0) == string::npos)
//			{
//				flag = 0;
//			}
//			else
//				cout << "������������ ����. ���������� ��� ���: " << endl;
//		}
//		if (keeper.get_size() > 0)
//		{
//			for (int i = 0; i < keeper.get_size(); i++)
//			{
//				if (keeper[i].get_number() == str)
//				{
//					index = i;
//				}
//			}
//			if (index != -1)
//			{
//				cout << "������� � ����� ������� ������: " << endl;
//				keeper[index].print_info();
//			}
//			else
//				cout << "�������� � ����� ������� ��� � ������." << endl;
//		}
//		else
//			cout << "������ ����, ������ ������." << endl;
//		break;
//	case 6:
//		if (keeper.get_size() > 0)
//		{
//			for (int i = 0; i < keeper.get_size(); i++)
//			{
//				keeper[i].file_save();
//			}
//		}
//		else
//			cout << "������ ������." << endl;
//		break;
//	case 7:
//		n.file_load();
//		for (int i = 0; i < 3; i++)  date[i] = n.get_date(i);
//		if ((n.get_fio() == "") || (n.get_number() == "") || (date[0] == 0) || (date[1] == 0) || (date[2] == 0))
//		{
//			cout << "�� ������� ��������� ������." << endl;
//		}
//		else
//			keeper += n;
//		break;
//	case 0:
//		exit(0);
//		break;
//	default:
//		cout << "������ �������� ����� ����. ���������� ��� ���." << endl;
//		break;
//	}
//}
//
//int main()
//{
//	SetConsoleCP(1251);
//	SetConsoleOutputCP(1251);
//	setlocale(LC_ALL, "ru");
//	while (1)
//	{
//		print_main_menu();
//		int choice = process_choice(0, 7);
//		menu_selection(choice);
//	}
//}