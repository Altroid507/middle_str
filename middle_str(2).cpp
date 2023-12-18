#include <iostream>
#include <string>
#include "middle_str.h"

using namespace std;

string itc_maxCharWord(string str) {
	int space1 = 0, space2;
	string maxim = "";
	str = itc_rmFreeSpace(str);
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

char itc_sameChar(string str) {
	char res;
	for (int i = 0; i < itc_len(str); i++) {
		if (!(str[i] >= '!' && str[i] <= '@') || !(str[i] >= '[' && str[i] <= '`') || !(str[i] >= '{' && str[i] <= '~')) {
			for (int j = i + 1; j < itc_len(str); j++) {
				if (str[i] == str[j]) {
					res = str[i];
				}
			}
		}
	}
	return res;
}

bool itc_isFirstInSecond(string s1, string s2) {
	bool ch = false;
	if (itc_len(s1) > itc_len(s2)) return false;
	for (int i = 0; i < itc_len(s2); i++) {
		for (int j = 0; j < itc_len(s1); j++) {
			if (s2[i] == s1[j]) {
				ch = true;
			}
			else {
				ch = false;
			}
		}
		if (ch) return true;
	}
	return false;
}

string itc_Cezar(string str, int k) {
	for (int i = 0; i < itc_len(str); i++) {
		if (str[i] >= 'a' && str[i] <= 'z') {
			str[i] += k;
			if (str[i] > 'z') {
				int a = str[i] - 'z';
				str[i] = 'a' - 1 + a;
			}
			if (str[i] < 'a') {
				int a = 'a' - str[i];
				str[i] = 'z' + 1 - a;
			}
		}
		if (str[i] >= 'A' && str[i] <= 'Z') {
			str[i] += k;
			if (str[i] > 'Z') {
				int a = str[i] - 'Z';
				str[i] = 'A' - 1 + a;
			}
			if (str[i] < 'A') {
				int a = 'A' - str[i];
				str[i] = 'Z' + 1 - a;
			}
		}
	}
	return str;
}

string itc_rmFreeSpace(string str) {
	bool spch = false;
	string res = "";
	for (int i = 0; i < itc_len(str); i++) {
		if (str[i] != ' ') {
			res += str[i];
			spch = false;
		}
		else {
			if (spch == false) {
				res += str[i];
				spch = true;
			}
		}
	}
	return res;
}
