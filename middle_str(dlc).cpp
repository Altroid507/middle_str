#include <iostream>
#include <string>
#include "middle_str.h"

using namespace std;

long long itc_len(string str) {		//Собственная функция
	long long size;
	size = 0;
	for (int i = 0; str[i] != '\0'; i++) {
		size++;
	}
	return size;
}

string itc_slice_str(string str, int start, int end) {		//Собственная функция
	string res;
	if (start > end) return str;
	if (end < itc_len(str)) {
		for (int i = (start - 1); i <= (end - 1); i++) {
			res += str[i];
		}
	}
	else {
		for (int i = (start - 1); i <= itc_len(str); i++) {
			res += str[i];
		}
	}
	return res;
}

unsigned char itc_toLower(unsigned char c) {	//Собственная функция
	if (c >= 65 && c <= 90) return c += 32;
	return c;
}