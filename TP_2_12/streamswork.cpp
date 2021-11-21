#include "streamswork.h"

string file_load()
{
	ifstream fin;
	fin.exceptions(std::ios::badbit | std::ios::failbit | std::ios::eofbit);
	string load_name;
	string s, str;
	cout << "Введите название файла, в котором хранится текст." << endl;
	while (!fin.is_open())
	{
		cin.ignore(32676, '\n');
		getline(cin, load_name);
		try
		{
			fin.open(load_name, ios_base::in | ios_base::out);
		}
		catch (const std::ios_base::failure& e)
		{
			std::cerr << "can not open file\nwhat: " << e.what() << "\n";
		}
	}
	try
	{
		while (getline(fin, str))
		{
			cout << str << endl;
			s.append(str).append("\n");
		}
	}
	catch(std::ifstream::failure e)
		{
		fin.close();
	}
	return s;
}

string find_dash_sentences(string s)
{
	int dash_start=0, dash_end=0;
	string out;
	bool is_sentence = false;
	bool is_dash_sentence = false;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] != ' ')
		{
			if (s[i] == '-')
				if (is_sentence == true)
					is_dash_sentence = false;
				else
				{
					is_dash_sentence = true;
					dash_start = i;
				}
			if (s[i] == '.' || s[i] == '!' || s[i] == '?' || s[i] == '\n')
				is_sentence = false;
			else
				is_sentence = true;
			if (is_dash_sentence)
			{
				if (s[i] == '.' || s[i] == '!' || s[i] == '?' || s[i] == '\n')
				{
					dash_end = i;
					out.insert(out.length(), s, dash_start, dash_end - dash_start + 1);
					out.append("\n");
					is_dash_sentence = false;
					is_sentence = false;
				}
			}
		}
	}
	return out;
}