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
	for (int i = 0; i < itc_len(str); i++) {
		if (!(str[i] >= '!' && str[i] <= '@') || !(str[i] >= '[' && str[i] <= '`') || !(str[i] >= '{' && str[i] <= '~')) {
			for (int j = i+1; j < itc_len(str); j++) {
				if (str[i] == str[j]) {
					return str[i];
				}
			}
		}
	}
}

bool itc_isFirstInSecond(string s1, string s2) {
	bool ch = false;
	int check = 0;
	if (itc_len(s1) > itc_len(s2)) return false;
	if (s1 == "") return true;
	for (int i = 0; i < itc_len(s2) - itc_len(s1)+1; i++) {
		for (int j = 0; j < itc_len(s1); j++) {
			if (s2[i+j] == s1[j]) {
				ch = true;
				check++;
			}
			else {
				ch = false;
				check = 0;
			}
		}
		if (ch && check == itc_len(s1)) return true;
	}
	return false;
}

string itc_Cezar(string str, int k) {
	for (int i = 0; i < itc_len(str); i++) {
		if (str[i] >= 'a' && str[i] <= 'z') {
			if (str[i] + k > 'z') {
				int a = (str[i] + k) % 'z';
				str[i] = 'a' + a - 1;
			}
			else if (str[i] + k < 'a') {
				int a = 'a' % (str[i] + k);
				str[i] = 'z' - a + 1;
			}
			else str[i] = str[i] + k;

		}
		if (str[i] >= 'A' && str[i] <= 'Z') {
			if (str[i] + k > 'z') {
				int a = (str[i] + k) % 'Z';
				str[i] = 'A' + a - 1;
			}
			else if (str[i] + k < 'A') {
				int a = 'A' % (str[i] + k);
				str[i] = 'Z' - a + 1;
			}
			else str[i] = str[i] + k;
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
