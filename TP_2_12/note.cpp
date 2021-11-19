#include "note.h"

Note::Note()
{
	cout << "Consctructor default Note" << endl;
	fio = "";
	number = "";
	date[0] = 0;
	date[1] = 0;
	date[2] = 0;
}

Note::Note(string _fio, string _number, int _day, int _month, int _year)
{
	cout << "Consctructor parameter Note" << endl;
	fio = _fio;
	number = _number;
	date[0] = _day;
	date[1] = _month;
	date[2] = _year;
}

Note::Note(const Note& _note)
{
	cout << "Consctructor copy Note" << endl;
	this->fio = _note.fio;
	this->number = _note.number;
	this->date[0] - _note.date[0];
	this->date[1] - _note.date[1];
	this->date[2] - _note.date[2];
}

Note::~Note()
{
	cout << "Deconsctructor default Note" << endl;
	fio = "";
	number = "";
	date[0] = 0;
	date[1] = 0;
	date[2] = 0;
}

void Note::set_info()
{
	cout << "������� ��� ��������: " << endl;
	string _fio, _number;
	string str;
	int flag = 1;
	int _day = 0, _month=0, _year=0;
	getline(cin, _fio);
	cout << "������� ���������� ����� ��������, ������� � ���� +7: " << endl;
	while (flag)
	{
		cin >> str;
		if ((str.find_first_not_of("+0123456789", 0) == string::npos) && (str[0] == '+') && (str[1] == '7'))
		{
			_number = str;
			flag = 0;
		}
		else
			cout << "������������ ����. ���������� ��� ���: " << endl;
	}
	cout << "������� ���� ��������: " << endl;
	cout << "������� ��� �������� (�� ����� ���� ������ 2021 � ������ 1931 ��� ������� ����������������� ����� � 90 ���):" << endl;
	flag = 1;
	while (flag)
	{
		cin >> str;
		if (str.find_first_not_of("0123456789", 0) == string::npos)
		{
			_year = stoi(str);
			if (_year < 1931 || _year > 2021)
				cout << "������ �������� ���. ���������� ��� ���: " << endl;
			else
				flag = 0;
		}
		else
			cout << "������������ ����. ���������� ��� ���: " << endl;
	}
	flag = 1;
	cout << "������� ����� ��������:" << endl;
	while (flag)
	{
		cin >> str;
		if (str.find_first_not_of("0123456789", 0) == string::npos)
		{
			_month = stoi(str);
			if (_month < 1 || _month > 12)
				cout << "������ �������� �����. ���������� ��� ���: " << endl;
			else
				flag = 0;
		}
		else
			cout << "������������ ����. ���������� ��� ���: " << endl;
	}
	flag = 1;
	cout << "������� ���� ��������:" << endl;
	while (flag)
	{
		cin >> str;
		if (str.find_first_not_of("0123456789", 0) == string::npos)
		{
			_day = stoi(str);
			if (_day < 1 || _day > 31)
				cout << "������ �������� ����. ���������� ��� ���: " << endl;
			else
				switch (_month)
				{
				case 1:
					flag = 0;
					break;
				case 2:
					if (_day > 29 || ((_day == 29) && (_year % 4 != 0)))
					{
						cout << "������ �������� ����. ���������� ��� ���: " << endl;
						break;
					}
					flag = 0;
					break;
				case 3:
					flag = 0;
					break;
				case 4:
					if (_day > 30)
					{
						cout << "������ �������� ����. ���������� ��� ���: " << endl;
						break;
					}
					flag = 0;
					break;
				case 5:
					flag = 0;
					break;
				case 6:
					if (_day > 30)
					{
						cout << "������ �������� ����. ���������� ��� ���: " << endl;
						break;
					}
					flag = 0;
					break;
				case 7:
					flag = 0;
					break;
				case 8:
					flag = 0;
					break;
				case 9:
					if (_day > 30)
					{
						cout << "������ �������� ����. ���������� ��� ���: " << endl;
						break;
					}
					flag = 0;
					break;
				case 10:
					flag = 0;
					break;
				case 11:
					if (_day > 30)
					{
						cout << "������ �������� ����. ���������� ��� ���: " << endl;
						break;
					}
					flag = 0;
					break;
				case 12:
					flag = 0;
					break;
				}
		}
		else
			cout << "������������ ����. ���������� ��� ���: " << endl;
	}
	this->set_fio(_fio);
	this->set_number(_number);
	this->set_date(_day, _month, _year);
}

void Note::change_info()
{
	cout << "�� ����������� �������� ������ �������. ��������, ��� �� ������ ��������: " << endl;
	cout << "1. ���\n2. ���������� �����\n3. ���� ��������\n0. ��������� �����." << endl;
	string _fio, _number;
	string str;
	int birth[3];
	int flag = 1;
	int choice;
	while (flag)
	{
		cin >> str;
		if (str.find_first_not_of("0123456789", 0) == string::npos)
		{
			choice = stoi(str);
			if (choice < 0 || choice > 3)
				cout << "������������ ����. ���������� ��� ���: " << endl;
			else
				flag = 0;
		}
		else
			cout << "������������ ����. ���������� ��� ���: " << endl;
	}
	cin.ignore(32767, '\n');
	switch (choice)
	{
	case 1:
		cout << "������� ���: " << endl;
		getline(cin, _fio);
		this->set_fio(_fio);
		break;
	case 2:
		cout << "������� ���������� ����� ��������, ������� � ���� +7: " << endl;
		while (flag)
		{
			cin >> str;
			if ((str.find_first_not_of("+0123456789", 0) == string::npos) && (str[0] == '+') && (str[1] == '7'))
			{
				_number = str;
				flag = 0;
			}
			else
				cout << "������������ ����. ���������� ��� ���: " << endl;
		}
		this->set_number(_number);
		break;
	case 3:
		flag = 1;
		cout << "������� ��� �������� (�� ����� ���� ������ 2021 � ������ 1931 ��� ������� ����������������� ����� � 90 ���):" << endl;
		while (flag)
		{
			cin >> str;
			if (str.find_first_not_of("0123456789", 0) == string::npos)
			{
				birth[2] = stoi(str);
				if (birth[2] < 1931 || birth[2] > 2021)
					cout << "������ �������� ���. ���������� ��� ���: " << endl;
				else
					flag = 0;
			}
			else
				cout << "������������ ����. ���������� ��� ���: " << endl;
		}
		flag = 1;
		cout << "������� ����� ��������:" << endl;
		while (flag)
		{
			cin >> str;
			if (str.find_first_not_of("0123456789", 0) == string::npos)
			{
				birth[1] = stoi(str);
				if (birth[1] < 1 || birth[1] > 12)
					cout << "������ �������� �����. ���������� ��� ���: " << endl;
				else
					flag = 0;
			}
			else
				cout << "������������ ����. ���������� ��� ���: " << endl;
		}
		flag = 1;
		cout << "������� ���� ��������:" << endl;
		while (flag)
		{
			cin >> str;
			if (str.find_first_not_of("0123456789", 0) == string::npos)
			{
				birth[0] = stoi(str);
				if (birth[0] < 1 || birth[0] > 31)
					cout << "������ �������� ����. ���������� ��� ���: " << endl;
				else
					switch (birth[1])
					{
					case 1:
						flag = 0;
						break;
					case 2:
						if (birth[0] > 29 || ((birth[0] == 29) && (birth[2] % 4 != 0)))
						{
							cout << "������ �������� ����. ���������� ��� ���: " << endl;
							break;
						}
						flag = 0;
						break;
					case 3:
						flag = 0;
						break;
					case 4:
						if (birth[0] > 30)
						{
							cout << "������ �������� ����. ���������� ��� ���: " << endl;
							break;
						}
						flag = 0;
						break;
					case 5:
						flag = 0;
						break;
					case 6:
						if (birth[0] > 30)
						{
							cout << "������ �������� ����. ���������� ��� ���: " << endl;
							break;
						}
						flag = 0;
						break;
					case 7:
						flag = 0;
						break;
					case 8:
						flag = 0;
						break;
					case 9:
						if (birth[0] > 30)
						{
							cout << "������ �������� ����. ���������� ��� ���: " << endl;
							break;
						}
						flag = 0;
						break;
					case 10:
						flag = 0;
						break;
					case 11:
						if (birth[0] > 30)
						{
							cout << "������ �������� ����. ���������� ��� ���: " << endl;
							break;
						}
						flag = 0;
						break;
					case 12:
						flag = 0;
						break;
					}
			}
			else
				cout << "������������ ����. ���������� ��� ���: " << endl;
		}
		this->set_date(birth[0], birth[1], birth[2]);
		break;
	case 0:
		break;
	}
}

void Note::set_fio(string _fio)
{
	this->fio = _fio;
}

void Note::set_number(string _number)
{
	this->number = _number;
}

void Note::set_date(int _day, int _month, int _year)
{
	this->date[0] = _day;
	this->date[1] = _month;
	this->date[2] = _year;
}

void Note::print_info()
{
	
	cout << "�������: " << endl;
	cout << "���: " << this->get_fio() << endl;
	cout << "���������� �����: " << this->get_number() << endl;
	int date[3]; for (int i = 0; i < 3; i++)  date[i] = this->get_date(i);
	cout << "���� ��������: " << date[0] << "." << date[1] << "." << date[2] << endl;
}

string Note::get_fio() { return this->fio; }
string Note::get_number() { return this->number; }
int Note::get_date(int index) { return date[index]; }

void Note::file_load()
{
	ifstream fin;
	fin.exceptions(std::ios::badbit | std::ios::failbit | std::ios::eofbit);
	string load_name;
	cout << "������� �������� �����, � ������� �������� ���������� �� ��������." << endl;
	cout << "��������� ��������� �� �� ������ �� ��������� ��������: save_*���*.txt. " << endl;
	cout << "��� ������ �����, ������� back: " << endl;
	while (!fin.is_open())
	{
		cin.ignore();
		getline(cin, load_name);
		try
		{
			if (load_name == "back")
			{
				break;
			}
			fin.open(load_name);
		}
		catch (const std::ios_base::failure& e)
		{
			std::cerr << "can not open file\nwhat: " << e.what() << "\n";
		}
	}
	if (load_name != "back")
	{
		int birth[3] = {0, 0, 0};
		string _fio = "", _number= "", str;
		getline(fin, str);
		if ((str.find_first_not_of("���������������������������������������������������������������� ", 0) == string::npos))
		{
			cout << "��� ������� ���������." << endl;
			_fio = str;
		}
		else
			cout << "��� ������� �����������." << endl;
		getline(fin, str);
		if ((str.find_first_not_of("+1234567890", 0) == string::npos) && (str[0] == '+') && (str[1] == '7'))
		{
			cout << "����� ������ ���������." << endl;
			_number = str;
		}
		else
			cout << "����� ������ �����������." << endl;
		getline(fin, str);
		if ((str.find_first_not_of("1234567890", 0) == string::npos))
		{
			birth[2] = stoi(str);
			if (birth[2] < 1931 || birth[2] > 2021)
			{
				cout << "������ �������� ���." << endl;
				birth[2] = 0;
			}
			else
				cout << "������ ������ ���." << endl;
		}
		else
			cout << "������ �������� ���." << endl;
		getline(fin, str);
		if ((str.find_first_not_of("1234567890", 0) == string::npos))
		{
			birth[1] = stoi(str);
			if (birth[1] < 1 || birth[1] > 12)
			{
				cout << "������ �������� �����." << endl;
				birth[1] = 0;
			}
			else
				cout << "������ ������ �����." << endl;
		}
		else
			cout << "������ �������� �����." << endl;
		getline(fin, str);
		if (str.find_first_not_of("0123456789", 0) == string::npos)
		{
			birth[0] = stoi(str);
			if (birth[0] < 1 || birth[0] > 31)
				cout << "������ �������� ����." << endl;
			else
				switch (birth[2])
				{
				case 1:
					cout << "������ ������ ����." << endl;
					break;
				case 2:
					if (birth[0] > 29 || ((birth[0] == 29) && (birth[2] % 4 != 0)))
					{
						cout << "������ �������� ����." << endl;
						break;
					}
					cout << "������ ������ ����." << endl;
					break;
				case 3:
					cout << "������ ������ ����." << endl;
					break;
				case 4:
					if (birth[0] > 30)
					{
						cout << "������ �������� ����." << endl;
						break;
					}
					cout << "������ ������ ����." << endl;
					break;
				case 5:
					cout << "������ ������ ����." << endl;
					break;
				case 6:
					if (birth[0] > 30)
					{
						cout << "������ �������� ����." << endl;
						break;
					}
					cout << "������ ������ ����." << endl;
					break;
				case 7:
					cout << "������ ������ ����." << endl;
					break;
				case 8:
					cout << "������ ������ ����." << endl;
					break;
				case 9:
					if (birth[0] > 30)
					{
						cout << "������ �������� ����." << endl;
						break;
					}
					cout << "������ ������ ����." << endl;
					break;
				case 10:
					cout << "������ ������ ����." << endl;
					break;
				case 11:
					if (birth[0] > 30)
					{
						cout << "������ �������� ����." << endl;
						break;
					}
					cout << "������ ������ ����." << endl;
					break;
				case 12:
					cout << "������ ������ ����." << endl;
					break;
				case 0:
					cout << "������ �������� ����." << endl;
					break;
				}
		}
		else
			cout << "������ �������� �����." << endl;
		fin.close();
		if (_fio != "" && _number != "" && birth[0] != 0 && birth[1] != 0 && birth[2] != 0)
		{
			this->set_date(birth[0], birth[1], birth[2]);
			this->set_fio(_fio);
			this->set_number(_number);
		}
		else
		{
			cout << "������ ����� " << load_name << " ���������. ��������� �� ������������ �������." << endl;
			birth[0] = 0;
			birth[1] = 0;
			birth[2] = 0;
			_fio = "";
			_number = "";
			this->set_date(birth[0], birth[1], birth[2]);
			this->set_fio(_fio);
			this->set_number(_number);
		}
			
	}
}

void Note::file_save()
{
	ofstream fout;
	string save_name = "save";
	save_name = save_name + "_" + this->get_fio() + ".txt";
	fout.open(save_name);
	int date[3]; for (int i = 0; i < 3; i++)  date[i] = this->get_date(i);
	fout << this->get_fio() << endl;
	fout << this->get_number() << endl;
	fout << date[2] << endl;
	fout << date[1] << endl;
	fout << date[0] << endl;
	fout.close();
}