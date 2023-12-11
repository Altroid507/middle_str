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

bool itc_isDigit(unsigned char c) {
	if (c >= '0' && c <= '9') return true;
	return false;
}

unsigned char itc_toUpper(unsigned char c) {
	if (c >= 97 && c <= 122) return c -= 32;
	return c;
}

unsigned char itc_toLower(unsigned char c) {	//Собственная функция
	if (c >= 65 && c <= 90) return c += 32;
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

string itc_maxCharWord(string str) {
	int space1 = 0, space2;
	string maxim = "";
	str = " " + str + " ";
	for (int i = 1; i <= itc_len(str); i++) {
		if (str[i] == ' ') {
			space2 = i;
			if (itc_len(maxim) < itc_len(itc_slice_str(str, space1 + 2, space2))) {
				maxim = itc_slice_str(str, space1 + 2, space2);
				for (int j = space1; j <= space2; j++) {
					if ((str[j] >= '!' && str[j] <= '@') || (str[j] >= '[' && str[j] <= '`') || (str[j] >= '{' && str[j] <= '~')) {
						maxim = "";
					}
				}
			}
			space1 = i;
		}
	}
	if (maxim == "") maxim = "error";
	return maxim;
}

int main() {
	cout << itc_maxCharWord("one two four") << endl;
	cout << itc_maxCharWord("one four nine") << endl;
	cout << itc_maxCharWord("one, four, nine.") << endl;
	cout << itc_maxCharWord("onefournine") << endl;
}
