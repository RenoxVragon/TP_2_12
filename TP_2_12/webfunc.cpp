#include "webfunc.h"

static size_t get_response_to_string(void* contents, size_t size, size_t nmemb, void* userp)
{
	((string*)userp)->append((char*)contents, size * nmemb);
	return size * nmemb;
}

void web_task(string _number)
{
	string number = _number;
	number.erase(0, 1);
	number.erase(0, 1);
	string url = "https://regionoperator.ru/" + number;
	string str_response;
	CURL* curl;
	CURLcode response;
	curl = curl_easy_init();
	curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, get_response_to_string);
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, &str_response);
	response = curl_easy_perform(curl);
	curl_easy_cleanup(curl);
	ofstream fout;
	string save_name = "html_code.txt";
	fout.open(save_name);
	fout << str_response << endl;
	fout.close();
	ShellExecuteA(NULL, "open", url.c_str(), NULL, NULL, SW_SHOWNORMAL);
}