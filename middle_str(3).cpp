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