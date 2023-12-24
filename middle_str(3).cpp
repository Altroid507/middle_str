#include <iostream>
#include <string>
#include "middle_str.h"

using namespace std;

bool itc_isIp(string str) {
	int kolvo = 0, number = 0;
	for (int i = 0; i < itc_len(str); i++) {
		if (str[i] == '.') {
			if (number < 0 || number > 255) {
				return false;
			}
			number = 0;
			kolvo++;
		}
		else if (str[i] >= '0' && str[i] <= '9') {
			number = number * 10 + (str[i] - '0');
		}
		else return false;
	}
	if (number < 0 || number > 255 || kolvo > 3) return false;
	return true;
}

string itc_DecToBin(string str) {
	string res = "", res1 = "";
	bool chk = false;
	long long number = 0;
	for (int i = 0; i < itc_len(str); i++) {
		if (!itc_isDigit(str[i])) {
			res += str[i];
		}
		else if (itc_isDigit(str[i])) {
			if (str[i] == '0') {
				res += '0';
			}
			int j = i;
			while (itc_isDigit(str[j])) {
				number = number * 10 + (str[j] - '0');
				j++;
			}
			i = j - 1;
			number = itc_changeNum(number, 2);
			while (number != 0) {
				res1 += (number % 10) + '0';
				number /= 10;
			}
			res += itc_reverse_str(res1);
			res1 = "";
		}
	}
	return res;
}
