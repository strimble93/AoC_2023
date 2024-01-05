#include "pch.h"
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <tuple>

using namespace std;

constexpr auto filename = "day3.txt";

void day3();
bool issymbol(string str, int i);
int validnumbers(string str0, string str1, string str2);
int gears(string str0, string str1, string str2);
int completenum(string str, int i);
bool isstar(string str, int i);


void day3() {
	int output = 0;
	fstream day_file;
	day_file.open(filename, ios::in);
	if (day_file.is_open()) {
		string tp0, tp1, tp2;
		while (getline(day_file, tp2)) {
			output = output + gears(tp0, tp1, tp2);
			tp0 = tp1;
			tp1 = tp2;
		}
		tp2.clear();
		output = output + gears(tp0, tp1, tp2);
		day_file.close();
	}
	cout << "The engine part is: " << output << '\n';
}

bool issymbol(string str, int i) {
	if (i < str.length() && str[i] != '.' && !isdigit(str[i])) {
		return true;
	}
	else {
		return false;
	}
}

int validnumbers(string str0, string str1, string str2){
	int output = 0;
	int count = 0;
	int pre = 0;
	int post = 0;

	for (int i = 0; i <= str1.length(); i++) {
		if (i != 0 && isdigit(str1[i]) && isdigit(str1[i-1])) {
			count = count * 10 + str1[i] - '0';

			if (i == str1.length()) {
				post = i;
			}
		}
		else if (isdigit(str1[i])) {
			count = str1[i] - '0';
			if (i == 0) {
				pre = 0;
			}
			else {
				pre = i - 1;
			}

			if (i == str1.length()) {
				post = i;
			}
		}
		else if (i != 0 && isdigit(str1[i-1])) {
			post = i;
		}

		if (post != 0) {
			for (int i = pre; i <= post; i++) {
				if (issymbol(str0, i) || issymbol(str1, i) || issymbol(str2, i)) {
					cout << count << " is valid\n";
					output = output + count;
					i = post + 1;
				}
			}
			post = 0;
		}
	}

	return output;
}

int gears(string str0, string str1, string str2){
	int output = 0;
	int gears = 0;
	int gear[1] = { 0 };
	string gearstr[1];
	for (int i = 0; i < str1.length(); i++) {
		if (isstar(str1, i)) {
			if (isdigit(str0[i - 1])) {
				gear[gears] = i - 1;
				gearstr[gears] = str0;
				gears++;
			}
			if (isdigit(str0[i]) && !isdigit(str0[i - 1]))
			{
				gear[gears] = i - 1;
				gearstr[gears] = str0;
				gears++;
			}
			if (isdigit(str0[i+1]) && !isdigit(str0[i]))
			{
				gear[gears] = i - 1;
				gearstr[gears] = str0;
				gears++;
			}
			if (isdigit(str1[i - 1])) {
				gear[gears] = i - 1;
				gearstr[gears] = str1;
				gears++;
			}
			if (isdigit(str1[i + 1])) {
				gear[gears] = i - 1;
				gearstr[gears] = str1;
				gears++;
			}
			if (isdigit(str2[i - 1])) {
				gear[gears] = i - 1;
				gearstr[gears] = str2;
				gears++;
			}
			if (isdigit(str2[i]) && !isdigit(str2[i - 1]))
			{
				gear[gears] = i - 1;
				gearstr[gears] = str2;
				gears++;
			}
			if (isdigit(str2[i + 1]) && !isdigit(str2[i]))
			{
				gear[gears] = i - 1;
				gearstr[gears] = str2;
				gears++;
			}
			if (gears == 2) {
				gear[0] = completenum(gearstr[0], gear[0]);
				gear[1] = completenum(gearstr[1], gear[1]);
				output = output + (gear[0] * gear[1]);
			}
		}
	}
	return output;
}

int completenum(string str, int i) {
	int output = 0;
	while (i >= 0 && isdigit(str[i])) {
		i--;
	}
	i++;
	while (isdigit(str[i])) {
		output = output * 10 + str[i] - '0';
		i++;
	}
	return output;
}

bool isstar(string str, int i) {
	if (str[i] == '*') {
		return true;
	}
	else {
		return false;
	}
}