#include <iostream>
#include <string>
#include "middle_str.h"

using namespace std;

bool itc_isDigit(unsigned char c) {
	if (c >= '0' && c <= '9') return true;
	return false;
}

unsigned char itc_toUpper(unsigned char c) {
	if (c >= 97 && c <= 122) return c -= 32;
	return c;
}

unsigned char itc_changeCase(unsigned char c) {
	if (c >= 97 && c <= 122) return itc_toUpper(c);
	if (c >= 65 && c <= 90) return itc_toLower(c);
	return c;
}

bool itc_compare(string s1, string s2) {
	int check = 0;
	if (itc_len(s1) != itc_len(s2)) return false;
	for (int i = 0; i <= itc_len(s1); i++) {
		if (s1[i] != s2[i]) check = 1;
	}
	if (check == 0) return true;
	return false;
}

int itc_countWords(string str) {
	int cntr = 0;
	int j = 0;
	str += " ";
	for (int i = 0; i < itc_len(str); i++) {
		if (str[i] == ' ') {
			cntr++;
			for (; j <= i; j++) {
				if ((str[j] >= '!' && str[j] <= '@') || (str[j] >= '[' && str[j] <= '`') || (str[j] >= '{' && str[j] <= '~')) {
					cntr--;
				}
			}
		}
	}
	return cntr;
}