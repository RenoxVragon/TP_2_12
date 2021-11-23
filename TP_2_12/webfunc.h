#pragma once
#define _CRT_SECURE_NO_WARNINGS 
#define CURL_STATICLIB
#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>
#include <curl/curl.h>
#include <ShellAPI.h>
using namespace std;

static size_t get_response_to_string(void* contents, size_t size, size_t nmemb, void* userp);
void web_task(string _number);