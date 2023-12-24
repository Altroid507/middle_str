#include <iostream>
#include <string>
#include "middle_str.h"

using namespace std;

long long itc_len(string str) {		//Ñîáñòâåííàÿ ôóíêöèÿ
	long long size;
	size = 0;
	for (int i = 0; str[i] != '\0'; i++) {
		size++;
	}
	return size;
}

string itc_slice_str(string str, int start, int end) {		//Ñîáñòâåííàÿ ôóíêöèÿ
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

unsigned char itc_toLower(unsigned char c) {	//Ñîáñòâåííàÿ ôóíêöèÿ
	if (c >= 65 && c <= 90) return c += 32;
	return c;
}

string itc_reverse_str(string str) {
	string rev;
	for (int i = 0; i < itc_len(str); i++) {
		rev += str[itc_len(str) - i - 1];
	}
	return rev;
}

long long itc_changeNum(long long number, long long step) {
	long long res = 0;
	long long base = 1;
	while (number > 0) {
		int d = number % step;
		res = d * base + res;
		base = base * 10;
		number = number / step;
	}
	return res;
}
