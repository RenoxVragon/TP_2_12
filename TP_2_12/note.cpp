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
	cout << "Введите ФИО абонента: " << endl;
	string _fio, _number;
	string str;
	int flag = 1;
	int _day = 0, _month=0, _year=0;
	getline(cin, _fio);
	cout << "Введите контактный номер абонента, начиная с кода +7: " << endl;
	while (flag)
	{
		cin >> str;
		if ((str.find_first_not_of("+0123456789", 0) == string::npos) && (str[0] == '+') && (str[1] == '7'))
		{
			_number = str;
			flag = 0;
		}
		else
			cout << "Некорректный ввод. Попробуйте еще раз: " << endl;
	}
	cout << "Введите дату рождения: " << endl;
	cout << "Введите год рождения (не может быть больше 2021 и меньше 1931 при средней продолжительности жизни в 90 лет):" << endl;
	flag = 1;
	while (flag)
	{
		cin >> str;
		if (str.find_first_not_of("0123456789", 0) == string::npos)
		{
			_year = stoi(str);
			if (_year < 1931 || _year > 2021)
				cout << "Введен неверный год. Попробуйте еще раз: " << endl;
			else
				flag = 0;
		}
		else
			cout << "Некорректный ввод. Попробуйте еще раз: " << endl;
	}
	flag = 1;
	cout << "Введите месяц рождения:" << endl;
	while (flag)
	{
		cin >> str;
		if (str.find_first_not_of("0123456789", 0) == string::npos)
		{
			_month = stoi(str);
			if (_month < 1 || _month > 12)
				cout << "Введен неверный месяц. Попробуйте еще раз: " << endl;
			else
				flag = 0;
		}
		else
			cout << "Некорректный ввод. Попробуйте еще раз: " << endl;
	}
	flag = 1;
	cout << "Введите день рождения:" << endl;
	while (flag)
	{
		cin >> str;
		if (str.find_first_not_of("0123456789", 0) == string::npos)
		{
			_day = stoi(str);
			if (_day < 0 || _day > 31)
				cout << "Введен неверный день. Попробуйте еще раз: " << endl;
			else
				switch (_month)
				{
				case 1:
					flag = 0;
					break;
				case 2:
					if (_day > 29 || ((_day == 29) && (_year % 4 != 0)))
					{
						cout << "Введен неверный день. Попробуйте еще раз: " << endl;
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
						cout << "Введен неверный день. Попробуйте еще раз: " << endl;
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
						cout << "Введен неверный день. Попробуйте еще раз: " << endl;
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
						cout << "Введен неверный день. Попробуйте еще раз: " << endl;
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
						cout << "Введен неверный день. Попробуйте еще раз: " << endl;
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
			cout << "Некорректный ввод. Попробуйте еще раз: " << endl;
	}
	this->set_fio(_fio);
	this->set_number(_number);
	this->set_date(_day, _month, _year);
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
	
	cout << "Абонент: " << endl;
	cout << "ФИО: " << this->get_fio() << endl;
	cout << "Контактный номер: " << this->get_number() << endl;
	int date[3]; for (int i = 0; i < 3; i++)  date[i] = this->get_date(i);
	cout << "Дата рождения: " << date[0] << "." << date[1] << "." << date[2] << endl;
}

string Note::get_fio() { return this->fio; }
string Note::get_number() { return this->number; }
int Note::get_date(int index) { return date[index]; }