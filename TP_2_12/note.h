#pragma once
#include <iostream>
#include <string>
using namespace std;

class Note
{
private:
	string fio;
	string number;
	int date[3];
public:
	Note();
	Note(string _fio, string _number, int _day, int _month, int _year);
	Note(const Note& _note);
	~Note();
	void print_info();
	void set_info();
	void set_fio(string _fio);
	string get_fio();
	void set_number(string _number);
	string get_number();
	void set_date(int _day, int _month, int _year);
	int get_date(int index);
};